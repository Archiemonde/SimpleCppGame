#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Item.h"
#include<map>
using namespace std;
class Player: public MapObject {
private:
	map<string,Item> items;
public:
	Player();
	Player(int, string, int, int, int);
	virtual void Player::interact(Player & player);
	virtual void Player::addItem(Item);
	virtual Item Player::getItem();
};