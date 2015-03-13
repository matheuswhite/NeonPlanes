#include "DataStore.h"

DataStore::DataStore() {
	this->fileEnd = false;
	this->fileLoad = false;
}

DataStore::~DataStore() {
	this->closeFile();
	this->fileEnd = false;
}

bool DataStore::isEOF() const {
	return this->fileEnd;
}

bool DataStore::hasFile(const std::string& filePath) {
	this->stream.open(filePath.c_str(), std::ios::in);
	if (this->stream.is_open()) {
		this->stream.close();
		return true;
	}
	return false;
}

void DataStore::loadReadFile(const std::string& filePath, const Uint8& mode) {
	if (!this->hasFile(filePath)) {
		std::cerr << "Error - Cannot read [" << filePath << "]" << std::endl;
	}
	else {
		switch (mode) 
		{
		case utility::NORMAL:
		case utility::FORCED:
			this->stream.open(filePath.c_str(), std::ios::in);
			break;
		case utility::BINARY:
			this->stream.open(filePath.c_str(), std::ios::in | std::ios::binary);
			break;
		default:
			break;
		}

		this->fileLoad = true;
	}
}

void DataStore::loadWriteFile(const std::string& filePath, const Uint8& mode) {
	switch (mode) 
	{
	case utility::NORMAL:
		if (!this->hasFile(filePath))
			this->stream.open(filePath.c_str(), std::ios::out);
		break;
	case utility::FORCED:
		this->stream.open(filePath.c_str(), std::ios::out);
		break;
	case utility::BINARY:
		this->stream.open(filePath.c_str(), std::ios::out | std::ios::binary);
		break;
	default:
		break;
	}

	this->fileLoad = true;
}

void DataStore::loadAppendFile(const std::string& filePath, const Uint8& mode) {
	if (!this->hasFile(filePath)) {
		std::cerr << "Error - Cannot read [" << filePath << "]" << std::endl;
	}
	else {
		switch (mode) 
		{
		case utility::NORMAL:
		case utility::FORCED:
			this->stream.open(filePath.c_str(), std::ios::out | std::ios::app);
			break;
		case utility::BINARY:
			this->stream.open(filePath.c_str(), std::ios::out | std::ios::app | std::ios::binary);
			break;
		default:
			break;
		}
	}

	this->fileLoad = true;
}

void DataStore::closeFile() {
	if (this->fileLoad)
		this->stream.close();
	this->fileLoad = false;
}