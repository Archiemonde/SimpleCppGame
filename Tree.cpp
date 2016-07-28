#include"Tree.h"
Tree::Tree(string name, int spriteName, int x, int y, int woodCount) :woodCount(woodCount), MapObject(TREE_ID, name, spriteName, x, y) {
}
void Tree::interact(Player & player)
{
	this->woodCount--;
	player.addItem(Item("Wood", "Chunk of wood", 1));
}
