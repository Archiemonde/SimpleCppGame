#pragma once
#include"Point.h"
#include<string>
#include"Item.h"
#include "Point.h"
#include <windows.h>
using namespace std;

class MapObject
{
public:
	MapObject(int objectID, string objectName, int objectSprite, Point coordinates);
	MapObject(int objectID, string objectName, int objectSprite, int x, int y, int = 0);
	virtual ~MapObject();
	virtual int interact(MapObject & player)=0;
	string objectName;
	int sprite;
	int objectID;
	Point coordinates;
	int progress();
	int elapsed = 0;
};