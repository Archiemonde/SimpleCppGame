#include"RenderTools.h"
#include"Tree.h"
#include"Rock.h"
#include"MapObject.h"
#include<map>
#include"LabelClass.h"
using namespace std;
using namespace sf;
Sprite sprite;
RenderTools::RenderTools() {
	this->cellsToRender = new Cell *[31];
	for (int i = 0;i < 31;i++) cellsToRender[i] = new Cell[21];
}


void RenderTools::drawSprite(RenderWindow &window,const int & imageName,const int & x,const int & y) {
	sprite.setTexture(textureBuffer.getTexture(imageName));
	sprite.setPosition(x * 50, y * 50);
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
void RenderTools::paintWorld(RenderWindow &window, const int & x, const int & y) {
	int screenX = 0;
	int screenY = 0;
	try {
		for (int i = 0; i < 31; i++) {
			screenY = 0;
			for (int j = 0; j < 21; j++) {
				if (checkHeight(i, j) == 300) {
					drawSprite(window, 100, screenX, screenY);
				}else{
					drawSprite(window, checkHeight(i, j) + 9, screenX, screenY);
				}
				if (j > 0 && RenderTools::cellsToRender[i][j - 1].getCoordinates().z >RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i, j - 1) + 1, screenX, screenY);
				}
				if (i<30 && RenderTools::cellsToRender[i + 1][j].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i + 1, j) +2, screenX, screenY);
				}
				if (j<20 && RenderTools::cellsToRender[i][j + 1].getCoordinates().z> RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i, j + 1) + 3, screenX, screenY);
				}
				if (i > 0 && RenderTools::cellsToRender[i - 1][j].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j) +4, screenX, screenY);
				}
				if (i > 0 && j > 0 && RenderTools::cellsToRender[i - 1][j - 1].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j - 1) +5, screenX, screenY);
				}
				if (i<30 && j>0 && RenderTools::cellsToRender[i + 1][j - 1].getCoordinates().z > RenderTools::cellsToRender[i][j].getCoordinates().z && j > 0) {
					drawSprite(window, checkHeight(i + 1, j - 1) + 6, screenX, screenY);
				}
				if (i<30 && j<20 && RenderTools::cellsToRender[i + 1][j + 1].getCoordinates().z >RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i + 1, j + 1) + 7, screenX, screenY);
				}
				if (i > 0 && j<20 && RenderTools::cellsToRender[i - 1][j + 1].getCoordinates().z> RenderTools::cellsToRender[i][j].getCoordinates().z) {
					drawSprite(window, checkHeight(i - 1, j + 1) + 8, screenX, screenY);
				}
				if (!RenderTools::cellsToRender[i][j].getAllObjects().empty())
					for (map<string, MapObject *>::iterator it = cellsToRender[i][j].getAllObjects().begin(); it != RenderTools::cellsToRender[i][j].getAllObjects().end(); it++)
					{
						MapObject *mo = it->second;
						if (typeid(dynamic_cast<Tree*>(mo)) == typeid(Tree *)) {
							drawSprite(window, mo->sprite, screenX, screenY);
						}
						else if (typeid(dynamic_cast<Rock*>(mo)) == typeid(Rock *)) {
							drawSprite(window, mo->sprite, screenX, screenY);
						}
						else if (typeid(dynamic_cast<Player*>(mo)) == typeid(Player *)) {
							drawSprite(window, mo->sprite, screenX, screenY);
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
