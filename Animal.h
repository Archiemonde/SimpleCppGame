#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Item.h"
#include<map>
//#include"WorldMap.h"
using namespace std;
const int ANIMAL_ID = 500;
class Animal : public MapObject {
private:

public:
	Animal(string, int, int, int);
	virtual int Animal::interact(MapObject & player);
	//void Animal::movingThread(WorldMap &worldMap);
	map<string, Item> items;
};