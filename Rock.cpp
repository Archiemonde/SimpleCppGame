#include"Rock.h"
#include"Item.h"
Rock::Rock(string name, int spriteName, int x, int y, int woodCount) :rockCount(woodCount), MapObject(ROCK_ID, name, spriteName, x, y) {
}
int Rock::interact(MapObject & player)
{
	if (rockCount > 0) {
		this->rockCount--;
		cout << rockCount << endl;
		static_cast<Player &>(player).addItem(Item("Rock", "Piece of rock", 1));
		return 1;
	}
	else {
		return 0;
	}

}
