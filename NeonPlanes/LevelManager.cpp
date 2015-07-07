#include "LevelManager.h"

Distance_HUD* LevelManager::distance_HUD = nullptr;
Level_HUD* LevelManager::level_HUD = nullptr;

LevelManager::LevelManager(std::map<std::string, Layer*>* mapLayers) : mapLayers(mapLayers)
{
	this->enemiesDestoyed = 0;
	this->maxEnemies_perLevel = 2;
	this->enemies_InGame = 0;
	this->increaseAI_values = true;
	this->delayEnemyDeploy = 0;

	this->distance_HUD = new Distance_HUD("Distance_HUD", 1000, 100);
	this->mapLayers->at("HUD")->addGameObject(this->distance_HUD);
	
	this->level_HUD = new Level_HUD("Level_HUD");
	this->mapLayers->at("HUD")->addGameObject(this->level_HUD);

	this->light_HUD = new Light_HUD("Light_HUD");
	this->mapLayers->at("HUD")->addGameObject(this->light_HUD);

	this->currentNameIndexYellow = 0;
	this->currentNameIndexRed = 0;
	this->currentNameIndexBlue = 0;

	this->createPlayer();
	this->createEnemy(utility::side::LEFT);
	this->createEnemy(utility::side::RIGHT);
}

LevelManager::~LevelManager()
{
}

void LevelManager::clearObjects() {
	std::vector<GameObject*> removedHUD;
	removedHUD.push_back(this->distance_HUD);
	removedHUD.push_back(this->level_HUD);
	removedHUD.push_back(this->light_HUD);

	this->mapLayers->at("HUD")->removeMultiple(removedHUD);

	this->distance_HUD = nullptr;
	this->level_HUD = nullptr;
	this->light_HUD = nullptr;
	
	this->mapLayers = nullptr;
	this->enemies_AI.clear();

	this->player = nullptr;
}

void LevelManager::levelLogic() {
	if (!this->player->isActive()) {
		this->saveScores();
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
		this->light_HUD->fillLightLevel();
		this->enemiesDestoyed = 0;
		this->maxEnemies_perLevel++;
		this->enemies_InGame = 0;
	}

	if (this->light_HUD->getIsDecrease() != nullptr) {
		this->light_HUD->updateLightLevel();
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
	this->player = new Player("Player", (Light_HUD*)this->mapLayers->at("HUD")->getGameObject("Light_HUD"));
	this->mapLayers->at("Interaction")->addGameObject(this->player);

	CheckerCollision::addAirplanes((Airplane*)this->mapLayers->at("Interaction")->getGameObject("Player"));
	CheckerCollision::addObject(this->mapLayers->at("Interaction")->getGameObject("Player"));
}

unsigned long long int LevelManager::getPlayerScore() {
	return distance_HUD->getTotalDistance() * (1.0 + (level_HUD->getLevel() / 10.0));
}

std::pair<std::string, std::pair<std::string, std::string> > LevelManager::getLevelDistanceTotal() {
	std::string level;
	std::string distance;
	std::string total;
	ScoreData* playerData = new ScoreData("J01", distance_HUD->getTotalDistance());

	//Level text formated
	float param = 1.0 + (level_HUD->getLevel() / 10.0);
	float unit;
	float decimal = modf(param, &unit);
	int decimaInt = decimal * 10.0;
	level = std::to_string((int)unit) + "." + std::to_string(decimaInt);

	//Distance text formated
	DataStore::formatOutput(playerData);
	distance = std::to_string(playerData->unitValue) + "." + std::to_string(playerData->decimalValue) + playerData->modifier;

	//Total text formated
	playerData->totalDistance = playerData->totalDistance * param;
	DataStore::formatOutput(playerData);
	total = std::to_string(playerData->unitValue) + "." + std::to_string(playerData->decimalValue) + playerData->modifier;

	//Return
	std::pair<std::string, std::string> disTot(distance, total);
	return std::pair<std::string, std::pair<std::string, std::string> >(level, disTot);
}

void LevelManager::saveScores() {
	std::string fileName = DATA_PATH + "save.gdata";
	std::vector<ScoreData*> dataVector;
	ScoreData* playerScore;

	if (DataStore::hasFile(fileName)) {
		//read file
		dataVector = DataStore::ReadFile(fileName);
		std::cout << std::endl;
	}
	else {
		//create vector with default scores

		ScoreData* score1 = new ScoreData("MT2", 23000000000000);
		ScoreData* score2 = new ScoreData("MK5", 18000000000);
		ScoreData* score3 = new ScoreData("LK1", 11000000);
		ScoreData* score4 = new ScoreData("JN3", 16000);
		ScoreData* score5 = new ScoreData("EPH", 200);

		dataVector.push_back(score1);
		dataVector.push_back(score2);
		dataVector.push_back(score3);
		dataVector.push_back(score4);
		dataVector.push_back(score5);
	}

	playerScore = new ScoreData("J01", LevelManager::getPlayerScore());
	DataStore::formatOutput(playerScore);

	dataVector.push_back(playerScore);
	std::sort(dataVector.begin(), dataVector.end(), [](ScoreData* f, ScoreData* s){ return f->totalDistance > s->totalDistance; });
	
	std::cout << std::endl;

	std::vector<ScoreData*> greaterFiveScores(dataVector.begin(), dataVector.begin() + 5);

	std::cout << std::endl;

 	DataStore::WriteFile(fileName, greaterFiveScores);
}
