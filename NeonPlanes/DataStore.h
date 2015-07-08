#pragma once

#include "core.h"

struct ScoreData
{
	std::string name;
	unsigned long long int totalDistance;
	char modifier;
	int unitValue;
	int decimalValue;

	ScoreData() { }
	ScoreData(std::string name, unsigned long long int totalDistance) : name(name), totalDistance(totalDistance) { }
};

class DataStore
{
public:
	DataStore();
	virtual ~DataStore();
	
	static bool hasFile(const std::string& filePath);
	static std::string formatOutput(ScoreData* data);
	static ScoreData* formatInput(std::string data);

	static std::vector<ScoreData*> ReadFile(const std::string& filePath);
	static void WriteFile(const std::string& filePath, std::vector<ScoreData*> data);


	/*
		# - divisor de ScoreData
		Formato:
		Nome1$Distancia1#Nome2$Distancia2#Nome3$Distancia3#
		     ^          ^
			 |          |
		 divisão      divisão pontuação
	  nome-distancia
	*/
	
private:
	static std::fstream _stream;
};
