#include "DeathCake.h"

DeathCake::DeathCake()
{
	if (!mobTexture.loadFromFile("textures/cakemob2.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wskmobTexture = &mobTexture;
	mobSprite.setTexture(*wskmobTexture);
	imgHeight = (mobTexture.getSize().y / 4);
	imgWidth = (mobTexture.getSize().x / 7);
	hp = 0;
	speed = 0;
	canHurt = false;
	isAlive = false;
	imgCounter = 0;
	velocity.x = 0;
	velocity.y = 0;
	mobSprite.setTextureRect(sf::IntRect(0, ((imgHeight * 2)+5), imgWidth, imgHeight));
	mobSprite.setOrigin(-15, 0);
	grounded = false;
	timer.restart();
	mobSprite.setScale(0.6, 0.6);
}

DeathCake::~DeathCake()
{
	//dtor
}

void DeathCake::setNewPossition(int x, int y)
{
	mobSprite.setPosition(x, y + 15);
}

void DeathCake::uptade(float dt)
{
	if ((timer.getElapsedTime().asSeconds() >= 0.13) && (imgCounter < 9))
	{
		mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), imgHeight * 3, imgWidth, imgHeight));
		timer.restart();
		imgCounter++;
		if (imgCounter > 8)
		{
			imgWidth = (mobTexture.getSize().x / 8);
			mobSprite.setTextureRect(sf::IntRect(0, imgHeight, imgWidth, imgHeight));
			mobSprite.setScale(0.7, 0.7);
		}
	}
}

void DeathCake::setPos(int x)
{
	sf::Vector2f sizeWindow(x - 350, mobSprite.getPosition().y);
	mobSprite.setPosition(sizeWindow);
}