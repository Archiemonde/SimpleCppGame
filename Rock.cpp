#include"Rock.h"
#include"Item.h"
Rock::Rock(string name, int spriteName, int x, int y, int woodCount) :rockCount(woodCount), MapObject(ROCK_ID, name, spriteName, x, y) {
}
void Rock::interact(Player & player)
{
	this->rockCount--;
	player.addItem(Item("Rock", "Piece of rock", 1));
}
