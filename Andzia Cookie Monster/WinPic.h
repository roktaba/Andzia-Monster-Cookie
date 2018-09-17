#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>

class WinPic :public sf::Drawable, sf::Transformable
{
public:
	WinPic(int x, int y);
	~WinPic();
	void setPosPic(int x);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::RectangleShape PicSprite;
	sf::Texture PicSPriteTexture;
};

