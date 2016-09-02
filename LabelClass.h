#pragma once
#include<SFML\Graphics.hpp>
using namespace std;
using namespace sf;
class LabelClass {
private:
	string labelText;
	Font font;
	Text label;
public:
	LabelClass(string, int);
	void setPosition(int, int);
	void setLabel(RenderWindow &);
	void setTextColor(Color);
	void setText(string text);
	void setSize(int size);
};