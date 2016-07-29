#include "MapObject.h"
using namespace std;
MapObject::MapObject(int objectID, string objectName, int objectSprite, Point coordinates) {
	this->objectID = objectID;
	this->objectName = objectName;
	this->coordinates = Point(coordinates);
	this->sprite = 0;
}

MapObject::MapObject(int objectID, string objectName, int objectSprite, int x, int y, int z) {
	this->objectID = objectID;
	this->objectName = objectName;
	this->coordinates = Point(x, y, z);
	this->sprite = objectSprite;
}
MapObject::~MapObject()
{
}