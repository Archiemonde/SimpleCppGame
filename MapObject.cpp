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
int MapObject::progress() {
	elapsed = 0;
	while (elapsed < 1000) {
		elapsed += 10;
		Sleep(10);
		//cout << elapsed << endl;
	}
	return elapsed;
}

MapObject::~MapObject()
{
}