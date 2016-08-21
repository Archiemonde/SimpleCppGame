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

MapObject& Cell::addObject(MapObject *object) {
	try {
		objects->insert(std::pair<const std::string, MapObject *>(object->objectName, object));
	}
	catch (...) {
	}
	return *objects->at(object->objectName);
}

MapObject & Cell::getObject(string objectName) {
	//cout << "returns the object " << this->objects->at(objectName).coordinates.x<<"  "<< this->objects->at(objectName).coordinates.y<< endl;
	try {
		return *this->objects->at(objectName);
	}
	catch (...) {
		if (this->objects->empty()) cout << "ERROR: Cell("<<this->coordinates.x<<", "<< this->coordinates.y <<") objects map is empty!" <<  endl;
		else cout << "Error while getting element from Cell("<<this->coordinates.x<<","<< this->coordinates.y <<")"<<  endl;
	}
}

int Cell::removeObject(string id) {
	try {
		return objects->erase(id);
	}
	catch (...) {
		if (this->objects->empty()) cout << "ERROR: Cell(" << this->coordinates.x << ", " << this->coordinates.y << ") objects map is empty!" << endl;
		else cout << "Error while getting element from Cell(" << this->coordinates.x << "," << this->coordinates.y << ")" << endl;
	}
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