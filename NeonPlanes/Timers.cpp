#include "Timers.h"

std::vector<SlaveTimer*> MasterTimer::slaves = {};

MasterTimer::MasterTimer() 
{
}

MasterTimer::~MasterTimer() 
{
}


void MasterTimer::pause() {
	for each (auto slave in slaves) {
		slave->pause();
	}
}

void MasterTimer::resume() {
	for each (auto slave in slaves) {
		slave->resume();
	}
}

void MasterTimer::updateSlaves(Uint32 elapsedTime) {
	for each (auto slave in slaves) {
		if (!slave->isPaused() && !slave->isFinish())
			if (elapsedTime > 0) {
				slave->update(elapsedTime);
			}
	}
}

void MasterTimer::registerSlaveTimer(SlaveTimer* timer) {
	slaves.push_back(timer);
}

void MasterTimer::removeSlaveTimer(SlaveTimer* timer) {
	if (!slaves.empty()) {
		auto it = std::find(slaves.begin(), slaves.end(), timer);
		if (it != slaves.end())
			slaves.erase(it);
	}
}
