#include"LabelClass.h"
#include<iostream>
LabelClass::LabelClass(string text, int textSize):labelText(text) {
	if (!font.loadFromFile("grafiki\\BuxtonSketch.ttf"))
	{
		cout << "Failed to load font file!";
	}
	this->label.setFont(font);
	this->label.setCharacterSize(textSize);
	this->label.setColor(sf::Color::Black);
	this->label.setString(text);
}
void LabelClass::setPosition(int x, int y) {
	this->label.setOrigin(this->label.getGlobalBounds().width / 2, this->label.getGlobalBounds().height / 2);
	this->label.setPosition(x, y);
}
void LabelClass::setTextColor(Color color) {
	this->label.setColor(color);
}
void LabelClass::setText(string text) {
	this->label.setString(text);
	this->label.setOrigin(this->label.getGlobalBounds().width / 2, this->label.getGlobalBounds().height / 2);

}
void LabelClass::setLabel(RenderWindow &window ) {
	window.draw(this->label);
}
void LabelClass::setSize(int size) {
	this->label.setCharacterSize(size);
}