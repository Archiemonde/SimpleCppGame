#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Item.h"
#include<map>
using namespace std;
class Player: public MapObject {
private:
	
public:
	Player();
	Player(int, string, int, int, int);
	virtual int Player::interact(MapObject & player);
	virtual void Player::addItem(Item);
	map<string, Item> items;
};