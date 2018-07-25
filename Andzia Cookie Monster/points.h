#ifndef POINTS_H
#define POINTS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>


class points :public sf::Drawable,
	sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Text cakesPoints;
	std::string pktString;
	int pkt;
	sf::Font pointsFont;

public:
	points();
	~points();
	void increasePkt();
};

#endif // POINTS_H
