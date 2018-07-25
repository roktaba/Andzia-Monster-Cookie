#include "points.h"

points::points()
{
	//    pointsFont.loadFromFile("aa");
	pkt = 0;
	double f = 23.43;
	//  std::string f_str = std::to_string(f);
	//  cakesPoints.setString(pktString);
	// cakesPoints.setFont(pointsFont);
	cakesPoints.setPosition(500, 500);
}

points::~points()
{
	//dtor
}

void points::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(cakesPoints, states);
}

void points::increasePkt()
{
	pkt++;
}
