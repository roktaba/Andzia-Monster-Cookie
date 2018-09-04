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
	velocity.x = 0;
	velocity.y = 0;
	posY = 0;
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
	posY = tileMap.getPosition().y;
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
	case 9:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 2, imgHeight * 3, imgWidth, imgHeight));
		break;
	case 72:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 9, 0, imgWidth, imgHeight));
		break;
	case 51:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 2, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 50:
		tileMap.setTextureRect(sf::IntRect(imgWidth, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 49:
		tileMap.setTextureRect(sf::IntRect(0, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 52:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 53:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 4, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 54:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 5, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 55:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 10, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 56:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 11, imgHeight * 4, imgWidth, imgHeight));
		break;
	case 57:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 2, imgHeight * 6, imgWidth, imgHeight));
		break;
	case 58:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 4, imgHeight, imgWidth, imgHeight));
		tileMap.setScale(1, 1);
		tileMap.setPosition(tileMap.getPosition().x, (tileMap.getPosition().y + 40));
		break;
	case 59:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, imgHeight*2, imgWidth, imgHeight));
		break;
	case 60:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 5, imgHeight * 5, imgWidth, imgHeight));
		break;
	case 61:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 6, imgHeight * 5, imgWidth, imgHeight));
		break;
	case 62:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 7, imgHeight * 5, imgWidth, imgHeight));
		break;
	case 63:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 5, imgHeight * 6, imgWidth, imgHeight));
		break;
	case 64:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 6, imgHeight * 6, imgWidth, imgHeight));
		break;
	case 65:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 7, imgHeight * 6, imgWidth, imgHeight));
		break;
	case 66:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, imgHeight * 5, imgWidth, imgHeight));
		break;
	case 67:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 4, imgHeight * 5, imgWidth, imgHeight));
		break;
	case 68:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 3, imgHeight * 6, imgWidth, imgHeight));
		break;
	case 69:
		tileMap.setTextureRect(sf::IntRect(imgWidth * 4, imgHeight * 6, imgWidth, imgHeight));
		break;
	default:
		break;
	}
}

sf::Vector2f Level::tileSize()
{
	return sf::Vector2f(imgWidth, imgHeight);
}