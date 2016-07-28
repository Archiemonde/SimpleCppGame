#pragma once

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

using namespace sf;
using namespace std;

class ProgressBarClass {
private:
	RectangleShape progressBarShape;
	RectangleShape progressBar;
	Text progressText;
	Font font;
	int progress;
public:
	ProgressBarClass(string ="", int =200, int =20);
	void setSize(int width, int height);
	void setProgressBar(RenderWindow &);
	void setPosition(int, int);
	void setColor(const Color &);
	void setTextColor(const Color &);
	void setProgress(float);
};