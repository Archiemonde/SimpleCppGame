#include "WorldMap.h"
WorldMap::WorldMap(int xSize, int ySize, int zSize)
{
	size = Point(xSize, ySize, zSize);
	maxHeight = 0;
	progress = 0.0;
	matrix = new Cell *[xSize];
	for (int i = 0; i < xSize; i++) matrix[i] = new Cell [ySize];
	isMapExists = 1;
}
int WorldMap::create() {
	clock_t begin = clock();
	fillWith(0);
	int count = (int)(this->size.x * this->size.y * 0.33);
	//for (int y = 0;y < size.y;y++) {
	//	for (int x = 0;x < size.x;x++) {
	//		cout << matrix[x][y].getCoordinates().z<<" ";
	//	}
	//	cout << endl;
	//}
	this->placeBedRock((int)sqrt(this->size.x), count, 1, 0);
	for (int i = 0; i < 48; i++) {
		count = (int)(count * 0.92);
		this->randomSeeds((int)sqrt(this->size.x), (i + 2), (i + 1));
		this->growSeeds(count, i + 2, (i + 1));
		this->progress += 0.02;
	}
	placeTrees((int)(size.x*size.y*0.15));
	placeRocks((int)(size.x*size.y*0.15));
	placeMoveable((int)(size.x*size.y*0.01));
	progress = 1.0;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	return 1;
}

/*
Fills whole matrix with Cells defined by argument.
It should be the first "layer" of map before bedRock.
This layer should represent the oceans if
you want to create WorldMap with some continents on it
id - id of fill type
z  - height of cells
*/
void WorldMap::fillWith(int z) {
	if (maxHeight < z) {//checking if the height is greater than notified maxHeight to make sure info about highest level is up to date
		maxHeight = z;
	}
	for (int y = 0; y < size.y; y++) {//filling whole map with one cell type and height
		for (int x = 0; x < size.x; x++) {
			this->matrix[x][y].getCoordinates().z = z;// = Cell(x, y, z);
			this->matrix[x][y].getCoordinates().x = x;
			this->matrix[x][y].getCoordinates().y = y;
		}
	}
	cout << "Done filling the matrix with: " << z << " in Z values";
}

/*
Placing the bedrock seeds and bedrock,
wchich means, this is the lowest terrain and every
other types of terrains shoul be plced on it.
Its not only placing the seeds, but every time it plant a seed
its aslo placing the proper amount of Cells around the seed.
That provides more random shapes of continents, than placing all seeds first
and then placing terains around them.

seeds  - number of seeds wchich have to be placed
count  - number of Cells which needs to be placed around the seeds, it should be around 33% of WorldMap Cells
z      - it is the height of the lowest terrain on the map, like 0 or 1
type   - type of terrain to place, the value determines the type of terrain in game (should be 1 or 2)
onType - type of terrain on which this bed rock needs to be placed, it should be type-1 value
*/
void WorldMap::placeBedRock(int seeds, int count, int z, int onType) {
	srand(time(NULL));
	int seedx;
	int seedy;
	if (maxHeight < z) {//checking if the height is greater than notified maxHeight to make sure info about highest level is up to date
		maxHeight = z;
	}
	int numSeeds = seeds;
	while (seeds > 0) {//setting up seeds
		seedx = rand() % ((int)(size.x * 0.8)) + (int)(size.x * 0.1);
		seedy = rand() % ((int)(size.y * 0.4)) + (int)(size.y * 0.2);
		if (matrix[seedx][seedy].getCoordinates().z == onType) {
			matrix[seedx][seedy].getCoordinates().z = z;
			growSeeds(count / numSeeds, z, onType);
			seeds--;
		}
	}
}

/*
Placing the seeds in random positions of specified type
seeds-number of seeds that needs to be placed
z - the heigth of this tile
type-type of seed for example: "forest", "hills" etc.
onType - on what type of terrain it needs to be placed
*/
void WorldMap::randomSeeds(int seeds, int z, int onType) {
	srand(time(NULL));
	int seedx;
	int seedy;
	if (maxHeight < z) {//checking if the height is greater than notified maxHeight to make sure info about highest level is up to date
		maxHeight = z;
	}
	while (seeds > 0) {//setting up seeds
		seedx = rand() % ((int)(size.x * 0.9)) + (int)(size.x * 0.05);
		seedy = rand() % ((int)(size.y * 0.9)) + (int)(size.y * 0.05);
		if (matrix[seedx][seedy].getCoordinates().z == onType) {
			matrix[seedx][seedy].getCoordinates().z = z;
			seeds--;
		}
	}
}

/**
* Growing the seeds on matrix.
*
* @param count  number of tiles to be filled with some terrain
* @param type type of terrain (height)
* @param z actual height
* @param onType type of terrain on which new terrain should be placed
* @return returns 0 if everything is ok, 1 if there was not enough space to place all
*/
int  WorldMap::growSeeds(int count, int z, int onType) {
	srand(time(NULL));
	int x;
	int y;
	int previousCount = count;
	if (maxHeight < z) { //checking if the height is greater than notified maxHeight to make sure info about highest level is up to date
		maxHeight = z;
	}
	while (count > 0) {
		for (y = 0; y < size.y; y++) {
			for (x = 0; x < size.x; x++) {
				if (matrix[x][y].getCoordinates().z == z && count > 0) { //the previous instance must be the same type and the same height, count needs to be greater than 0
					int way = rand() % 8; //random choosing map cell in neighbour of existing one
										  //cout << way<<"  ";
					switch (way) {//trying to put new map cell
					case 0:
						if (((x - 1) > 0) && ((y - 1) > 0) && (matrix[x - 1][y - 1].getCoordinates().z == onType)) {
							matrix[x - 1][y - 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 1:
						if (((y - 1) > 0) && (matrix[x][y - 1].getCoordinates().z == onType)) {
							matrix[x][y - 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 2:
						if (((x + 1) < (size.x - 1)) && ((y - 1) > 0) && (matrix[x + 1][y - 1].getCoordinates().z == onType)) {
							matrix[x + 1][y - 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 3:
						if (((x + 1) < (size.x - 1)) && (matrix[x + 1][y].getCoordinates().z == onType)) {
							matrix[x + 1][y].getCoordinates().z = z;
							x++;
							count--;
						}
						break;
					case 4:
						if (((x + 1) < (size.x - 1)) && ((y + 1) < (size.y- 1)) && (matrix[x + 1][y + 1].getCoordinates().z == onType)) {
							matrix[x + 1][y + 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 5:
						if (((y + 1) < (size.y - 1)) && (matrix[x][y + 1].getCoordinates().z == onType)) {
							matrix[x][y + 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 6:
						if (((x - 1) > 0) && ((y + 1) < (size.y - 1)) && (matrix[x - 1][y + 1].getCoordinates().z == onType)) {
							matrix[x - 1][y + 1].getCoordinates().z = z;
							count--;
						}
						break;
					case 7:
						if (((x - 1) > 0) && (matrix[x - 1][y].getCoordinates().z== onType)) {
							matrix[x - 1][y].getCoordinates().z = z;
							count--;
						}
						break;
					}
				}
			}
		}
		if (previousCount == count)
			return 1; //there is no more space to place a cell it needs to leave the while loop otherwise it stay there forever
		else previousCount = count; //here its updates the previous count to know how many tiles was placed
	}
	//for (int x = 0; x < this->size.x; x++) {
	//	for (int y = 0; y < this->size.y; y++) {
	//		cout << this->matrix[x][y].getCoordinates().z;
	//	}
	//	cout << endl;
	//}
	return 0;
}

void WorldMap::placePlayer(string playerName,int playerID, Player &player)
{
	srand(time(NULL));
	int x, y;
	while (true) {
		x = rand() % ((int)(size.x * 0.9)) + (int)(size.x * 0.05);
		y = rand() % ((int)(size.y * 0.9)) + (int)(size.y * 0.05);
		if (matrix[x][y].getCoordinates().z != 0 && matrix[x][y].getAllObjects().empty() == true) {
			player = * new Player(playerID, playerName, x, y, playerID);
			matrix[x][y].addObject(&player);
			cout << "Player placed at Cell(" << x << ", " << y << ")" << endl;
			break;	
		}
	}
}

void WorldMap::bringMoveablesToLife() {
	srand(time(NULL));
	while (isMapExists)
		for (int i = 0; i< animals.size(); i++) {
			animals.at(i) = static_cast<Animal*>(&moveObject(animals.at(i), (rand() % 3) - 1, (rand() % 3) - 1));
			Sleep(100);
		}
	Sleep(3000);
}

void WorldMap::placeMoveable(int seeds)
{
	srand(time(NULL));
	int seedx;
	int seedy;
	while (seeds > 0) {
		//cout << seeds << endl;
		seedx = rand() % ((int)(size.x * 0.9)) + (int)(size.x * 0.05);
		seedy = rand() % ((int)(size.y * 0.9)) + (int)(size.y * 0.05);
		if (matrix[seedx][seedy].getCoordinates().z != 0 && matrix[seedx][seedy].getAllObjects().empty() == true) {
			int moveableID = ANIMAL_ID + (rand() % 3);
			string spriteName = to_string(moveableID) + ".png";
			string animalID = "Animal";
			animals.push_back(static_cast<Animal *>(&matrix[seedx][seedy].addObject(new Animal(animalID, moveableID, seedx, seedy))));
			seeds--;
		}
		
	}
	move = new std::thread(&WorldMap::bringMoveablesToLife, this);
	//bringMoveablesToLife();
	cout << "Done setting moveables"<<endl;
}

MapObject& WorldMap::moveObject(MapObject *object, int dx, int dy) {
	if ((dx == 0 && dy == 0)) return *object;
	if((object->objectID != 0))
	if((matrix[object->coordinates.x + dx][object->coordinates.x + dy].getCoordinates().z == 0) || (object->coordinates.x + dx == 0) || (object->coordinates.y + dy == 0)) return *object;
	object->coordinates.x += dx;
	object->coordinates.y += dy;
	int x = object->coordinates.x;
	int y = object->coordinates.y;
	this->matrix[object->coordinates.x][object->coordinates.y].addObject(object);
	*object = this->matrix[object->coordinates.x][object->coordinates.y].getObject(object->objectName);
	this->matrix[object->coordinates.x - dx][object->coordinates.y - dy].removeObject(object->objectName);
	*object = (this->matrix[x][y].getObject(object->objectName));
	return *object;
}

void WorldMap::placeTrees(int seedCount)
{
	srand(time(NULL));
	int seedx;
	int seedy;
	while (seedCount > 0) {
		seedx = rand() % ((int)(size.x * 0.9)) + (int)(size.x * 0.05);
		seedy = rand() % ((int)(size.y * 0.9)) + (int)(size.y * 0.05);
		if (matrix[seedx][seedy].getCoordinates().z != 0 && matrix[seedx][seedy].getAllObjects().size() == 0) {
			int treeID = TREE_ID + rand()%4;
			string spriteName = to_string(treeID) + ".png";
			matrix[seedx][seedy].addObject(new Tree("Tree",treeID,seedx,seedy, (rand() % 10) + 1));
		}
		seedCount--;
	}
	cout<<"Done making trees" << endl;
}
void WorldMap::placeRocks(int seedCount) {
	srand(time(NULL));
	int seedx;
	int seedy;
	while (seedCount > 0) {
		seedx = rand() % ((int)(size.x * 0.9)) + (int)(size.x * 0.05);
		seedy = rand() % ((int)(size.y * 0.9)) + (int)(size.y * 0.05);
		if (matrix[seedx][seedy].getCoordinates().z != 0 && matrix[seedx][seedy].getAllObjects().size() == 0) {
			int rockID = ROCK_ID + rand() % 4;
			matrix[seedx][seedy].addObject(new Rock("Rock", rockID, seedx, seedy, (rand() % 10)+1));
		}
		seedCount--;
	}
	cout << "Done making rocks" << endl;
}
Cell ** WorldMap::getMatrix() {
	return matrix;
}

WorldMap::~WorldMap()
{
	move->join();
	isMapExists = 0;
	for (int i = 0;i < this->size.y;i++) delete [] matrix[i];
	delete[] matrix;
}


/*
Test method
*/
//int WorldMap::main(void) {
//	WorldMap wm = WorldMap(50, 50, 9);
//	wm.fillWith(0);
//	int count = (int)(wm.size.getX() * wm.size.getY() * 0.33);
//	wm.placeBedRock((int)sqrt(wm.size.getX()), count, 1, 0);
//	for (int i = 0; i < 8; i++) {
//		count = (int)(count * 0.92);
//		wm.randomSeeds((int)sqrt(wm.size.getX()), (i + 2), (i + 1));
//		wm.growSeeds(count, i + 2, (i + 1));
//		wm.progress += 0.02;
//	}
//	for (int x = 0; x < wm.size.getX(); x++) {
//		for (int y = 0; y < wm.size.getY(); y++) {
//			cout << wm.getMatrix()[x][y].getCoordinates().getZ() << " ";
//		}
//		cout << "\n";
//	}
//	system("pause");
//	return 0;
//}