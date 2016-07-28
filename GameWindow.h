#pragma once
#include"Cell.h"
#include"RenderTools.h"
#include"TextBoxClassh.h"
#include"WorldMap.h"
#include"ProgressBarClass.h"
#include"ButtonClass.h"
#include"Interaction.h"
#include"LabelClass.h"
#include <thread>   
#include <SFML/Graphics.hpp>

class GameWindow {
private:
	TextBoxClass *focused;
	Player *player;
	bool interactionEnabled = 0;
	Interaction interaction;
public:
	wm::WorldMap *worldMap;
	RenderTools rt;
	void checkCollision(ButtonClass& interactionBtn, RenderWindow & window, int dx, int dy);
	void createGameWindow();
	void createMenuWindow();
	//void updateProgressBar(const wm::WorldMap &, ProgressBarClass &);
	~GameWindow();
	void updateProgressBar(ProgressBarClass &);
};