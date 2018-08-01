#ifndef DEATHCAKE_H
#define DEATHCAKE_H
#include "Cake.h"


class DeathCake : public Cake
{
private:

public:
	DeathCake();
	~DeathCake();
	void setNewPossition(int x, int y);
	void uptade(float dt);
	void setPos(int x);
};

#endif // DEATHCAKE_H
