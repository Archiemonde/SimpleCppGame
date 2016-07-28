#pragma once
#include"MapObject.h"
#include"Player.h"
#include"Item.h"
const int TREE_ID = 300;
class Tree :public MapObject {
public:
	int woodCount;
	Tree(string, int, int, int, int);
	virtual void interact(Player &);
};