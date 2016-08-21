#include"Animal.h"
Animal::Animal(string name, int spriteName, int x, int y): MapObject(ANIMAL_ID, name, spriteName, x, y) {

}

int Animal::interact(MapObject & player) {
	return 1;
}

//void Animal::movingThread(WorldMap &worldMap) {
//
//}