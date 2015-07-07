#pragma once

#include "Layer.h"

#include "Distance_HUD.h"
#include "Level_HUD.h"
#include "Light_HUD.h"

#include "Player.h"
#include "BlueEnemy.h"
#include "RedEnemy.h"
#include "YellowEnemy.h"

#include "YellowEnemy_AI.h"
#include "RedEnemy_AI.h"

#include "DataStore.h"
#include "Notifier.h"
#include "CheckerCollision.h"

class LevelManager
{
public:
	LevelManager(std::map<std::string, Layer*>* mapLayers);
	virtual ~LevelManager();

	void clearObjects();
	void levelLogic();
private:
	void createEnemy(char side = DEFAULT);
	bool enemyCanCreated();
	void createYellowEnemy(char side = DEFAULT);
	void createRedEnemy(char side = DEFAULT);
	void createBlueEnemy(char side = DEFAULT);

	void createPlayer();
	void increaseLevel();
	void updateDistance();
	void saveScores();
	static unsigned long long int getPlayerScore();
	
	int enemiesDestoyed;
	int maxEnemies_perLevel;
	int enemies_InGame;
	bool increaseAI_values;
	int delayEnemyDeploy;

	unsigned long long int currentNameIndexYellow;
	unsigned long long int currentNameIndexRed;
	unsigned long long int currentNameIndexBlue;

	//elements of HUD
	static Distance_HUD* distance_HUD;
	static Level_HUD* level_HUD;
	Light_HUD* light_HUD;

	Player* player;
	std::map<std::string, Base_AI*> enemies_AI;
	std::map<std::string, Layer*>* mapLayers;
};
