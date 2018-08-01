#include "points.h"

points::points()
{
	if (!pointsFont.loadFromFile("fonts/KGCamdenMarketScript.ttf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	pkt = 0;
	std::string pktString = std::to_string(pkt);
	ix = "x";
	pktString = ix + pktString;
	cakesPoints.setString(pktString);
	cakesPoints.setFont(pointsFont);
	cakesPoints.setFillColor(sf::Color::Magenta);
	cakesPoints.setCharacterSize(40);
	cakesPoints.setPosition(200, 20);
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
	std::string pktString = std::to_string(pkt);
	pktString = ix + pktString;
	cakesPoints.setString(pktString);
}

void points::setPos(int x)
{
	sf::Vector2f sizeWindow(x-280, cakesPoints.getPosition().y);
	cakesPoints.setPosition(sizeWindow);
}