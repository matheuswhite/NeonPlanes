#include "RedEnemy_AI.h"

RedEnemy_AI::RedEnemy_AI(GameObject* enemy, std::string name) : Base_AI(enemy, name)
{
	this->createTimers();
	this->initFSM();
}

RedEnemy_AI::~RedEnemy_AI()
{
}

void RedEnemy_AI::initFSM() {
	this->fsm = new FSM();

	//add states
	this->fsm->addState(new State(States::MIN_PATROL, true));
	this->fsm->addState(new State(States::LIGHT_WALL, false));
	this->fsm->addState(new State(States::MAX_PATROL, false));
	this->fsm->addState(new State(States::GO_DOWN, false));
	this->fsm->addState(new State(States::DASH_AND_LIGHT_WALL, false));
	

	//add transitions
	this->fsm->addTransition(this->fsm->getState(States::MIN_PATROL), this->fsm->getState(States::LIGHT_WALL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::A, [](RedEnemy_AI& ai)
	{
		ai.getTimer("MinPatrol")->loop();
		ai.getTimer("MinPatrol")->pause();

		ai.getTimer("LightWall")->loop();
		ai.enemy->getBehavior("LightWallBehavior")->setActive(true);
	}));
	this->fsm->addTransition(this->fsm->getState(States::LIGHT_WALL), this->fsm->getState(States::MAX_PATROL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::A, [](RedEnemy_AI& ai)
	{
		ai.getTimer("LightWall")->loop();
		ai.getTimer("LightWall")->pause();

		ai.enemy->getBehavior("LightWallBehavior")->setActive(false);

		ai.getTimer("MaxPatrol")->loop();
	}));
	this->fsm->addTransition(this->fsm->getState(States::MAX_PATROL), this->fsm->getState(States::GO_DOWN), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::A, [](RedEnemy_AI& ai)
	{
		ai.getTimer("MaxPatrol")->loop();
		ai.getTimer("MaxPatrol")->pause();

		ai.enemy->getBehavior("PatrolBehavior")->setActive(false);
		ai.enemy->getBehavior("GoDownBehavior")->setActive(true);
	}));
	this->fsm->addTransition(this->fsm->getState(States::GO_DOWN), this->fsm->getState(States::MIN_PATROL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::A, [](RedEnemy_AI& ai)
	{
		ai.enemy->getBehavior("PatrolBehavior")->setActive(true);
		ai.getTimer("MinPatrol")->loop();
	}));
	this->fsm->addTransition(this->fsm->getState(States::DASH_AND_LIGHT_WALL), this->fsm->getState(States::MAX_PATROL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::A, [](RedEnemy_AI& ai)
	{
		ai.getTimer("LightWall")->loop();
		ai.getTimer("LightWall")->pause();

		ai.enemy->getBehavior("LightWallBehavior")->setActive(false);

		ai.enemy->getBehavior("PatrolBehavior")->setActive(true);
		ai.getTimer("MaxPatrol")->loop();
		
	}));
	this->fsm->addTransition(this->fsm->getState(States::MIN_PATROL), this->fsm->getState(States::MIN_PATROL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::B, [](RedEnemy_AI& ai)
	{
		ai.getTimer("MinPatrol")->loop();
	}));
	this->fsm->addTransition(this->fsm->getState(States::MAX_PATROL), this->fsm->getState(States::MIN_PATROL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::B, [](RedEnemy_AI& ai)
	{
		ai.getTimer("MaxPatrol")->loop();
		ai.getTimer("MaxPatrol")->pause();

		ai.getTimer("MinPatrol")->loop();
	}));
	this->fsm->addTransition(this->fsm->getState(States::MIN_PATROL), this->fsm->getState(States::DASH_AND_LIGHT_WALL), std::pair<int, std::function<void(RedEnemy_AI&)> >(Transitions::C, [](RedEnemy_AI& ai)
	{
		ai.getTimer("MinPatrol")->loop();
		ai.getTimer("MinPatrol")->pause();

		ai.enemy->getBehavior("PatrolBehavior")->setActive(false);
		ai.enemy->getBehavior("DashBehavior")->setActive(true);
		ai.enemy->getBehavior("LightWallBehavior")->setActive(true);
	}));

	//preenchendo__ a__ fita__
	this->fita__.push(Transitions::A);
	this->fita__.push(Transitions::A);
	this->fita__.push(Transitions::A);
	this->fita__.push(Transitions::A);
	this->fita__.push(Transitions::B);
	this->fita__.push(Transitions::C);
	this->fita__.push(Transitions::A);
	this->fita__.push(Transitions::B);
}

void RedEnemy_AI::createTimers() {
	this->addTimer(new SlaveTimer(1500,"MinPatrol"));
	this->getTimer("MinPatrol")->pause();

	this->addTimer(new SlaveTimer(700, "LightWall"));
	this->getTimer("LightWall")->pause();

	this->addTimer(new SlaveTimer(3000, "MaxPatrol"));
	this->getTimer("MaxPatrol")->pause();
}

void RedEnemy_AI::manageBehaviors() {
	if (!this->enemy->isActive()) {
		this->enemy = nullptr;
		this->active = false;
	}
	else {
		auto front = this->fita__.front();

		if (this->flagInitialize) {
			this->getTimer("MinPatrol")->loop();
			this->flagInitialize = false;
		}

		switch (this->fsm->getCurentState()->getID())
		{
		case States::MIN_PATROL:
			if (this->getTimer("MinPatrol")->isFinish()) {
				this->fita__.pop();
				this->fita__.push(front);
				this->fsm->switchState(front, *this);
			}
			break;
		case States::LIGHT_WALL:
			if (this->getTimer("LightWall")->isFinish()) {
				this->fita__.pop();
				this->fita__.push(front);
				this->fsm->switchState(front, *this);
			}
			break;
		case States::GO_DOWN:
			if (!this->enemy->getBehavior("GoDownBehavior")->isActive()) {
				this->fita__.pop();
				this->fita__.push(front);
				this->fsm->switchState(front, *this);
			}
			break;
		case States::DASH_AND_LIGHT_WALL:
			if (!this->enemy->getBehavior("DashBehavior")->isActive()) {
				this->fita__.pop();
				this->fita__.push(front);
				this->fsm->switchState(front, *this);
			}
			break;
		case States::MAX_PATROL:
			if (this->getTimer("MaxPatrol")->isFinish()) {
				this->fita__.pop();
				this->fita__.push(front);
				this->fsm->switchState(front, *this);
			}
			break;
		default:
			break;
		}
	}
}