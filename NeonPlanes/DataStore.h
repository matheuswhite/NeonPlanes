#pragma once

#include "core.h"

struct ScoreData
{
	std::string name;
	unsigned long long int totalDistance;
	char modifier;
	int unitValue;
	int decimalValue;

	bool operator==(const ScoreData& s) {
		return (this->unitValue == s.unitValue && this->decimalValue == s.decimalValue && this->modifier == this->modifier);
	}

	bool operator!=(const ScoreData& s) {
		return (this->unitValue != s.unitValue && this->decimalValue != s.decimalValue && this->modifier != this->modifier);
	}

	bool operator<(const ScoreData& s) {
		bool out;
		bool out2 = (this->unitValue < s.unitValue && this->decimalValue < s.decimalValue);

		if (this->modifier == 'T') {
			if (s.modifier == 'T') out = true;
			else out = false;
		}
		else if (this->modifier == 'G'){
			if (s.modifier == 'T') out = true;
			else if (s.modifier == 'G') out = true;
			else out = false;
		}
		else if (this->modifier == 'M') {
			if (s.modifier == 'T') out = true;
			else if (s.modifier == 'G') out = true;
			else if (s.modifier == 'M') out = true;
			else out = false;
		}
		else if (this->modifier == 'K') {
			if (s.modifier == 'T') out = true;
			else if (s.modifier == 'G') out = true;
			else if (s.modifier == 'M') out = true;
			else if (s.modifier == 'K') out = true;
			else out = false;
		}
		else if (this->modifier == ' ')
			out = true;

		return out && out2;
	}

	bool operator>(const ScoreData& s) {
		bool out;
		bool out2 = (this->unitValue > s.unitValue && this->decimalValue > s.decimalValue);

		if (this->modifier == 'T')
			out = true;

		else if (this->modifier == 'G') {
			if (s.modifier == 'T') out = false;
			else out = true;
		}
		else if (this->modifier == 'M') {
			if (s.modifier == 'T') out = false;
			else if (s.modifier == 'G') out = false;
			else out = true;
		}
		else if (this->modifier == 'K') {
			if (s.modifier == 'K') out = true;
			else if (s.modifier == ' ') out = true;
			else out = false;
		}
		else if (this->modifier == ' ') {
			if (s.modifier == ' ') out = true;
			else out = false;
		}

		return out && out2;
	}

	bool operator<=(const ScoreData& s) {
		return (this->operator<(s) || this->operator==(s));
	}

	bool operator>=(const ScoreData& s) {
		return (this->operator>(s) || this->operator==(s));
	}
};

class DataStore
{
public:
	DataStore();
	virtual ~DataStore();
	
	bool hasFile(const std::string& filePath);
	void loadFile(const std::string& filePath, const Uint8& mode);
	std::vector<ScoreData*> ReadFile(const std::string& filePath);
	void WriteFile(const std::string& filePath, std::vector<ScoreData*> data);

	/*
		# - divisor de ScoreData
		Formato:
		Nome1$Distancia1#Nome2$Distancia2#Nome3$Distancia3
		     ^          ^
			 |          |
		 divisão      divisão pontuação
	  nome-distancia
	*/
	
private:
	void closeFile();
	std::string formatOutput(ScoreData* data, bool last);
	ScoreData* formatInput(std::string data);

	int mode;
	std::fstream stream;
};
