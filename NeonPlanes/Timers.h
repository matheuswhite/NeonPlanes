#pragma once

#include "core.h"

class SlaveTimer;

class MasterTimer
{
public:
	MasterTimer();
	virtual ~MasterTimer();

	static void pause();
	static void resume();
	static void updateSlaves(Uint32 elapsedTime);

	static void registerSlaveTimer(SlaveTimer* timer);
	static void removeSlaveTimer(SlaveTimer* timer);

private:
	static std::vector<SlaveTimer*> slaves;
};

class SlaveTimer
{
public:
	SlaveTimer(const Uint32 finalTime) : finalTime(finalTime) { MasterTimer::registerSlaveTimer(this); this->duration = 0; this->paused = false; }

	virtual ~SlaveTimer() { MasterTimer::removeSlaveTimer(this); }

	Uint32 getDuration() const { return this->duration; }
	bool isPaused() const { return this->paused; }

	bool isFinish() const { return duration >= finalTime; }
	void update(Uint32 elapsedTime) { this->duration += elapsedTime; }
	void pause() { this->paused = true; }
	void resume() { this->paused = false; }
	void loop() { this->duration = 0; this->paused = false; }

protected:
	Uint32 duration;
	const Uint32 finalTime;
	bool paused;
};
