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
	CakeBoss Boss;
	WinPic AndziaWin(window.getSize().x, window.getSize().y);
	Boss.isAlive = false;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1280, 960));
	std::vector <statusBar> healthBar;
	std::vector <Level> platform;
	std::vector <Level> platformNonCol;
	std::vector <Level> platformBlocker;
	std::vector <Level> platformKilling;
	std::vector <Level> platformBox;
	std::vector <Cake> ciastko;
	std::vector <DeathCake> martweCiastko;
	for (int i = 0; i<player1.howManyLifes(); i++)
	{
		healthBar.push_back(healthCounter);
	}
	DeathCake DCiastko;
	DeathCake cakeCounter;
	cakeCounter.setNewPossition(-250, -5);
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
						if ((tabLvl[j][i] == 1) || (tabLvl[j][i] == 2) || (tabLvl[j][i] == 3) || (tabLvl[j][i] == 6) || (tabLvl[j][i] == 7) || (tabLvl[j][i] == 8) || (tabLvl[j][i] == 9) || (tabLvl[j][i] == 51) || (tabLvl[j][i] == 50) || (tabLvl[j][i] == 49) || (tabLvl[j][i] == 63) || (tabLvl[j][i] == 64) || (tabLvl[j][i] == 65) || (tabLvl[j][i] == 66) || (tabLvl[j][i] == 67) || (tabLvl[j][i] == 68) || (tabLvl[j][i] == 69))
						{
							platform.push_back(lvl);
							platform[platform.size() - 1].setNewPossiotion(i, j);
							platform[platform.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if ((tabLvl[j][i] == 4) || (tabLvl[j][i] == 5) || (tabLvl[j][i] == 52) || (tabLvl[j][i] == 53) || (tabLvl[j][i] == 54) || (tabLvl[j][i] == 55) || (tabLvl[j][i] == 56) || (tabLvl[j][i] == 57) || (tabLvl[j][i] == 60) || (tabLvl[j][i] == 61) || (tabLvl[j][i] == 62))
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
						if (tabLvl[j][i] == 58)
						{
							platformKilling.push_back(lvl);
							platformKilling[platformKilling.size() - 1].setNewPossiotion(i, j);
							platformKilling[platformKilling.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if (tabLvl[j][i] == 59)
						{
							platformBox.push_back(lvl);
							platformBox[platformBox.size() - 1].setNewPossiotion(i, j);
							platformBox[platformBox.size() - 1].changeTexture(tabLvl[j][i]);
						}
						if (tabLvl[j][i] == 17)
						{
							ciastko.push_back(cake1);
							ciastko[ciastko.size() - 1].setNewPossition(i, j, lvl.tileSize());
						}
						if (tabLvl[j][i] == 70)
						{
							Boss.setNewPossition(i, j, lvl.tileSize());
							Boss.isAlive = true;
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
		if (Boss.RAISE)
		{
			Boss.uptade(dt, player1.getPlayerPos().x);
		}
		for (int i = 0; i<ciastko.size(); i++)
		{
			ciastko[i].uptade(dt);
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			martweCiastko[i].uptade(dt);
		}
		if (((player1.getPlayerPos().y) > (window.getSize().y + 100)) && (healthBar.size() > 0))
		{
			healthBar.erase(healthBar.begin() + healthBar.size() - 1);
			player1.setStartPos();
		}
		if (healthBar.size()==0)
		{
			view.setCenter((window.getSize().x / 2), (window.getSize().y) / 2);
			window.clear();
			window.setView(view);
			return 1;
		}
		//BOSS//
		if ((Boss.isAlive==true)&&(Boss.checkTimer() > 3)&&(Boss.RAISE))
		{
			ciastko.push_back(cake1);
			Boss.restartBossTimer();
			ciastko[ciastko.size() - 1].mobSprite.setPosition(Boss.mobSprite.getPosition().x, Boss.mobSprite.getPosition().y);
			ciastko[ciastko.size() - 1].setVelocityY();
			if (ciastko.size() % 2 == 0)
			{
				ciastko[ciastko.size() - 1].changeDirection();
				ciastko[ciastko.size() - 1].setVelocityX();
			}
		}
		//COLLISION PART//
		if (Boss.RAISE)
		if (((player1.collision(0.0, Boss.mobSprite))&&(healthBar.size() > 0)))
		{
		healthBar.erase(healthBar.begin() + healthBar.size() - 1);
		player1.setStartPos();
		}
		for (int j = 0; j<ciastko.size(); j++)
		{
			for (int i = 0; i<platform.size(); i++)
			{
				ciastko[j].collision(0.0, platform[i].tileMap);
			}
		}
		for (int i = 0; i<platform.size(); i++)
		{
			Boss.collision(0.0, platform[i].tileMap);
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
		for (int i = 0; i<platformBox.size(); i++)
		{
			player1.collision(0.0, platformBox[i].tileMap);
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			if (player1.collision(1.0, martweCiastko[i].mobSprite))
			{
				martweCiastko.erase(martweCiastko.begin() + martweCiastko.size() - 1);
				cakesPkt.increasePkt();
			}
		}
		for (int i = 0; i<martweCiastko.size(); i++)
		{
			if (Boss.collision(1.0, martweCiastko[i].mobSprite))
			{
				martweCiastko.erase(martweCiastko.begin() + martweCiastko.size() - 1);
				Boss.raiseOfLivingCake();
				Boss.changeHP(15);
			}
		}
		for (int i = 0; i<platform.size(); i++)
		{
			player1.arrowCollision(platform[i].tileMap, false);
		}
		for (int i = 0; i<ciastko.size(); i++)
		{
			if ((player1.collision(0.0, ciastko[i].mobSprite)) && (healthBar.size() > 0))
			{
				healthBar.erase(healthBar.begin() + healthBar.size() - 1);
				player1.setStartPos();
			}
		}
		for (int i = 0; i<platformKilling.size(); i++)
		{
			if (player1.collision(0.0, platformKilling[i].tileMap))
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
		if (player1.arrowCollision(Boss.mobSprite, true))
		{
			if ((!Boss.RAISE)&&(Boss.getHP() > 0))
			{
				Boss.RAISE = true;
				player1.changeRespawnPoint();
			}
			Boss.changeHP(-1);
		}
		if (Boss.getHP() < 1)
		{
			Boss.RAISE = false;
			Boss.dyingBoss(dt);
			if (Boss.checkTimer() > 5)
			{
				AndziaWin.setPosPic(player1.getPlayerPos().x);
				window.clear();
				window.draw(AndziaWin);
				window.display();
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
				}
			}
		}
		for (int i = 0; i<platformBox.size(); i++)
		{
			if (player1.arrowCollision(platformBox[i].tileMap, true))
				platformBox.erase(platformBox.begin() + i);
		}
		view.setCenter((player1.getPlayerPos().x + 300), (window.getSize().y / 2));
		window.clear();
		window.setView(view);
		lvl1Background.setPos(player1.getPlayerPos().x);
		cakesPkt.setPos(player1.getPlayerPos().x);
		cakeCounter.setPos(player1.getPlayerPos().x);
		for (int i = 0; i<healthBar.size(); i++)
		{
			healthBar[i].update(dt);
		}
		for (int i = 0; i<healthBar.size(); i++)
		{
			healthBar[i].setPos(player1.getPlayerPos().x, i);
		}
		for (int i = 0; i<ciastko.size(); i++)
		{
			if (ciastko[i].getPos() < 0)
				ciastko.erase(ciastko.begin() + i);
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
		for (int i = 0; i<platformKilling.size(); i++)
		{
			window.draw(platformKilling[i]);
		}
		for (int i = 0; i<platformBox.size(); i++)
		{
			window.draw(platformBox[i]);
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
		if (Boss.isAlive)
		window.draw(Boss);
		player1.drawAmmo(window);
		window.draw(cakeCounter);
		window.draw(cakesPkt);
		for (int i = 0; i<healthBar.size(); i++)
		{
			window.draw(healthBar[i]);
		}
		window.display();
	}
}
