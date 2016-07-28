#pragma once
#include"Point.h"
#include<string>
#include"Item.h"
#include "Point.h"
using namespace std;

class MapObject
{
public:
	MapObject(int, string, int, Point);
	MapObject(int, string, int, int, int, int = 0);
	virtual ~MapObject();
	//virtual void interact(Player & player)=0;
	string objectName;
	int sprite;
	int objectID;
	Point coordinates;
};