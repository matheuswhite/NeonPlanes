#pragma once

#include "Tool.h"
#include "core.h"

class DataStore : public Tool
{
public:
	DataStore();
	virtual ~DataStore();

	bool isEOF() const;
	bool hasFile(const std::string& filePath);
	void loadReadFile(const std::string& filePath, const Uint8& mode = utility::NORMAL);
	void loadWriteFile(const std::string& filePath, const Uint8& mode = utility::NORMAL);
	void loadAppendFile(const std::string& filePath, const Uint8& mode = utility::NORMAL);
	void closeFile();


	/*
		## -> simboliza o caracter '#' / symbolizes the character '#'
		#| -> simboliza o caracter '|' / symbolizes the character '|'
		#B -> inicio do arquivo / begin of file
		| -> separação de valores / end of value
		#E -> fim do arquivo / end of file

	*/
	template <typename T, typename E>
	std::pair<T, E> getInPair() {
		std::pair < T, E > temp;

		return temp;
	}

	template <typename T, typename E, typename U>
	std::pair<T, std::pair<E, U> > getInTrio() {
		std::pair < T, std::pair<E, U> > temp;



		return temp;
	}
private:
	bool fileEnd;
	bool fileLoad;
	std::fstream stream;
};
