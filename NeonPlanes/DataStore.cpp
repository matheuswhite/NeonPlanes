#include "DataStore.h"

std::fstream DataStore::_stream;

DataStore::DataStore() {
}

DataStore::~DataStore() {
}

bool DataStore::hasFile(const std::string& filePath) {
	_stream.open(filePath.c_str(), std::ios::in);
	if (_stream.is_open()) {
		_stream.close();
		return true;
	}
	return false;
}

std::string DataStore::formatOutput(ScoreData* data) {
	std::string str;
	str.clear();
	/*
	1 000 000 000 000 000
	   T   G   M   K
	*/
	if (data->totalDistance < 1000000000000000 && data->totalDistance >= 1000000000000) {
		double param = data->totalDistance / 1000000000000;
		double unit;
		double decimal = modf(param, &unit);
		
		data->decimalValue = decimal * 10;
		data->unitValue = unit;
		data->modifier = 'T';
	}
	else if (data->totalDistance < 1000000000000 && data->totalDistance >= 1000000000) {
		double param = data->totalDistance / 1000000000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 10;
		data->unitValue = unit;
		data->modifier = 'G';
	}
	else if (data->totalDistance < 1000000000 && data->totalDistance >= 1000000) {
		double param = data->totalDistance / 1000000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 10;
		data->unitValue = unit;
		data->modifier = 'M';
	}
	else if (data->totalDistance < 1000000 && data->totalDistance >= 1000) {
		double param = data->totalDistance / 1000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 10;
		data->unitValue = unit;
		data->modifier = 'K';
	}
	else if(data->totalDistance < 1000) {
		data->decimalValue = 0;
		data->unitValue = data->totalDistance;
		data->modifier = ' ';
	}

	str += data->name;
	str += "$";
	str += std::to_string(data->unitValue);
	str += ".";
	str += std::to_string(data->decimalValue);
	str += data->modifier;
	str += "#";

	return str;
}

ScoreData* DataStore::formatInput(std::string data) {
	std::string str;
	ScoreData* score = new ScoreData();
	unsigned long long int multi = 1;
	bool noName = false;

	for (size_t i = 0; i < data.size(); i++)
	{
		char c = data[i];
		if (c == '$') {
			score->name += str;
			noName = true;
			str.clear();
		}
		else if (c == '.') {
			score->unitValue = std::atoi(str.c_str());
			str.clear();
		}
		else if (noName && (c == 'T' ||
							c == 'G' ||
							c == 'M' ||
							c == 'K' ||
							c == ' ')) {
			score->decimalValue = std::atoi(str.c_str());
			score->modifier = c;
			str.clear();
		}
		else {
			str += c;
		}
	}

	str.clear();

	switch (score->modifier)
	{
	case 'T': multi = 1000000000000;
		break;
	case 'G': multi = 1000000000;
		break;
	case 'M': multi = 1000000;
		break;
	case 'K': multi = 1000;
		break;
	default:
		break;
	}

	score->totalDistance = (score->unitValue + (score->decimalValue / 10)) * multi;

	return score;
}

std::vector<ScoreData*> DataStore::ReadFile(const std::string& filePath) {
	if (hasFile(filePath)) {
		_stream.open(filePath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

		if (_stream.is_open()) {
			std::vector<ScoreData*> vectorOutput;
			char c;
			std::string str;

			_stream.seekg(0, std::ios::beg);
			while (_stream.get(c)) {
				if (c != '#') str += c;
				else {
					vectorOutput.push_back(formatInput(str));
					str.clear();
				}
			}
			
			_stream.close();
			
			return vectorOutput;
		}
		else {
			std::cerr << "Error - Cannot read [" << filePath << "] " << std::endl;
			throw std::exception("Error Read");
		}
	}
	else {
		std::cerr << "Error - File [" << filePath << "] does not exist " << std::endl;
		throw std::exception("Nonexistent File");
	}
}

void DataStore::WriteFile(const std::string& filePath, std::vector<ScoreData*> data) {
	_stream.open(filePath.c_str(), std::ios::out | std::ios::binary);
	if (_stream.is_open()) {
		for each (auto score in data)
		{
			_stream << formatOutput(score);
		}

		_stream.close();
	}
	else {
		std::cerr << "Error - Cannot write [" << filePath << "]" << std::endl;
	}
}
