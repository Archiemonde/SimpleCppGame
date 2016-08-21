#pragma once
#include"Cell.h"
#include"Player.h"
#include"MapObject.h"
#include<map>
#include<vector>
#include<time.h>
#include"Tree.h"
#include"Rock.h"
#include"Animal.h"
#include<thread>
	class WorldMap
	{
	public:
		WorldMap(int xSize, int ySize, int zSize = 0);
		int create();
		Cell ** getMatrix();
		Cell **matrix;
		Point size;
		int maxHeight;
		double progress;
		std::map<int, Player> players;
		/*places the player on random position on the map*/
		void WorldMap::placePlayer(string, int, Player &player);
		MapObject& WorldMap::moveObject(MapObject *object, int dx, int dy);
		//MapObject& wm::WorldMap::moveObject(MapObject &object, int dx, int dy);
		virtual ~WorldMap();
	private:
		void WorldMap::placeMoveable(int seeds);
		void WorldMap::placeRocks(int);
		void WorldMap::placeTrees(int);
		/*
		seeds - number of seeds wchich have to be placed
		count - number of Cells which needs to be placed around the seeds, it should be around 33 % of WorldMap Cells
		z - height of the lowest terrain on the map
		type - type of terrain to place, the value should be like "2" or "1" for easier iteration
		onType - type of terrain on which this bed rock needs to be placed, method would be helpfull
		*/
		void WorldMap::placeBedRock(int seeds, int cellsAround, int z, int ontype);
		/*
		Placing the seeds in random positions of specified type
		seeds-number of seeds that needs to be placed
		z- the heigth of this tile
		type-type of seed for example: "forest", "hills" etc.
		onType - on what type of terrain it needs to be placed
		*/
		void randomSeeds(int seeds, int z, int onType);
		int growSeeds(int count, int z, int onType);
		void fillWith(int = 0);
		void WorldMap::bringMoveablesToLife();
		int WorldMap::main(void);
		vector<Animal *> animals;
		std::thread *move;
		int isMapExists = 0;
	};
