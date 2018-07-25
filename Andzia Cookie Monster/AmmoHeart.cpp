#include "AmmoHeart.h"

AmmoHeart::AmmoHeart()
{
	if (!heartTexture.loadFromFile("textures/arrowheart.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wskHeartTexture = &heartTexture;
	ammoSprite.setTexture(*wskHeartTexture);
}

AmmoHeart::~AmmoHeart()
{
	//std::cout<<"test"<<std::endl;
}

void AmmoHeart::uptade(float dt)
{
	ammoWay = (ammoWay + (ammoVelocity.x*dt));
	ammoSprite.move(ammoVelocity*dt);
}

bool AmmoHeart::ammoRangeCheck()
{
	if (abs(ammoWay) > ammoRange)
		return false;
	return true;
}

void AmmoHeart::changeDirection()
{
	ammoVelocity.x = ammoVelocity.x * -1;
	ammoSprite.setTextureRect(sf::IntRect(heartTexture.getSize().x, 0, (heartTexture.getSize().x* -1), heartTexture.getSize().y));
}
