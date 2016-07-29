#include"ButtonClass.h"
#include<iostream>
ButtonClass::ButtonClass(const string & buttonText,int textSize, int width, int height) {
	this->buttonRect.setSize(sf::Vector2f(width, height));
	this->buttonRect.setOutlineThickness((width + height) / 2 * 0.05);
	this->buttonRect.setFillColor(Color(200, 200, 200,255));
	this->buttonRect.setOutlineColor(Color(180, 180, 180, 255));
	if (!font.loadFromFile("grafiki\\BuxtonSketch.ttf"))
	{
		cout << "Failed to load font file!";
	}
	this->buttonText.setString(String(buttonText));
	this->buttonText.setFont(font);
	this->buttonText.setCharacterSize(textSize);
	this->buttonText.setColor(sf::Color::White);
}
void ButtonClass::setSize(int width, int height) {
	buttonRect.setSize(sf::Vector2f(width, height));
	/*Text should always be at the center of button*/
	this->buttonText.setPosition(
		this->buttonRect.getGlobalBounds().left + this->buttonRect.getGlobalBounds().width / 2,
		this->buttonRect.getGlobalBounds().top + this->buttonRect.getGlobalBounds().height / 2);
}
void ButtonClass::setButton(RenderWindow & window) {
	window.draw(this->buttonRect);
	window.draw(this->buttonText);
}
void ButtonClass::setPosition(int x, int y) {
	this->buttonRect.setOrigin(this->buttonRect.getGlobalBounds().width / 2, this->buttonRect.getGlobalBounds().height / 2);
	this->buttonRect.setPosition(x, y);
	this->buttonText.setOrigin(this->buttonText.getGlobalBounds().width / 2, 0);
	/*Text should always be at the center of button*/
	this->buttonText.setPosition(
		this->buttonRect.getGlobalBounds().left+ this->buttonRect.getGlobalBounds().width/2,
		this->buttonRect.getGlobalBounds().top + this->buttonRect.getGlobalBounds().height/2 -30);
}
void ButtonClass::setColor(const Color & color) {
	this->buttonRect.setFillColor(color);
	this->buttonRect.setOutlineColor(Color(color.r-20, color.g - 20, color.b - 20, color.a));
	
}
void ButtonClass::setTextColor(const Color & color) {
	this->buttonText.setColor(color);
}
void ButtonClass::setTextSize(const int & size) {
	this->buttonText.setCharacterSize(size);
	this->buttonText.setOrigin(this->buttonText.getGlobalBounds().width / 2, this->buttonText.getGlobalBounds().height / 2);
	/*Text should always be at the center of button*/
	this->buttonText.setPosition(
		this->buttonRect.getGlobalBounds().left + this->buttonRect.getGlobalBounds().width / 2,
		this->buttonRect.getGlobalBounds().top + this->buttonRect.getGlobalBounds().height / 2);
}
int ButtonClass::handleClickEvent(int x, int y) {
	if (this->buttonRect.getGlobalBounds().left < x &&
		(this->buttonRect.getGlobalBounds().left + this->buttonRect.getGlobalBounds().width) >= x &&
		this->buttonRect.getGlobalBounds().top < y &&
		(this->buttonRect.getGlobalBounds().top + this->buttonRect.getGlobalBounds().height) >= y) {
		cout << "CLICKED" << this->buttonText.getString().toAnsiString();
		return 1;
	}
	else return 0;
}
void ButtonClass::setText(string text) {
	this->buttonText.setString(text);
	this->buttonText.setOrigin(this->buttonText.getGlobalBounds().width / 2, this->buttonText.getGlobalBounds().height / 2);
	/*Text should always be at the center of button*/
	this->buttonText.setPosition(
		this->buttonRect.getGlobalBounds().left + this->buttonRect.getGlobalBounds().width / 2,
		this->buttonRect.getGlobalBounds().top + this->buttonRect.getGlobalBounds().height / 2);
}
ButtonClass::~ButtonClass() {
}
