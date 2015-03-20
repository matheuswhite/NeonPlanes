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
		map_layers.clear();
	}
	
	virtual void execute_BTN_Z() = 0;
	virtual void execute_BTN_SPACE() = 0;
	virtual void execute_BTN_ENTER() = 0;
	virtual void execute_LEFT() = 0;
	virtual void execute_RIGHT() = 0;
	virtual void execute_UP() = 0;
	virtual void execute_DOWN() = 0;

	void addLayer(Layer* layer) 
	{ 
		this->layers.push_back(layer); 
		this->map_layers.insert(std::pair<std::string, Layer*>(layer->getName(), layer));
	}
	std::vector<Layer*> getVectorLayers() const { return this->layers; }
	Layer* getLayer(std::string layer) const { return this->map_layers.at(layer); }
protected:
	std::vector<Layer*> layers;
	std::map<std::string, Layer*> map_layers;
};
