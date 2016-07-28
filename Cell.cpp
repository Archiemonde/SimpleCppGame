#include "Cell.h"
#include"Tree.h"
Cell::Cell(const int & x, const int & y,const int & z):coordinates(x,y,z){
	objects = new map<string,MapObject *>;
}
Cell::Cell(Point coordinates):coordinates(coordinates) {
	objects = new map<string, MapObject *>;
}
Point & Cell::getCoordinates() {
	return coordinates;
}
map<string, MapObject *> & Cell::getAllObjects() {
	return *objects;
}

void Cell::addObject(MapObject *object) {
	objects->insert(std::pair<const std::string, MapObject *>(object->objectName, object));
}

MapObject & Cell::getObject(string objectName) {
	//cout << "returns the object " << this->objects->at(objectName).coordinates.x<<"  "<< this->objects->at(objectName).coordinates.y<< endl;
	return *this->objects->at(objectName);
}

int Cell::removeObject(string id) {
	return objects->erase(id);
}

int Cell::contains(const string & objectName) {
	try {
		this->objects->at(objectName);
		return 1;
	}
	catch(out_of_range e){
		return 0;
	}
}

Cell::~Cell()
{
	delete objects;
}