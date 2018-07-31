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
	cakesPoints.setString(pktString);
	cakesPoints.setFont(pointsFont);
	cakesPoints.setFillColor(sf::Color::Blue);
	cakesPoints.setPosition(100, 20);
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

void points::setPos(int x)
{
	sf::Vector2f sizeWindow(x-300, cakesPoints.getPosition().y);
	cakesPoints.setPosition(sizeWindow);
}