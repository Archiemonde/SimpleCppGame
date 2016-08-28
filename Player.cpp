#include "Player.h"
using namespace std;
Player::Player(int id, string playerName, int xPos, int yPos, int sprite):MapObject(id,playerName,sprite, Point(xPos,yPos)){
	this->addItem(Item("Wood", "Chunk of wood", 0));
	this->addItem(Item("Rock", "Piece of rock", 0));
	//this->addItem(Item("Pelt", "Sheet of Leather", 0));
	this->healingThread = new std::thread(&Player::autoHealingThread, this);
}
Player::Player(): MapObject(0, "default", 0, Point(0, 0)) {
	this->addItem(Item("Wood", "Chunk of wood", 0));
	this->addItem(Item("Rock", "Piece of rock", 0));
	//this->addItem(Item("Pelt", "Sheet of Leather", 0));
	this->healingThread = new std::thread(&Player::autoHealingThread, this);
}

void Player::addItem(Item item) {
	if (items.count(item.name) > 0) {
		Item * it = &this->items[item.name];
		it->amount += 1;
	}
	else {
		items[item.name] = item;
	}
}
int Player::makeDamage() {
	srand(time(NULL));
	return  rand() % dmg;
}
int Player::takeDamage(int dmg) {
	hp -= dmg;
	if (hp > 0) return 0;
	else return 1;
}
int Player::interact(MapObject & player) {
	return 0;
}

void Player::autoHealingThread() {
	while (hp > 0) {
		if (hp < 100) {
			progress();
			hp++;
			cout << hp << endl;
		}
	}
}

Player::~Player() {
	this->healingThread->join();
}
