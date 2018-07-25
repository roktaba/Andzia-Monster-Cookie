#include "Cake.h"

Cake::Cake()
{
	if (!mobTexture.loadFromFile("textures/cakemob2.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wskmobTexture = &mobTexture;
	mobSprite.setTexture(*wskmobTexture);
	imgHeight = (mobTexture.getSize().y / 4);
	imgWidth = (mobTexture.getSize().x / 9);
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
}

Cake::~Cake()
{
	std::cout << "Cake destroyed" << std::endl;
}

void Cake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mobSprite, states);
}

void Cake::uptade(float dt)
{
	if (speed > 0)
	{
		if (timer.getElapsedTime().asSeconds() >= 0.1)
		{
			mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), 0, -imgWidth, imgHeight));
			timer.restart();
			imgCounter++;
			if (imgCounter > 7)
				imgCounter = 1;
		}
	}
	else
	{
		if (timer.getElapsedTime().asSeconds() >= 0.1)
		{
			mobSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), 0, imgWidth, imgHeight));
			timer.restart();
			imgCounter++;
			if (imgCounter > 7)
				imgCounter = 1;
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

bool Cake::collision(float push, sf::Sprite &other)
{
	sf::Vector2f mainPosition(mobSprite.getPosition());
	sf::Vector2f otherPosition(other.getPosition());

	sf::Vector2f mainHalfSize((mobSprite.getGlobalBounds().width / 2), (mobSprite.getGlobalBounds().height / 2));
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
				mobSprite.move(intersectX * (1.0 - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
				changeDirection();
			}
			else
			{
				mobSprite.move(-intersectX * (1.0 - push), 0.0f);
				other.move(intersectX * push, 0.0f);
				changeDirection();
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				mobSprite.move(0.0f, intersectY* (1.0f - push));
				other.move(0.0f, -intersectY * push);
				velocity.y = 0.0;
				grounded = true;
			}
			else
			{
				mobSprite.move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
				if (velocity.y < 0)
					velocity.y = 0.0;
			}
		}
		return true;
	}
	return false;
}

void Cake::changeDirection()
{
	speed *= -1;
}

void Cake::setNewPossition(int i, int j, sf::Vector2f tileSize)
{
	mobSprite.setPosition(((i*tileSize.y*1.5) - 3 * tileSize.x), (j*tileSize.x*1.5));
}
