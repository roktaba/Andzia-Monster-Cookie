#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>


class Level :public sf::Drawable, sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Texture tileMapTexture;
	sf::Texture *wskTileMapTexture;
	float imgWidth, imgHeight;
	sf::Vector2f velocity;
	float posY;

public:
	sf::Sprite tileMap;
	Level();
	~Level();
	void setNewPossiotion(int i, int j);
	void changeTexture(int counter);
	sf::Vector2f tileSize();
};

#endif // LEVEL_H
