#include "Level.h"

Level::Level()
{
	if (!tileMapTexture.loadFromFile("textures/Tileset.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}

	tileMap.setTexture(tileMapTexture);
	imgHeight = (tileMapTexture.getSize().y / 7);
	imgWidth = (tileMapTexture.getSize().x / 13);
	tileMap.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
	tileMap.setScale(1.5, 1.5);
	tileMap.setPosition(0, 0);
}

Level::~Level()
{
	//dtor
}

void Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(tileMap, states);
}

void Level::setNewPossiotion(int i, int j)
{
	tileMap.setPosition(((i*imgHeight*1.5) - 3 * imgWidth), (j*imgWidth*1.5));
}

void Level::changeTexture(int counter)
{
	switch (counter)
	{
	case 1:
		tileMap.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
		break;
	case 2:
		tileMap.setTextureRect(sf::IntRect(imgWidth, 0, imgWidth, imgHeight));
		break;
	case 3:
		tileMap.setTextureRect(sf::IntRect(imgWidth + imgWidth, 0, imgWidth, imgHeight));
		break;
	case 4:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, 0, imgWidth, imgHeight));
		break;
	case 5:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, imgHeight, imgWidth, imgHeight));
		break;
	case 6:
		tileMap.setTextureRect(sf::IntRect(0, imgHeight, imgWidth, imgHeight));
		break;
	case 7:
		tileMap.setTextureRect(sf::IntRect(imgWidth, imgHeight, imgWidth, imgHeight));
		break;
	case 8:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 2, imgHeight, imgWidth, imgHeight));
		break;
	case 72:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 9, 0, imgWidth, imgHeight));
		break;
	default:
		break;
	}
}

sf::Vector2f Level::tileSize()
{
	return sf::Vector2f(imgWidth, imgHeight);
}
