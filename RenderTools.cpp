#include"RenderTools.h"
#include"Tree.h"
#include"Rock.h"
#include"MapObject.h"
#include<map>
#include"LabelClass.h"
#include"ProgressBarClass.h"
using namespace std;
using namespace sf;
Sprite sprite;
Sprite sprite2;
RenderTools::RenderTools() {
	this->cellsToRender = new Cell *[31];
	for (int i = 0;i < 31;i++) cellsToRender[i] = new Cell[21];
}

void RenderTools::drawPlayerName(RenderWindow &window, const string & playerName) {
	LabelClass playerNameLabel(playerName,40);
	playerNameLabel.setPosition(window.getSize().x/2, 50);
	playerNameLabel.setTextColor(Color(sf::Color::White));
	playerNameLabel.setLabel(window);
}

void RenderTools::drawSprite(RenderWindow &window,const int & imageName,const int & x,const int & y, const int & xChange, const int & yChange) {
	sprite.setTexture(textureBuffer.getTexture(imageName));
	sprite.setPosition(x * 50 +xChange, y * 50+yChange);
	window.draw(sprite);
}
void RenderTools::drawPlayerResourceGraphs(RenderWindow &window, int wood, int rock) {
	//drawSprite(window, 10, window.getSize().x-100, 40);
	//drawSprite(window, 11, window.getSize().x - 100, 80);
	Sprite sprite1;
	sprite1.setTexture(textureBuffer.getTexture(10));
	sprite1.setPosition(window.getSize().x - 120, 0);
	window.draw(sprite1);
	LabelClass woodResourceCounterLabel(to_string(wood), 40);
	woodResourceCounterLabel.setPosition(window.getSize().x - 120, 100);
	woodResourceCounterLabel.setTextColor(Color(sf::Color::White));
	woodResourceCounterLabel.setLabel(window);

	sprite1.setTexture(textureBuffer.getTexture(11));
	sprite1.setPosition(window.getSize().x - 120, 120);
	window.draw(sprite1);
	LabelClass rockResourceCounterLabel(to_string(rock), 40);
	rockResourceCounterLabel.setPosition(window.getSize().x - 120, 220);
	rockResourceCounterLabel.setTextColor(Color(sf::Color::White));
	rockResourceCounterLabel.setLabel(window);
}
void RenderTools::drawHealthBar(RenderWindow &window, float hp) {
	ProgressBarClass healthBar("Health",300, 20);
	healthBar.setPosition(window.getSize().x / 2, window.getSize().y -100);
	healthBar.setTextColor(Color(sf::Color::White));
	healthBar.setProgress(hp);
	healthBar.setProgressBar(window);
}
void RenderTools::paintWorld(RenderWindow &window, const int & x, const int & y) {
	int screenX = 0;
	int screenY = 0;
	try {
		for (int i = 0; i < 31; i++) {
			screenY = 0;
			for (int j = 0; j < 21; j++) {
				if (checkHeight(i, j) == 300) {
					drawSprite(window, 100, screenX, screenY, 0, 0);
				}else{
					drawSprite(window, checkHeight(i, j) + 9, screenX, screenY, 0, 0);
				}
				if (j > 0 && RenderTools::cellsToRender[i][j - 1].getCoordinates().z >RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i, j - 1) + 1, screenX, screenY,0,0);
				}
				if (i<30 && RenderTools::cellsToRender[i + 1][j].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i + 1, j) +2, screenX, screenY, 0, 0);
				}
				if (j<20 && RenderTools::cellsToRender[i][j + 1].getCoordinates().z> RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i, j + 1) + 3, screenX, screenY, 0, 0);
				}
				if (i > 0 && RenderTools::cellsToRender[i - 1][j].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j) +4, screenX, screenY, 0, 0);
				}
				if (i > 0 && j > 0 && RenderTools::cellsToRender[i - 1][j - 1].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j - 1) +5, screenX, screenY, 0, 0);
				}
				if (i<30 && j>0 && RenderTools::cellsToRender[i + 1][j - 1].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z && j > 0) {
					drawSprite(window, checkHeight(i + 1, j - 1) + 6, screenX, screenY, 0, 0);
				}
				if (i<30 && j<20 && RenderTools::cellsToRender[i + 1][j + 1].getCoordinates().z >RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i + 1, j + 1) + 7, screenX, screenY, 0, 0);
				}
				if (i > 0 && j<20 && RenderTools::cellsToRender[i - 1][j + 1].getCoordinates().z> RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j + 1) + 8, screenX, screenY, 0, 0);
				}
				if (!RenderTools::cellsToRender[i][j].getAllObjects().empty())
					for (map<string, MapObject *>::iterator it = cellsToRender[i][j].getAllObjects().begin(); it != RenderTools::cellsToRender[i][j].getAllObjects().end(); it++)
					{
						MapObject *mo = it->second;
						if (mo->objectName == "Tree") {
							sprite2.setTexture(textureBuffer.getTexture(350));
							sprite2.setPosition(screenX * 50 - 30, screenY * 50 - 20);
							window.draw(sprite2);
							sprite2.setTexture(textureBuffer.getTexture(mo->sprite));
							sprite2.setPosition(screenX * 50 -10, screenY * 50 -20);
							window.draw(sprite2);
						}else if (mo->objectName == "Rock") {
							sprite2.setTexture(textureBuffer.getTexture(450));
							sprite2.setPosition(screenX * 50 - 20, screenY * 50 - 10);
							window.draw(sprite2);
							sprite2.setTexture(textureBuffer.getTexture(mo->sprite));
							sprite2.setPosition(screenX * 50 - 10, screenY * 50 - 10);
							window.draw(sprite2);

						}
						else {
							drawSprite(window, mo->sprite, screenX, screenY, 0, 0);
						}
					}
					
				screenY++;
			}
			screenX++;
		}
	}
	catch (out_of_range e) {
		cout<<e.what();
	}
}

int RenderTools::checkHeight(const int & dx, const int & dy) {
	if (RenderTools::cellsToRender[dx][dy].getCoordinates().z >= 17)return 200;
	else if (RenderTools::cellsToRender[dx][dy].getCoordinates().z == 0) return 300;
	else return 100;
}
