#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

using namespace sf;
using namespace std;
class ButtonClass {
public:
	ButtonClass(const std::string &,int =20,int =200,int = 40);
	void setSize(int width, int height);
	void setButton(RenderWindow &);
	void setPosition(int, int);
	void setColor(const Color &);
	void setTextColor(const Color &);
	void setTextSize(const int &);
	int handleClickEvent(int, int);
	void setText(string text);
	~ButtonClass();
private:
	RectangleShape buttonRect;
	Text buttonText;
	Font font;
};