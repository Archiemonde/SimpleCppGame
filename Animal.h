#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Item.h"
#include<map>
#include<time.h>
#include "Player.h"
//#include"WorldMap.h"
using namespace std;
const int ANIMAL_ID = 500;
class Animal : public MapObject {
private:
	int hp;
	int dmg;
public:
	int iterator;
	Animal(string name, int spriteName, int x, int y, int dmg);
	virtual int Animal::interact(MapObject & player);
	//void Animal::movingThread(WorldMap &worldMap);
	map<string, Item> items;
	int makeDamage();
	int takeDamage(int dmg);
};