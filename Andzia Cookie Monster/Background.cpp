#include "Background.h"

Background::Background(int x, int y)
{
	sf::Vector2f sizeWindow(x + 100, y + 100);
	backG.setSize(sizeWindow);
	if (!backGTexture.loadFromFile("textures/backgroundlvl1.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	backG.setTexture(&backGTexture);
}

Background::~Background()
{
	std::cout << "Background Destroyed" << std::endl;
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backG, states);
}

void Background::setPos(int x)
{
	sf::Vector2f sizeWindow(x - 400, backG.getPosition().y);
	backG.setPosition(sizeWindow);
}
