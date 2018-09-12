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
private:
	sf::Clock bossTimer;
};

