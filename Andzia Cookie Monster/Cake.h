#ifndef CAKE_H
#define CAKE_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>


class Cake :public sf::Drawable,
	sf::Transformable
{
protected:
	int hp;
	int speed;
	bool canHurt;
	bool isAlive;
	sf::Texture mobTexture;
	sf::Texture *wskmobTexture;
	sf::Vector2f velocity;
	sf::Clock timer;
	int imgCounter;
	float imgWidth, imgHeight;
	bool grounded;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	sf::Sprite mobSprite;
	Cake();
	~Cake();
	void uptade(float dt);
	bool collision(float push, sf::Sprite &other);
	void changeDirection();
	void setNewPossition(int i, int j, sf::Vector2f tileSize);

};

#endif // CAKE_H
