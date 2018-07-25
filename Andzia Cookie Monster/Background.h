#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

class Background :public sf::Drawable, sf::Transformable

{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::RectangleShape backG;
	sf::Texture backGTexture;
public:
	Background(int x, int y);
	~Background();
	void setPos(int x);
};

#endif // BACKGROUND_H
