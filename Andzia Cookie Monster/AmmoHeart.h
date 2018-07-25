#ifndef AMMOHEART_H
#define AMMOHEART_H

#include "Ammunition.h"


class AmmoHeart : public Ammunition
{
private:
	sf::Texture heartTexture;
	sf::Texture *wskHeartTexture;
	sf::Vector2f startPossition;

public:
	AmmoHeart();
	~AmmoHeart();
	void uptade(float dt);
	bool ammoRangeCheck();
	void changeDirection();
};

#endif // AMMOHEART_H
