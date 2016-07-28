#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Player.h"

class Interaction {
public:
	void makeInteraction(Player &player, MapObject &object, int interactionID);
	void makeInteraction(int interactionID);
	void setMapObject(MapObject &object);
	void setPlayer(Player &player);
private:
	Player *player;
	MapObject *mapObject;
};