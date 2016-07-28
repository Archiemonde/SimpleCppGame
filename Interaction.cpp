#include"Interaction.h"

void Interaction::makeInteraction(Player &player, MapObject &object, int interactionID) {
	switch (interactionID) {
	case 1:
		//player.addItem(object.getItem());
		break;
	}
}
void Interaction::makeInteraction(int interactionID) {
	switch (interactionID) {
	case 1:
		//this->mapObject->interact(*this->player);
		//this->player->addItem(this->mapObject->getItem());
		break;
	}
}
void Interaction::setMapObject(MapObject &object) {
	this->mapObject = &object;
}
void Interaction::setPlayer(Player &player) {
	this->player = &player;
}