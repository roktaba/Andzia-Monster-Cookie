#include "GameMenu.h"

GameMenu::GameMenu()
{
	if (!menuFont.loadFromFile("fonts/KGCamdenMarketScript.ttf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
}

GameMenu::~GameMenu()
{
	std::cout << "GameMenu destroyed" << std::endl;
}
int GameMenu::startMenu(sf::RenderWindow &window)
{
	while (true)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::RectangleShape wallpaper(sf::Vector2f(window.getSize().x, window.getSize().y));
		sf::Texture menuwallpaper;
		menuwallpaper.loadFromFile("textures/chocomenu.jpg");
		wallpaper.setTexture(&menuwallpaper);

		sf::Text title;
		title.setFont(menuFont);
		title.setString("ANDZIA COOKIE MONSTER!");
		title.setCharacterSize(70);
		title.setFillColor(sf::Color::Cyan);
		title.setStyle(sf::Text::Style::Bold);
		title.setPosition(((window.getSize().x - title.getGlobalBounds().width) / 2), 10);

		sf::Text play;
		play.setFont(menuFont);
		play.setString("PLAY");
		play.setCharacterSize(50);
		play.setStyle(sf::Text::Style::Bold);
		play.setPosition(((window.getSize().x - play.getGlobalBounds().width) / 2), ((window.getSize().y - play.getGlobalBounds().height) / 2));
		if (play.getGlobalBounds().contains(mouse))
		{
			play.setFillColor(sf::Color::Red);
		}
		else play.setFillColor(sf::Color::White);
		if ((play.getGlobalBounds().contains(mouse)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			return 1;
		}

		sf::Text exit;
		exit.setFont(menuFont);
		exit.setString("EXIT");
		exit.setCharacterSize(50);
		exit.setFillColor(sf::Color::White);
		exit.setStyle(sf::Text::Style::Bold);
		exit.setPosition(((window.getSize().x - exit.getGlobalBounds().width) / 2), (((window.getSize().y - exit.getGlobalBounds().height) / 2) + 100));
		if (exit.getGlobalBounds().contains(mouse))
		{
			exit.setFillColor(sf::Color::Red);
		}
		else exit.setFillColor(sf::Color::White);
		if ((exit.getGlobalBounds().contains(mouse)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			return 0;
		}

		window.clear();
		window.draw(wallpaper);
		window.draw(title);
		window.draw(play);
		window.draw(exit);
		window.display();
	}
}
