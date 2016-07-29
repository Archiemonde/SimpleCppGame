#include "Player.h"
using namespace std;
Player::Player(int id, string playerName, int xPos, int yPos, int sprite):MapObject(id,playerName,sprite, Point(xPos,yPos)){
	this->addItem(Item("Wood", "Chunk of wood", 0));
	this->addItem(Item("Rock", "Piece of rock", 0));
}
Player::Player(): MapObject(0, "default", 0, Point(0, 0)) {

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
int Player::interact(MapObject & player) {
	return 0;
}
