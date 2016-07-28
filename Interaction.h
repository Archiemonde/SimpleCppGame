#pragma once
#include"Point.h"
#include"MapObject.h"
#include"Player.h"

class Interaction {
public:
	int makeInteraction(Player &player, MapObject &object, int interactionID);
	int makeInteraction(int interactionID);
	void setMapObject(MapObject &object);
	void setPlayer(Player &player);
	MapObject * getMapObject();
private:
	Player *player;
	MapObject *mapObject;
};