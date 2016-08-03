#include"Tree.h"

const std::string Tree::SOUND = "dzwieki\\wood.ogg";
int Tree::loadSoundBuffer = 0;
sf::SoundBuffer Tree::sBuffer;
sf::Sound Tree::sound;

Tree::Tree(string name, int spriteName, int x, int y, int woodCount) :woodCount(woodCount), MapObject(TREE_ID, name, spriteName, x, y) {
	if (!loadSoundBuffer) {
		loadSoundBuffer = 1;
		if (!sBuffer.loadFromFile(SOUND)) {
			cout << "Error loading Tree sound" << endl;
		}
		sound.setBuffer(sBuffer);
	}
}
int Tree::interact(MapObject & player)
{
	if (woodCount > 0) {
		sound.play();
		progress();
		this->woodCount--;
		cout << woodCount << endl;
		static_cast<Player &>(player).addItem(Item("Wood", "Chunk of wood", 1));
		sound.stop();
		return 1;
	}
	else {
		return 0;
	}
}

int Tree::progress() {
	elapsed = 0;
	while (elapsed < 1000) {
		elapsed += 10;
		Sleep(10);
		cout << elapsed << endl;
	}
	return elapsed;
}
