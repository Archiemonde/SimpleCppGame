#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Item.h"
#include<time.h>
#include<map>
#include<thread>
using namespace std;
class Player: public MapObject {
private:
	std::thread *healingThread;
public:
	Player();
	Player(int id, string playerName, int xPos, int yPos, int sprite);
	virtual int Player::interact(MapObject & player);
	virtual void Player::addItem(Item);
	map<string, Item> items;
	int makeDamage();
	int takeDamage(int dmg);
	void autoHealingThread();
	int hp = 100;
	int dmg = 10;
	virtual ~Player();
};