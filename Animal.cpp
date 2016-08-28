#include"Animal.h"
Animal::Animal(string name, int spriteName, int x, int y, int dmg): MapObject(ANIMAL_ID, name, spriteName, x, y), hp(100), dmg(dmg) {

}

int Animal::makeDamage() {
	srand(time(NULL));
	return rand() % dmg;
}
int Animal::takeDamage(int dmg) {
	hp -= dmg;
	if (hp > 0) return 0;
	else return 1;
}
int Animal::interact(MapObject & player) {
	if (this->takeDamage(static_cast<Player &>(player).makeDamage()) == 0) {
		cout << this->hp<<endl;
		cout << static_cast<Player &>(player).hp<<endl;
		static_cast<Player &>(player).takeDamage(this->makeDamage());
		return 1;
	}else return 0;
}

//void Animal::movingThread(WorldMap &worldMap) {
//
//}