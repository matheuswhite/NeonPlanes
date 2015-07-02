#include "DataStore.h"

DataStore::DataStore() {
	this->mode = DEFAULT;
}

DataStore::~DataStore() {
	this->closeFile();
	this->mode = DEFAULT;
}

bool DataStore::hasFile(const std::string& filePath) {
	this->stream.open(filePath.c_str(), std::ios::in);
	if (this->stream.is_open()) {
		this->stream.close();
		return true;
	}
	return false;
}

void DataStore::loadFile(const std::string& filePath, const Uint8& mode) {
	if (!this->hasFile(filePath)) {
		std::cerr << "Error - Cannot read [" << filePath << "]" << std::endl;
	}
	else {
		if (mode == utility::streamMode::READ) {
			this->stream.open(filePath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
			this->mode = mode;
		}
		else if (mode == utility::streamMode::WRITE) {
			this->stream.open(filePath.c_str(), std::ios::out | std::ios::binary);
			this->mode = mode;
		}
	}
}

std::string DataStore::formatOutput(ScoreData* data, bool last) {
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

		data->decimalValue = decimal * 1000000000000;
		data->unitValue = unit;
		data->modifier = 'T';
	}
	else if (data->totalDistance < 1000000000000 && data->totalDistance >= 1000000000) {
		double param = data->totalDistance / 1000000000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 1000000000;
		data->unitValue = unit;
		data->modifier = 'G';
	}
	else if (data->totalDistance < 1000000000 && data->totalDistance >= 1000000) {
		double param = data->totalDistance / 1000000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 1000000;
		data->unitValue = unit;
		data->modifier = 'M';
	}
	else if (data->totalDistance < 1000000 && data->totalDistance >= 1000) {
		double param = data->totalDistance / 1000;
		double unit;
		double decimal = modf(param, &unit);

		data->decimalValue = decimal * 1000;
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
	str += data->unitValue;
	str += ".";
	str += data->decimalValue;
	str += data->modifier;
	if (!last) str += "#";

	return str;
}

ScoreData* DataStore::formatInput(std::string data) {
	std::string str;
	ScoreData* score = new ScoreData();
	bool name = true;

	for (size_t i = 0; i < data.size(); i++)
	{
		char c = data[i];
		if (name) {
			if (c == '$') {
				score->name += str;
				name = false;
			}
			else str += c;
		}
		else {
			if (c == '.') score->unitValue = std::atoi(str.c_str());
			else if (c == 'T' ||
				c == 'G' ||
				c == 'M' ||
				c == 'K' ||
				c == ' ') {
				score->decimalValue = std::atoi(str.c_str());
				score->modifier = c;
			}
			else str += c;
		}
	}

	str.clear();

	return score;
}

std::vector<ScoreData*> DataStore::ReadFile(const std::string& filePath) {
	if (this->hasFile(filePath) && this->mode == utility::streamMode::READ) {
		std::vector<ScoreData*> vectorOutput;
		char c;
		std::string str;

		this->stream.seekg(0, std::ios::beg);
		while (this->stream.get(c)) {
			if (c != '#') str += c;
			else {
				vectorOutput.push_back(this->formatInput(str));
				str.clear();
			}
		}

		this->closeFile();
	}
	else {
		std::cerr << "Error - Cannot read [" << filePath << "]" << std::endl;
	}
}

void DataStore::WriteFile(const std::string& filePath, std::vector<ScoreData*> data) {
	if (this->mode == utility::streamMode::WRITE) {
		bool last;
		for each (auto score in data)
		{
			if (data.back() == score) last = true;
			else last = false;

			auto str = this->formatOutput(score, last);
			this->stream << str;
		}

		this->closeFile();
	}
	else {
		std::cerr << "Error - Cannot read [" << filePath << "]" << std::endl;
	}
}

void DataStore::closeFile() {
	if (this->mode != DEFAULT)
		this->stream.close();
	this->mode = DEFAULT;
}