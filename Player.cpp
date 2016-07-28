#include "Player.h"
using namespace std;
Player::Player(int id, string playerName, int xPos, int yPos, int sprite):MapObject(id,playerName,sprite, Point(xPos,yPos)){

}
Player::Player(): MapObject(0, "default", 0, Point(0, 0)) {

}

void Player::addItem(Item item) {
	if (items.count(item.name) > 0) items[item.name].amount + item.amount;
	else items[item.name] = item;
}
void Player::interact(Player & player) {

}

Item Player::getItem() {
	return Item("def", "def", 0);
}