#include "statusBar.h"

statusBar::statusBar()
{
	if (!healthTexture.loadFromFile("textures/heart.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wskhealthTexture = &healthTexture;
	healthSprite.setTexture(*wskhealthTexture);
	imgHeight = (healthTexture.getSize().y / 2);
	imgWidth = (healthTexture.getSize().x / 3);
	healthSprite.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
	healthSprite.setPosition(100, 20);
	imgCounter = 0;
	timer.restart();
	healthSprite.setScale(0.7, 0.7);
	line = 0;
}

statusBar::~statusBar()
{
	//dtor
}

void statusBar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(healthSprite, states);
}

void statusBar::setPos(int x, int i)
{
	sf::Vector2f sizeWindow((x + 850 - (i*imgWidth)), healthSprite.getPosition().y);
	healthSprite.setPosition(sizeWindow);
}

void statusBar::update(float dt)
{
	if (timer.getElapsedTime().asSeconds() >= 0.15)
	{
		healthSprite.setTextureRect(sf::IntRect((imgCounter*imgWidth), imgHeight*line, imgWidth, imgHeight));
		timer.restart();
		imgCounter++;
		if (imgCounter > 2)
		{
			imgCounter = 0;
			line++;
			if (line == 2)
				line = 0;
		}
	}
}
