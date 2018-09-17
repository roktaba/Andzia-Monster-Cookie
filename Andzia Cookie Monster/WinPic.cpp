#include "WinPic.h"

WinPic::WinPic(int x, int y)
{
	sf::Vector2f sizeWindow(x + 50, y + 50);
	PicSprite.setSize(sizeWindow);
	if (!PicSPriteTexture.loadFromFile("textures/WIN.jpg"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	PicSprite.setTexture(&PicSPriteTexture);
}


WinPic::~WinPic()
{
}

void WinPic::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(PicSprite, states);
}

void WinPic::setPosPic(int x)
{
	sf::Vector2f sizeWindow(x - 400, PicSprite.getPosition().y);
	PicSprite.setPosition(sizeWindow);
}
