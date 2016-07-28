#pragma once
#include"Point.h"
#include"MapObject.h"
#include<vector>
#include<map>
#include<iostream>
/*
That Cell is representation of sector on the WorldMap.
Every sector is capable to contain many MapObjects
Every Cell has its own coords and typeOfTerrain value wchich describes it
*/
class Cell
{
public:
	Cell(const int & = 0,const int & = 0,const int & = 0); //params: (x,y,z)
	Cell(Point); //<param>s: (coords)
	virtual ~Cell();
	Point & getCoordinates(); //returns coordinates of that cell
	map<string, MapObject *> & getAllObjects();
	void addObject(MapObject *object);
	MapObject& getObject(string objectName);
	int contains(const string & objectName);
	int removeObject(string objectName);
private:
	Point coordinates; //coords of specified cell
	map<string, MapObject *> *objects; //objects wchich are on that cell
};