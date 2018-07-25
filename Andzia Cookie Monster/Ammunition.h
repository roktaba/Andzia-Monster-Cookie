#ifndef AMMUNITION_H
#define AMMUNITION_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

class Ammunition :public sf::Drawable, sf::Transformable
{
protected:
	int ammoCounter;
	int ammoRange;
	int ammoWay;
	int ammoSpeed;
	int ammoDmg;
	sf::Vector2f ammoVelocity;
	sf::Clock timer;
	int imgCounter;
	float imgWidth, imgHeight;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	sf::Sprite ammoSprite;
	Ammunition();
	~Ammunition();
	void setNewPossition(sf::Vector2f newPos);
	bool ammoCollision(float push, sf::Sprite &other);
};

#endif // AMMUNITION_H
