#include "CakeBoss.h"



CakeBoss::CakeBoss()
{
	if (!mobTexture.loadFromFile("textures/cakeboss.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wskmobTexture = &mobTexture;
	mobSprite.setTexture(*wskmobTexture);
	imgHeight = (mobTexture.getSize().y / 4);
	imgWidth = (mobTexture.getSize().x / 8);
	hp = 1;
	speed = 200;
	canHurt = true;
	isAlive = true;
	imgCounter = 1;
	velocity.x = 0;
	velocity.y = 0;
	mobSprite.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
	mobSprite.setOrigin(-15, 0);
	grounded = false;
	timer.restart();
	bossTimer.restart();
}


CakeBoss::~CakeBoss()
{
	std::cout << "CakeBoss destroyed" << std::endl;
}

int CakeBoss::checkTimer()
{
	return bossTimer.getElapsedTime().asSeconds();
}

void CakeBoss::restartBossTimer()
{
	bossTimer.restart();
}