#include"Rock.h"

const std::string Rock::SOUND = "dzwieki\\stone.ogg";
int Rock::loadSoundBuffer = 0;
sf::SoundBuffer Rock::sBuffer;
sf::Sound Rock::sound;

Rock::Rock(string name, int spriteName, int x, int y, int woodCount) :rockCount(woodCount), MapObject(ROCK_ID, name, spriteName, x, y) {
	if (!loadSoundBuffer) {
		loadSoundBuffer = 1;
		if (!sBuffer.loadFromFile(SOUND)) {
			cout << "Error loading Rock sound" << endl;
		}
		sound.setBuffer(sBuffer);
	}
}
int Rock::interact(MapObject & player)
{
	if (rockCount > 0) {
		sound.play();
		progress();
		this->rockCount--;
		cout << rockCount << endl;
		static_cast<Player &>(player).addItem(Item("Rock", "Piece of rock", 1));
		sound.stop();
		return 1;
	}
	else {
		return 0;
	}
}

int Rock::progress() {
	elapsed = 0;
	while (elapsed < 1000) {
		elapsed += 10;
		Sleep(10);
		cout << elapsed << endl;
	}
	return elapsed;
}