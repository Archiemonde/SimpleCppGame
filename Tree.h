#pragma once
#include"MapObject.h"
#include"Player.h"
#include"Item.h"
#include"SFML\Audio\SoundBuffer.hpp"
#include"SFML\Audio\sound.hpp"
using namespace sf;
const int TREE_ID = 300;

class Tree :public MapObject {
private:
	static const string SOUND;
	static sf::SoundBuffer sBuffer;
	static sf::Sound sound;
	static int loadSoundBuffer;
public:
	int woodCount;
	int elapsed = 0;
	Tree(string, int, int, int, int);
	virtual int interact(MapObject &);
	int progress();
};