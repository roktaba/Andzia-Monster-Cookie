#ifndef GAMEMENU_H
#define GAMEMENU_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>


class GameMenu :public sf::RenderWindow
{
private:
	sf::Font menuFont;
public:
	GameMenu();
	~GameMenu();
	int startMenu(sf::RenderWindow &window);
};

#endif // GAMEMENU_H
