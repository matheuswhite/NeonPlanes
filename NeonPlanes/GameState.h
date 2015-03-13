#pragma once

#include "Command.h"
#include "Layer.h"

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {
		for each (auto var in this->layers) {
			delete var;
		}
		layers.clear();
	}
	
	virtual void execute_BTN_Z() = 0;
	virtual void execute_BTN_SPACE() = 0;
	virtual void execute_BTN_ENTER() = 0;
	virtual void execute_LEFT() = 0;
	virtual void execute_RIGHT() = 0;
	virtual void execute_UP() = 0;
	virtual void execute_DOWN() = 0;

	void addLayer(Layer* layer) { this->layers.push_back(layer); }
	std::vector<Layer*> getLayers() const { return this->layers; }
protected:
	std::vector<Layer*> layers;
};
