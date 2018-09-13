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
	imgWidth = (mobTexture.getSize().x / 9);
	hp = 80;
	speed = 100;
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
	scale = 1;
	RAISE = false;
	imgCounterDyingBoss = true;
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

void CakeBoss::uptade(float dt, float playerX)
{
	if (playerX  > mobSprite.getPosition().x)
	{
		if (timer.getElapsedTime().asSeconds() >= 0.13)
		{
			mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), imgHeight, -imgWidth, imgHeight));
			timer.restart();
			imgCounter++;
			if (imgCounter > 5)
				imgCounter = 1;
		}
		if (speed < 0)
		{
			changeDirection();
		}
	}
	else
	{
		if (timer.getElapsedTime().asSeconds() >= 0.13)
		{
			mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), imgHeight, imgWidth, imgHeight));
			timer.restart();
			imgCounter++;
			if (imgCounter > 5)
				imgCounter = 1;
		}
		if (speed > 0)
		{
			changeDirection();
		}
	}
	velocity.y += 981 * dt;
	if (grounded)
	{
		velocity.x = speed;
		grounded = true;
	}
	mobSprite.move(velocity * dt);
}

void CakeBoss::raiseOfLivingCake()
{
	if (scale < 1.3)
	{
		scale += 0.01;
		mobSprite.scale(scale, scale);
		velocity.y = -100;
		mobSprite.setPosition(mobSprite.getPosition().x, (mobSprite.getPosition().y - 100));
	}
}

void CakeBoss::changeHP(int i)
{
	hp += i;
}

void CakeBoss::dyingBoss(float dt)
{
	if (imgCounterDyingBoss)
	{
		imgCounter = 3;
		imgCounterDyingBoss = false;
	}
	imgWidth = (mobTexture.getSize().x / 6);
	if ((timer.getElapsedTime().asSeconds() >= 0.25) && (imgCounter < 6))
	{
		mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), imgHeight * 3, imgWidth, imgHeight));
		timer.restart();
		imgCounter++;
	}
}