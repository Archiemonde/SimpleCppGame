#pragma once
#include<SFML\Graphics.hpp>
using namespace std;
using namespace sf;
class TextBoxClass {
private:
	std::string textString="";
	RectangleShape textbox;
	Text text;
	Font font;
	int maxTextLength;
public:
	TextBoxClass(int = 20, int = 250, int = 40, int =32);
	void setSize(int width, int height);
	void setTextBox(RenderWindow &);
	void setPosition(int, int);
	void setColor(const Color &);
	void setTextColor(const Color &);
	void setTextSize(const int &);
	void setMaxStringLength(int);
	void enterTextHandler(const Event &);
	int handleClickEvent(int, int);
	std::string getContent();

};