#pragma once
#include"MapObject.h"
#include"Player.h"
const int ROCK_ID = 400;
class Rock :public MapObject {
public:
	int rockCount;
	Rock(string, int, int, int, int);
	virtual int interact(MapObject &);
};