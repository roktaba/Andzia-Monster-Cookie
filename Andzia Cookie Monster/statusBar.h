#ifndef STATUSBAR_H
#define STATUSBAR_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>


class statusBar :public sf::Drawable, sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Sprite healthSprite;
	sf::Texture healthTexture;
	sf::Texture *wskhealthTexture;
	sf::Clock timer;
	float imgWidth, imgHeight;
	int imgCounter, line;

public:
	statusBar();
	~statusBar();
	void setPos(int x, int i);
	void update(float dt);
};

#endif // STATUSBAR_H
