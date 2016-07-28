#include"TextBoxClassh.h"
#include<iostream>
TextBoxClass::TextBoxClass(int fontSize, int width, int height, int maxTextLength):maxTextLength(maxTextLength) {
	this->textbox.setSize(sf::Vector2f(width, height));
	this->textbox.setOutlineThickness((width + height) / 2 * 0.03);
	this->textbox.setFillColor(Color(240, 240, 240, 255));
	this->textbox.setOutlineColor(Color(180, 180, 180, 255));
	if (!font.loadFromFile("grafiki\\BuxtonSketch.ttf"))
	{
		cout << "Failed to load font file!";
	}
	this->text.setFont(font);
	this->text.setCharacterSize(fontSize);
	this->text.setColor(sf::Color::Black);
}
/*Sets size of the text box and repositions the text contained in that box*/
void TextBoxClass::setSize(int width, int height) {
	textbox.setSize(sf::Vector2f(width, height));
	/*Text should always be at the center of button*/
	this->text.setPosition(
		this->textbox.getGlobalBounds().left + this->textbox.getGlobalBounds().width / 2,
		this->textbox.getGlobalBounds().top + this->textbox.getGlobalBounds().height / 2);
}
/*Draws a TextBox on given RenderWindow refference*/
void TextBoxClass::setTextBox(RenderWindow & window) {
	window.draw(this->textbox);
	window.draw(this->text);
}
/*Sets the position of whole TextBox (rectangle and contained text)*/
void TextBoxClass::setPosition(int x, int y) {
	this->textbox.setOrigin(this->textbox.getGlobalBounds().width / 2, this->textbox.getGlobalBounds().height / 2);
	this->textbox.setPosition(x, y);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, 0);
	/*Text should always be at the center of button*/
	this->text.setPosition(
		this->textbox.getGlobalBounds().left + this->textbox.getGlobalBounds().width / 2,
		this->textbox.getGlobalBounds().top + this->textbox.getGlobalBounds().height / 2 - 30);
}
/*Sets the color of TextBox rectangle and outline.
Outline color is always 20 pt "darker" than Fill Color*/
void TextBoxClass::setColor(const Color & color) {
	this->textbox.setFillColor(color);
	this->textbox.setOutlineColor(Color(color.r - 20, color.g - 20, color.b - 20, color.a));
}

void TextBoxClass::setTextColor(const Color & color) {
	this->text.setColor(color);
}
/*Sets new text size, keeping track on position in the rectangle*/
void TextBoxClass::setTextSize(const int & size) {
	this->text.setCharacterSize(size);
	this->textbox.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
	/*Text should always be at the center of button*/
	this->text.setPosition(
		this->textbox.getGlobalBounds().left + this->textbox.getGlobalBounds().width / 2,
		this->textbox.getGlobalBounds().top + this->textbox.getGlobalBounds().height / 2);
}
/*Sets the maximum StringLength in TextBox*/
void TextBoxClass::setMaxStringLength(int maxLength) {
	this->maxTextLength = maxLength;
}
/*This event should be used to set the focus on specified TextBox*/
int TextBoxClass::handleClickEvent(int x, int y) {
	if (this->textbox.getGlobalBounds().left<x &&
		(this->textbox.getGlobalBounds().left + this->textbox.getGlobalBounds().width) >= x &&
		this->textbox.getGlobalBounds().top<y &&
		(this->textbox.getGlobalBounds().top + this->textbox.getGlobalBounds().height) >= y) return 1;
	else return 0;
}
/*Returns the actual string content of TextBox*/
string TextBoxClass::getContent() {
	return this->textString;
}
/*Handle the input of text into TextBox, updating the Text rendering entity, repositioning the Text in rectangle, and updating string container*/
void TextBoxClass::enterTextHandler(const Event &event) {
		sf::Uint32 unicode = event.text.unicode;

		if (unicode == '\b' && this->textString.size() > 0)
		{
			this->textString.erase(this->textString.size() - 1, 1);
			text.setString(this->textString);
		}
		else if (((unicode >= 20 && unicode <= 57) || (unicode >= 65 && unicode <= 122)) && this->textString.size() < this->maxTextLength)
		{
			this->textString += static_cast<char>(unicode);
			text.setString(this->textString);
		}
		this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
		/*Text should always be at the center of button*/
		this->text.setPosition(
			this->textbox.getGlobalBounds().left + this->textbox.getGlobalBounds().width / 2,
			this->textbox.getGlobalBounds().top + this->textbox.getGlobalBounds().height / 2);
}