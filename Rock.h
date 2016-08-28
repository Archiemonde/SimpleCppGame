#pragma once
#include"MapObject.h"
#include"Player.h"
#include"Item.h"
#include"SFML\Audio\SoundBuffer.hpp"
#include"SFML\Audio\sound.hpp"

const int ROCK_ID = 400;

class Rock :public MapObject {
private:
	const static string SOUND;
	static sf::SoundBuffer sBuffer;
	static sf::Sound sound;
	static int loadSoundBuffer;
public:
	int rockCount;
	Rock(string, int, int, int, int);
	virtual int interact(MapObject &);
};