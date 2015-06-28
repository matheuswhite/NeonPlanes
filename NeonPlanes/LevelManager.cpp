#include "LevelManager.h"

LevelManager::LevelManager(std::map<std::string, Layer*>* mapLayers) : mapLayers(mapLayers)
{
	this->enemiesDestoyed = 0;
	this->maxEnemies_perLevel = 2;
	this->enemies_InGame = 0;
	this->increaseAI_values = true;
	this->delayEnemyDeploy = 0;

	//create elements of HUD
	this->distance_HUD = new Distance_HUD("Distance_HUD", 1000, 100);
	this->mapLayers->at("HUD")->addGameObject(this->distance_HUD);

	this->level_HUD = new Level_HUD("Level_HUD");
	this->mapLayers->at("HUD")->addGameObject(this->level_HUD);

	this->currentNameIndexYellow = 0;
	this->currentNameIndexRed = 0;
	this->currentNameIndexBlue = 0;

	this->createPlayer();
	this->createEnemy(utility::side::LEFT);
	this->createEnemy(utility::side::RIGHT);
}

LevelManager::~LevelManager()
{
	this->clearObjects();
}

void LevelManager::clearObjects() {
	this->mapLayers = nullptr;
	this->enemies_AI.clear();

	this->player = nullptr;

	//clear elements of HUD
	if (this->distance_HUD != nullptr) {
		this->distance_HUD->clear();
		this->distance_HUD = nullptr;
	}

	if (this->level_HUD != nullptr) {
		this->level_HUD->clear();
		this->level_HUD = nullptr;
	}
}

void LevelManager::levelLogic() {
	if (!this->player->isActive()) {
		this->clearObjects();
		Notifier::notify(utility::states::GAMEOVER);
		return;
	}

	for each (auto var in this->mapLayers->at("Interaction")->getGameObjects())
	{
		if (typeid(*var) == typeid(RedEnemy) ||
			typeid(*var) == typeid(YellowEnemy) ||
			typeid(*var) == typeid(BlueEnemy)) {
			if (!var->isActive()) {
				this->enemies_InGame--;
				this->enemiesDestoyed++;
			}
		}
	}

	if (this->delayEnemyDeploy >= 15) {
		this->createEnemy();
		this->delayEnemyDeploy = 0;
	}
	else {
		this->delayEnemyDeploy++;
	}

	if (this->enemiesDestoyed >= this->maxEnemies_perLevel && this->level_HUD->getLevel() <= this->level_HUD->getMaxLevel()) {
		this->increaseLevel();
		this->enemiesDestoyed = 0;
		this->maxEnemies_perLevel++;
		this->enemies_InGame = 0;
	}

	this->updateDistance();
}

void LevelManager::createEnemy(char side) {
	if (this->enemyCanCreated()) {
		auto randNum = rand() % 3;

		switch (randNum)
		{
		case utility::enemies::YELLOW_ENEMY:
			this->createYellowEnemy(side);
			break;
		case utility::enemies::RED_ENEMY:
			this->createRedEnemy(side);
			break;
		case utility::enemies::BLUE_ENEMY:
			this->createBlueEnemy(side);
			break;
		default:
			break;
		}

		this->enemies_InGame++;
	}
}

void LevelManager::createYellowEnemy(char side) {
	std::string nameEnemy = "YellowEnemy" + std::to_string(this->currentNameIndexYellow);
	std::string nameAI = "YellowEnemy_AI" + std::to_string(this->currentNameIndexYellow);
	char randNum = rand() % 2;
	float pos_x;
	char signal = 1;

	if (side != DEFAULT) {
		randNum = side;
	}

	if (randNum == utility::side::LEFT) {
		pos_x = -65.0;
	}
	else if (randNum == utility::side::RIGHT) {
		pos_x = SCREEN_WIDTH + 11;
		signal = -1;
	}

	this->mapLayers->at("Interaction")->addGameObject(new YellowEnemy(nameEnemy, new Rectangle(Vector2D(pos_x, BOTTOM_ZONE), Vector2D(54, 55), "destiny"), signal * 4));
	this->mapLayers->at("EnemyAI")->addGameObject(new YellowEnemy_AI(this->mapLayers->at("Interaction")->getGameObject(nameEnemy), nameAI));

	auto yellowAI = (Base_AI*)this->mapLayers->at("EnemyAI")->getGameObject(nameAI);
	this->enemies_AI.insert(std::pair<std::string, Base_AI*>(yellowAI->getName(), yellowAI));

	CheckerCollision::addAirplanes((Airplane*)this->mapLayers->at("Interaction")->getGameObject(nameEnemy));
	CheckerCollision::addObject(this->mapLayers->at("Interaction")->getGameObject(nameEnemy));

	if (this->currentNameIndexYellow >= ULLONG_MAX - 2) {
		this->currentNameIndexYellow = 0;
	}
	else {
		this->currentNameIndexYellow++;
	}
}

void LevelManager::createRedEnemy(char side) {
	std::string nameEnemy = "RedEnemy" + std::to_string(this->currentNameIndexRed);
	std::string nameAI = "RedEnemy_AI" + std::to_string(this->currentNameIndexRed);
	auto randNum = rand() % 2;
	float pos_x;
	char signal = 1;

	if (side != DEFAULT) {
		randNum = side;
	}

	if (randNum == utility::side::LEFT) {
		pos_x = -65.0;
	}
	else if (randNum == utility::side::RIGHT) {
		pos_x = SCREEN_WIDTH + 11;
		signal = -1;
	}

	this->mapLayers->at("Interaction")->addGameObject(new RedEnemy(nameEnemy, new Rectangle(Vector2D(pos_x, TOP_ZONE), Vector2D(54, 55), "destiny"), signal * 4));
	this->mapLayers->at("EnemyAI")->addGameObject(new RedEnemy_AI(this->mapLayers->at("Interaction")->getGameObject(nameEnemy), nameAI));

	auto redAI = (Base_AI*)this->mapLayers->at("EnemyAI")->getGameObject(nameAI);
	this->enemies_AI.insert(std::pair<std::string, Base_AI*>(redAI->getName(), redAI));

	CheckerCollision::addAirplanes((Airplane*)this->mapLayers->at("Interaction")->getGameObject(nameEnemy));
	CheckerCollision::addObject(this->mapLayers->at("Interaction")->getGameObject(nameEnemy));

	if (this->currentNameIndexRed >= ULLONG_MAX - 2) {
		this->currentNameIndexRed = 0;
	}
	else {
		this->currentNameIndexRed++;
	}
}

void LevelManager::createBlueEnemy(char side) {
	std::string nameEnemy = "BlueEnemy" + std::to_string(this->currentNameIndexBlue);
	std::string nameAI = "BlueEnemy_AI" + std::to_string(this->currentNameIndexBlue);
	auto randNum = rand() % 2;
	auto randNum2 = rand() % 2;
	float pos_x;
	char signal = 1;

	if (side != DEFAULT) {
		randNum = side;
	}

	if (randNum == utility::side::LEFT) {
		pos_x = -65.0;
	}
	else if (randNum == utility::side::RIGHT) {
		pos_x = SCREEN_WIDTH + 11;
		signal = -1;
	}

	if (randNum2 == utility::enemies::YELLOW_ENEMY) {
		this->mapLayers->at("Interaction")->addGameObject(new BlueEnemy(nameEnemy, new Rectangle(Vector2D(pos_x, BOTTOM_ZONE), Vector2D(54, 55), "destiny"), signal * 4));
		this->mapLayers->at("EnemyAI")->addGameObject(new YellowEnemy_AI(this->mapLayers->at("Interaction")->getGameObject(nameEnemy), nameAI));
	}
	else if (randNum2 == utility::enemies::RED_ENEMY) {
		this->mapLayers->at("Interaction")->addGameObject(new BlueEnemy(nameEnemy, new Rectangle(Vector2D(pos_x, TOP_ZONE), Vector2D(54, 55), "destiny"), signal * 4));
		this->mapLayers->at("EnemyAI")->addGameObject(new RedEnemy_AI(this->mapLayers->at("Interaction")->getGameObject(nameEnemy), nameAI));
	}

	auto blueAI = (Base_AI*)this->mapLayers->at("EnemyAI")->getGameObject(nameAI);
	this->enemies_AI.insert(std::pair<std::string, Base_AI*>(blueAI->getName(), blueAI));

	CheckerCollision::addAirplanes((Airplane*)this->mapLayers->at("Interaction")->getGameObject(nameEnemy));
	CheckerCollision::addObject(this->mapLayers->at("Interaction")->getGameObject(nameEnemy));

	if (this->currentNameIndexBlue >= ULLONG_MAX - 2) {
		this->currentNameIndexBlue = 0;
	}
	else {
		this->currentNameIndexBlue++;
	}
}

bool LevelManager::enemyCanCreated() {
	return (enemies_InGame < 3) && ((enemies_InGame + enemiesDestoyed) < maxEnemies_perLevel);
}

void LevelManager::increaseLevel() {
	this->level_HUD->increaseLevel();
}

void LevelManager::updateDistance() {
	this->distance_HUD->updateDistance();
}

void LevelManager::createPlayer() {
	this->player = new Player("Player");
	this->mapLayers->at("Interaction")->addGameObject(this->player);

	CheckerCollision::addAirplanes((Airplane*)this->mapLayers->at("Interaction")->getGameObject("Player"));
	CheckerCollision::addObject(this->mapLayers->at("Interaction")->getGameObject("Player"));
}

void LevelManager::saveScores() {

}
