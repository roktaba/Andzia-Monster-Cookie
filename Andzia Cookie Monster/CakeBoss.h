#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "Cake.h"

class CakeBoss: public Cake
{
public:
	CakeBoss();
	~CakeBoss();
	int checkTimer();
	void restartBossTimer();
	void uptade(float dt, float playerX);
	void raiseOfLivingCake();
	void changeHP(int i);
	bool RAISE;
	void dyingBoss(float dt);
	bool imgCounterDyingBoss;
private:
	sf::Clock bossTimer;
	float scale;
};

