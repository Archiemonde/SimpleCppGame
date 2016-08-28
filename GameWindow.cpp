#include"GameWindow.h"
using namespace sf;

/*Checks collisions with Trees, Rocks and unable player to walk on water (unless youre Jesus)*/
void GameWindow::checkCollision(ButtonClass& interactionBtn, RenderWindow & window, int dx, int dy) {
	if (worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].contains("Tree")) {
		interactionBtn.setText("Chop wood");
		this->interaction.setMapObject(worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].getObject("Tree"));
		interactionEnabled = 1;
	}
	else if (worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].contains("Rock")) {
		interactionBtn.setText("Chop stone");
		this->interaction.setMapObject(worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].getObject("Rock"));
		interactionEnabled = 1;
	}
	else if (worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].contains("Animal")) {
		interactionBtn.setText("Fight");
		this->interaction.setMapObject(worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].getObject("Animal"));
		interactionEnabled = 1;
	}
	else {
		interactionEnabled = 0;
		if (abs(worldMap->matrix[player->coordinates.x][player->coordinates.y].getCoordinates().z - worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].getCoordinates().z) <10 && worldMap->matrix[player->coordinates.x + dx][player->coordinates.y + dy].getCoordinates().z!=0 && (player->coordinates.x + dx!=0 || player->coordinates.y + dy!=0) || player->objectName == "Jesus")
		player = static_cast<Player*>(&this->worldMap->moveObject(player, dx, dy));
	}
}

void GameWindow::createGameWindow() {
	RenderWindow window(sf::VideoMode(1550, 1050, 32), "Game window");
	window.setFramerateLimit(60);

	this->interaction.setPlayer(*player);
	/*In game GUI elements*/
	ButtonClass interactionBtn("Interact");
	interactionBtn.setSize(200, 50);
	interactionBtn.setColor(Color(200, 200, 200, 255));
	interactionBtn.setTextSize(40);
	interactionBtn.setPosition((window.getSize().x / 2) + 60, (window.getSize().y / 2) - 60);


	/*END of In game GUI elements*/
	while (window.isOpen())
	{
		Event event;

		/*Rendering the world always where the player is (player should be in the center of the screen). 
		If player get to the edge of map it stops moving with the player*/
		int minx = player->coordinates.x - 15;
		int miny = player->coordinates.y - 10;
		int maxx = player->coordinates.x + 15;
		int maxy = player->coordinates.y + 10;

		if (minx<0) minx = 0;
		else if (maxx >= worldMap->size.x) minx = worldMap->size.x - 31;
		if (miny<0) miny = 0;
		else if (maxy >= worldMap->size.y) miny = worldMap->size.y - 21;
		for (int x = 0; x < 31; x++) {
			for (int y = 0; y < 21; y++) {
				rt.cellsToRender[x][y] = this->worldMap->matrix[x + minx][y + miny];
			}
		}
		window.clear();
		this->rt.paintWorld(window, 0, 0);
		this->rt.drawPlayerResourceGraphs(window, player->items.at("Wood").amount, player->items.at("Rock").amount);
		this->rt.drawHealthBar(window, float(player->hp / 100.));
		if (player->hp <= 0) break; //when the player is dead...
		/*Maintaining all the events happened in game window*/
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			/*Moving events*/
			else if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::W:
					checkCollision(interactionBtn, window,0,-1);
					break;
				case sf::Keyboard::D:
					checkCollision(interactionBtn, window,1,0);
					break;
				case sf::Keyboard::S:
					checkCollision(interactionBtn, window,0,1);
					break;
				case sf::Keyboard::A:
					checkCollision(interactionBtn, window,-1,0);
					break;
				}
			}
			//else/* if (event.type == sf::Event::Resized) //nie bedzie skalowac obiektow w oknie podczas skalowania okna
			//window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
		}
		/*If event loop detect player interaction with some object, interactionEnabled flag gets swiched to 1*/
		if (interactionEnabled == 1) {
			interactionBtn.setButton(window);
			if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed && interactionBtn.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
				//if(worldMap->matrix[player->coordinates.x][player->coordinates.y].getObject())
			int deleteFlag = interaction.makeInteraction(1);
			if (deleteFlag == 0) {
				worldMap->matrix[interaction.getMapObject()->coordinates.x][interaction.getMapObject()->coordinates.y].removeObject(interaction.getMapObject()->objectName);
				interactionEnabled = 0;
			}
			}
		}
		window.display();
	}

}

void GameWindow::updateProgressBar(ProgressBarClass & pbc) {
	while (this->worldMap->progress < 1.f) {
		pbc.setProgress(40);//this->worldMap->progress);
	}
}

void GameWindow::createMenuWindow() {
	RenderWindow window(sf::VideoMode(1550, 1050, 32), "Main Menu window");
	window.setFramerateLimit(60);
	/*Loading Background image*/
	Texture background;
	background.loadFromFile("grafiki\\BGImage.png");
	Sprite bgSprite;
	bgSprite.setTexture(background);
	float xscale = 1550.f / float(background.getSize().x);
	float yscale = 1050.f / float(background.getSize().y);
	bgSprite.scale(xscale, yscale);

	/*Join Game button in main menu view*/
	ButtonClass joinGameBtn("Join game");
	joinGameBtn.setSize(200, 100);
	joinGameBtn.setColor(Color(200, 200, 200,255));
	joinGameBtn.setTextSize(40);
	joinGameBtn.setPosition(window.getSize().x/2, window.getSize().y / 2-60);

	/*Create Game button in main menu view*/
	ButtonClass createGameBtn("Create game");
	createGameBtn.setSize(200, 100);
	createGameBtn.setColor(Color(200, 200, 200, 255));
	createGameBtn.setTextSize(40);
	createGameBtn.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 60);

	/*Back to main menu button in all other views read: join game view and create game view*/
	ButtonClass backToMainMenuBtn("Back to menu");
	backToMainMenuBtn.setSize(200, 100);
	backToMainMenuBtn.setColor(Color(200, 200, 200, 255));
	backToMainMenuBtn.setTextSize(40);
	backToMainMenuBtn.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 200);

	/*Join Game button in join game menu, after clicking on that button, all the data from textBoxes
	in that view should be processed and if the game exists and there is a space on server, player should
	join game, and the client application now should send player data to the server, and after that, servr should 
	respond in, sending data needed to render a map*/
	ButtonClass joinGameBtn1("Join game");
	joinGameBtn1.setSize(200, 100);
	joinGameBtn1.setColor(Color(200, 200, 200, 255));
	joinGameBtn1.setTextSize(40);
	joinGameBtn1.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);

	/*Create game button in create game menu. Same thing as in Join Game button but before that, it creates the server and
	generates new map based on data given in text boxes*/
	ButtonClass createGameBtn1("Create game");
	createGameBtn1.setSize(200, 100);
	createGameBtn1.setColor(Color(200, 200, 200, 255));
	createGameBtn1.setTextSize(40);
	createGameBtn1.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);

	/*Player name label in create game menu and join game menu*/
	LabelClass playerNameLabel("Nazwa gracza", 24);
	playerNameLabel.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 150);
	playerNameLabel.setTextColor(Color(sf::Color::White));

	/*Here you can write your player name to identify yourself :)*/
	TextBoxClass playerNameTxt;
	playerNameTxt.setSize(200, 40);
	playerNameTxt.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 100);
	
	/*server name/address label in join game menu*/
	LabelClass serverNameLabel("Adres serwera", 24);
	serverNameLabel.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 50);
	serverNameLabel.setTextColor(Color(sf::Color::White));

	/*server address textBox in join game menu*/
	TextBoxClass serverAddressTxt;
	serverAddressTxt.setSize(200, 40);
	serverAddressTxt.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	/*map size label in create game menu*/
	LabelClass mapSizeLabel("Wielkosc mapy", 24);
	mapSizeLabel.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 50);
	mapSizeLabel.setTextColor(Color(sf::Color::White));

	/*Map size textBox in create game menu*/
	TextBoxClass mapSizeTxt;
	mapSizeTxt.setSize(200, 40);
	mapSizeTxt.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	ProgressBarClass progressBar("progress", 300, 20);
	progressBar.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 300);
	progressBar.setTextColor(Color(sf::Color::White));
	
	/*All windowStates explanation:
	0 - main menu window state
\
1 - join game state
	2 - create game state
	3 - Actual game world rendering state*/
	int windowState = 0;
	
	while (window.isOpen())
	{
		Event event;
		/*Petla w ktorej obs³ugiwane s¹ wszystkie komunikaty*/
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.mouseButton.button == sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				/*Join game button event in main menu*/
				if (windowState == 0 && joinGameBtn.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					windowState = 1;
				}
				/*Create game button in main menu*/
				else if (windowState == 0 && createGameBtn.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					windowState = 2;
				}
				/*Back to main menu buttons from all the menus*/
				else if (windowState == 1 | windowState == 2 && backToMainMenuBtn.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					windowState = 0;
				}
				//sets focus on playerName in join game menu
				else if (windowState == 1 | windowState == 2 && playerNameTxt.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					this->focused = &playerNameTxt;
				}
				//sets focus on server address in join game menu
				else if (windowState == 1 && serverAddressTxt.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					this->focused = &serverAddressTxt;
				}
				//sets focus on mapSize textBox in Create game menu
				else if (windowState == 2 && mapSizeTxt.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					this->focused = &mapSizeTxt;
				}
				//when player click on create game in create game manu to bring game window to life
				else if (windowState == 2 && createGameBtn1.handleClickEvent(event.mouseButton.x, event.mouseButton.y) == 1) {
					cout << "creating a game..." << endl;
					int size = std::stoi(mapSizeTxt.getContent());
					if (size > 30) {
						worldMap = new WorldMap(size, size, 47);
						std::thread t(&WorldMap::create, worldMap);
						player = new Player();
						worldMap->placePlayer(playerNameTxt.getContent(), 0, *player);
						int minx = player->coordinates.x - 15;
						int miny = player->coordinates.y - 10;
						int maxx = player->coordinates.x + 15;
						int maxy = player->coordinates.y + 10;
						if (minx<0) minx = 0;
						else if (maxx >= worldMap->size.x) minx = worldMap->size.x - 31;
						if (miny<0) miny = 0;
						else if (maxy >= worldMap->size.y) miny = worldMap->size.y - 21;
						cout <<"coords of Player: "<< player->coordinates.x <<"  "<< player->coordinates.y<<endl;
						//std::thread t2(&GameWindow::updateProgressBar, this,progressBar);
						//t2.join();
						t.join();
						cout << "map created..."<<endl;
						for (int x = 0;x < 31;x++) {
							for (int y = 0;y < 21;y++) {
								rt.cellsToRender[x][y] = this->worldMap->matrix[x+minx][y+miny];
							}
						}
						//this->createGameWindow();
						std::thread t3(&GameWindow::createGameWindow,this);
						window.close();
						t3.join();
					}
					else {
						this->worldMap = new WorldMap(100, 100, 47);
						this->worldMap->create();
						for (int x = 0;x < 31;x++) {
							for (int y = 0;y < 21;y++) {
								rt.cellsToRender[x][y] = this->worldMap->matrix[x + 30][y + 30];
							}
						}
						//this->createGameWindow();
						//std::thread t4(&GameWindow::createGameWindow, this, this);
					}
				}
				//join game button event in join game menu
				else if (windowState == 1 && joinGameBtn1.handleClickEvent(event.mouseButton.x, event.mouseButton.y ==1)) {

				}
				//create game button in create game menu
				
				else{
					//this->focused = NULL; //cos tu nie dziala, gdy proboje wpisac a do textboxa, warunek handleClickEvent nie dziala(??)
				}
							
			}
			else if(event.type == Event::TextEntered)
			{
				if(focused!=NULL)
				this->focused->enterTextHandler(event);
			}
			else if (event.type == sf::Event::Resized) {

			}//nie bedzie skalowac obiektow w oknie podczas skalowania okna
			//window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
		}
		if (windowState == 0) {
			window.clear();
			window.draw(bgSprite);
			joinGameBtn.setButton(window);
			createGameBtn.setButton(window);
		}
		else if (windowState == 1) {
			window.clear();
			window.draw(bgSprite);
			joinGameBtn1.setButton(window);
			playerNameLabel.setLabel(window);
			playerNameTxt.setTextBox(window);
			serverNameLabel.setLabel(window);
			serverAddressTxt.setTextBox(window);
			backToMainMenuBtn.setButton(window);
		}
		else if (windowState == 2) {
			window.clear();
			window.draw(bgSprite);
			playerNameLabel.setLabel(window);
			playerNameTxt.setTextBox(window);
			mapSizeLabel.setLabel(window);
			mapSizeTxt.setTextBox(window);
			createGameBtn1.setButton(window);
			backToMainMenuBtn.setButton(window);
			progressBar.setProgressBar(window);
			
		}
		window.display();
	}
}

GameWindow::~GameWindow() {
	delete this->worldMap;
}
/*just a test method*/
void main() {
	//wm::WorldMap wm(100,100,47);
	//wm.create();
	//cout << a.getCoordinates().x<<"  "<<b.getCoordinates().x;
	GameWindow gw;
	std::thread mainThread(&GameWindow::createMenuWindow,gw);
	mainThread.join();

	system("pause");
}
