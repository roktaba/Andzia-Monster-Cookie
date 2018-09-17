#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <cmath>
#include "AmmoHeart.h"
#include <vector>


class Player :public sf::Drawable,
	sf::Transformable
{
private:
	sf::Texture playerTexture;
	sf::Texture *wskplayerTexture;
	sf::Vector2f velocity;
	sf::Clock timer;
	sf::Clock ammoTimer;
	float mvspeed;
	float imgWidth, imgHeight;
	int imgCounter;
	bool canJump;
	float jumpHeight;
	int life;
	bool faceRight;
	AmmoHeart ammunitionHearts;
	std::vector <AmmoHeart> AmmoH;
	sf::Vector2f respawnPlace;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	Player();
	~Player();
	void uptade(float dt);
	void setJump();
	bool collision(float push, sf::Sprite &other);
	sf::Vector2f getPlayerPos();
	void drawAmmo(sf::RenderWindow &window);
	void eraseArrow(int numer);
	bool arrowCollision(sf::Sprite &otherSprite, bool destroy);
	void setStartPos();
	int howManyLifes();
	void setPlayerPos(float x, float y);
	sf::Sprite playerSprite;
	void changeRespawnPoint();
};

#endif // PLAYER_H
