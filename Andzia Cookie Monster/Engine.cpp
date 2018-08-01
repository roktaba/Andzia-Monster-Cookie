#include "Engine.h"

Engine::Engine()
{
	mapLoaded = false;
	mapCounter = 0;
}

Engine::~Engine()
{
	std::cout << "Engine destroyed" << std::endl;
}

int Engine::runGame(sf::RenderWindow &window)
{
	Player player1;
	points cakesPkt;
	statusBar healthCounter;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1280, 960));
	std::vector <statusBar> healthBar;
	std::vector <Level> platform;
	std::vector <Level> platformNonCol;
	std::vector <Level> platformBlocker;
	std::vector <Cake> ciastko;
	std::vector <DeathCake> martweCiastko;
	for (int i = 0; i<player1.howManyLifes(); i++)
	{
		healthBar.push_back(healthCounter);
	}
	DeathCake DCiastko;
	Cake cake1;
	Level lvl;
	Background lvl1Background(window.getSize().x, window.getSize().y);
	if (mapLoaded == false)
	{
		std::ifstream plik;
		std::string nazwa = "lvl1.txt";
		plik.open(nazwa.c_str(), std::ios::in);
		if (plik.good() == false)
		{
			MessageBox(0, "lvl1.txt not found!", "ERROR", 0);
		}
		int x = 0;
		while (!plik.eof())
		{
			for (int j = 0; j<10; j++)
			{
				std::string line;
				std::getline(plik, line);
				for (int i = 0; i<line.size(); i++)
				{
					tabLvl[j][i] = (line[i] - '0');
					if (tabLvl[j][i] != 0)
					{
						if ((tabLvl[j][i] == 1) || (tabLvl[j][i] == 2) || (tabLvl[j][i] == 3) || (tabLvl[j][i] == 6) || (tabLvl[j][i] == 7) || (tabLvl[j][i] == 8))
						{
							platform.push_back(lvl);
							platform[platform.size() - 1].setNewPossiotion(i, j);
							platform[platform.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if ((tabLvl[j][i] == 4) || (tabLvl[j][i] == 5))
						{
							platformNonCol.push_back(lvl);
							platformNonCol[platformNonCol.size() - 1].setNewPossiotion(i, j);
							platformNonCol[platformNonCol.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if (tabLvl[j][i] == 72)
						{
							platformBlocker.push_back(lvl);
							platformBlocker[platformBlocker.size() - 1].setNewPossiotion(i, j);
							platformBlocker[platformBlocker.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if (tabLvl[j][i] == 17)
						{
							ciastko.push_back(cake1);
							ciastko[ciastko.size() - 1].setNewPossition(i, j, platform[0].tileSize());
						}
					}
				}
			}
		}
		plik.close();
		mapLoaded = true;
	}
	sf::Clock deltaTime;
	while (true)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			return 0;
		sf::Event akcjaOkna;
		while (window.pollEvent(akcjaOkna))
		{
			switch (akcjaOkna.type)
            case sf::Event::Closed:
				return 0;
				break;
		}
		//UPTADE PART//
		float dt = deltaTime.restart().asSeconds();
		player1.uptade(dt);
		for (int i = 0; i<ciastko.size(); i++)
		{
			ciastko[i].uptade(dt);
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			martweCiastko[i].uptade(dt);
		}
		if (!player1.checkLife(window.getSize().y))
		{
			if (healthBar.size()<2)
			{
				view.setCenter((window.getSize().x / 2), (window.getSize().y) / 2);
				window.clear();
				window.setView(view);
				return 1;
			}
			healthBar.erase(healthBar.begin() + healthBar.size() - 1);
			player1.setStartPos();
		}
		//COLLISION PART//
		for (int j = 0; j<ciastko.size(); j++)
		{
			for (int i = 0; i<platform.size(); i++)
			{
				ciastko[j].collision(0.0, platform[i].tileMap);
			}
		}
		for (int j = 0; j<ciastko.size(); j++)
		{
			for (int i = 0; i<platformBlocker.size(); i++)
			{
				ciastko[j].collision(0.0, platformBlocker[i].tileMap);
			}
		}
		for (int i = 0; i<platform.size(); i++)
		{
			player1.collision(0.0, platform[i].tileMap);
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			if (player1.collision(1.0, martweCiastko[i].mobSprite))
			{
				martweCiastko.erase(martweCiastko.begin() + martweCiastko.size() - 1);
				cakesPkt.increasePkt();
			}
		}
		for (int i = 0; i<platform.size(); i++)
		{
			player1.arrowCollision(platform[i].tileMap, false);
		}
		for (int i = 0; i<ciastko.size(); i++)
		{
			if (player1.collision(0.0, ciastko[i].mobSprite))
			{
				healthBar.erase(healthBar.begin() + healthBar.size() - 1);
				player1.setStartPos();
			}
		}
		for (int i = 0; i<ciastko.size(); i++)
		{
			if (player1.arrowCollision(ciastko[i].mobSprite, true))
			{
				martweCiastko.push_back(DCiastko);
				martweCiastko[martweCiastko.size() - 1].setNewPossition(ciastko[i].mobSprite.getPosition().x, ciastko[i].mobSprite.getPosition().y);
				ciastko.erase(ciastko.begin() + i);
			}
		}
		view.setCenter((player1.getPlayerPos().x + 300), (window.getSize().y / 2));
		window.clear();
		window.setView(view);
		lvl1Background.setPos(player1.getPlayerPos().x);
		cakesPkt.setPos(player1.getPlayerPos().x);
		for (int i = 0; i<healthBar.size(); i++)
		{
			healthBar[i].update(dt);
		}
		for (int i = 0; i<healthBar.size(); i++)
		{
			healthBar[i].setPos(player1.getPlayerPos().x, i);
		}
		//DRAW PART//
		for (int i = 0; i<platformBlocker.size(); i++)
		{
			window.draw(platformBlocker[i]);
		}
		window.draw(lvl1Background);
		for (int i = 0; i<platform.size(); i++)
		{
			window.draw(platform[i]);
		}
		for (int i = 0; i<platformNonCol.size(); i++)
		{
			window.draw(platformNonCol[i]);
		}
		window.draw(player1);
		for (int i = 0; i<ciastko.size(); i++)
		{
			window.draw(ciastko[i]);
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			window.draw(martweCiastko[i]);
		}
		player1.drawAmmo(window);
		window.draw(cakesPkt);
		for (int i = 0; i<healthBar.size(); i++)
		{
			window.draw(healthBar[i]);
		}
		window.display();
	}
}
