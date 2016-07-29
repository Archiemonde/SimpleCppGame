#pragma once
#include<SFML\Graphics.hpp>
#include"TextureBuffer.h"
#include"Cell.h"
#include"Player.h"
class RenderTools {
public:
	RenderTools();
	Cell **cellsToRender;
	TextureBuffer textureBuffer; //buffer containing all nessecary images used while map rendering
	void drawSprite(sf::RenderWindow &, const int &, const int &, const int &);
	void paintWorld(sf::RenderWindow &, const int &, const int &);
	int checkHeight(const int &, const int &);
	void drawPlayerResourceGraphs(RenderWindow &window, int wood, int rock);
};

