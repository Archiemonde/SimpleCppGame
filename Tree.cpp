#include"Tree.h"
Tree::Tree(string name, int spriteName, int x, int y, int woodCount) :woodCount(woodCount), MapObject(TREE_ID, name, spriteName, x, y) {
}
int Tree::interact(MapObject & player)
{
	if (woodCount > 0) {
		this->woodCount--;
		cout << woodCount << endl;
		static_cast<Player &>(player).addItem(Item("Wood", "Chunk of wood", 1));
		return 1;
	}
	else {
		return 0;
	}
}
