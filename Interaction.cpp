#include"Interaction.h"

int Interaction::makeInteraction(Player &player, MapObject &object, int interactionID) {
	switch (interactionID) {
	case 1:
		cout << "interaction!: wood: " << player.items["Wood"].amount << endl;
		cout << "interaction!: rock: " << player.items["Rock"].amount << endl;
		if (this->mapObject->interact(*this->player)) return 1;
		else return 0;
		break;
	}
	return 0;
}
int Interaction::makeInteraction(int interactionID) {
	switch (interactionID) {
	case 1:
		if (this->mapObject->interact(*this->player)) {
			return 1;
		}
		else return 0;
		break;
	}
}
void Interaction::setMapObject(MapObject &object) {
	this->mapObject = &object;
}
void Interaction::setPlayer(Player &player) {
	this->player = &player;
}

MapObject * Interaction::getMapObject() {
	return this->mapObject;
}