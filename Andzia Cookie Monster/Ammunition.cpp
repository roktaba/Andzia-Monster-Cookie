#include "Ammunition.h"

Ammunition::Ammunition()
{
	ammoCounter = 10;
	ammoRange = 520;
	ammoWay = 0;
	ammoSpeed = 1000;
	ammoDmg = 1;
	ammoVelocity.x = ammoSpeed;
	ammoVelocity.y = 0;
	timer.restart();
	imgCounter = 0;
	imgWidth = 0;
	imgWidth = 0;
}

Ammunition::~Ammunition()
{
	//dtor
}

void Ammunition::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(ammoSprite, states);
}

void Ammunition::setNewPossition(sf::Vector2f newPos)
{
	ammoSprite.setPosition(newPos.x, (newPos.y + 40));
}

bool Ammunition::ammoCollision(float push, sf::Sprite &other)
{
	sf::Vector2f mainPosition(ammoSprite.getPosition());
	sf::Vector2f otherPosition(other.getPosition());
	otherPosition.x = otherPosition.x + 32;
	otherPosition.y = otherPosition.y + 32;

	sf::Vector2f mainHalfSize((ammoSprite.getGlobalBounds().width / 2), (ammoSprite.getGlobalBounds().height / 2));
	sf::Vector2f otherHalfSize((other.getGlobalBounds().width / 2), (other.getGlobalBounds().height / 2));

	float deltaX = otherPosition.x - mainPosition.x;
	float deltaY = otherPosition.y - mainPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + mainHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + mainHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				ammoSprite.move(intersectX * (1.0 - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else
			{
				ammoSprite.move(-intersectX * (1.0 - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				ammoSprite.move(0.0f, intersectY* (1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else
			{
				ammoSprite.move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	return false;
}
