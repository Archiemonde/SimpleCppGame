#include"ProgressBarClass.h"
#include<iostream>

ProgressBarClass::ProgressBarClass(string text, int width, int height) {
	this->progressBarShape.setSize(sf::Vector2f(width, height));
	this->progressBar.setSize(sf::Vector2f(0, height));
	this->progressBarShape.setOutlineThickness(3);
	this->progressBarShape.setFillColor(Color(255, 255, 255, 255));
	this->progressBar.setFillColor(Color(220, 0, 0, 255));
	this->progressBarShape.setOutlineColor(Color(180, 180, 180, 255));
	if (!font.loadFromFile("grafiki\\BuxtonSketch.ttf"))
	{
		cout << "Failed to load font file!";
	}
	this->progressText.setFont(font);
	this->progressText.setCharacterSize(height-5);
	this->progressText.setColor(sf::Color::Black);
}

void ProgressBarClass::setSize(int width, int height) {
	progressBarShape.setSize(sf::Vector2f(width, height));
	this->progressBar.setSize(sf::Vector2f(0, height));
	/*Text should always be at the center of button*/
	this->progressText.setCharacterSize(height - 5);
	this->progressText.setPosition(
		this->progressBarShape.getGlobalBounds().left + this->progressBarShape.getGlobalBounds().width / 2,
		this->progressBarShape.getGlobalBounds().top + this->progressBarShape.getGlobalBounds().height / 2);
}

void ProgressBarClass::setProgressBar(RenderWindow & window) {
	window.draw(this->progressBarShape);
	window.draw(this->progressBar);
	window.draw(this->progressText);
	
}

void ProgressBarClass::setPosition(int x, int y) {
	this->progressBarShape.setOrigin(this->progressBarShape.getGlobalBounds().width / 2, this->progressBarShape.getGlobalBounds().height / 2);
	this->progressBarShape.setPosition(x, y);
	this->progressBar.setPosition(this->progressBarShape.getGlobalBounds().left+this->progressBarShape.getOutlineThickness()
		, this->progressBarShape.getGlobalBounds().top + this->progressBarShape.getOutlineThickness());
	this->progressText.setOrigin(this->progressText.getGlobalBounds().width / 2, 0);
	/*Text should always be at the center of button*/
	this->progressText.setPosition(
		this->progressBarShape.getGlobalBounds().left + this->progressBarShape.getGlobalBounds().width / 2,
		this->progressBarShape.getGlobalBounds().top + this->progressBarShape.getGlobalBounds().height / 2 - 30);
}

void ProgressBarClass::setColor(const Color & color) {
	this->progressBarShape.setFillColor(color);
	this->progressBarShape.setOutlineColor(Color(color.r - 50, color.g - 50, color.b - 50, color.a));
}

void ProgressBarClass::setTextColor(const Color & color) {
	this->progressText.setColor(color);
}

void ProgressBarClass::setProgress(float progress) {
	if (progress <= 1.0 && progress>=0.0) {
		//cout << progress<<endl;
		this->progressBar.setSize(sf::Vector2f(this->progressBarShape.getSize().x*progress, this->progressBarShape.getSize().y));
		this->progressBar.setPosition(sf::Vector2f(this->progressBarShape.getGlobalBounds().left +this->progressBarShape.getOutlineThickness(),
			this->progressBarShape.getGlobalBounds().top+ this->progressBarShape.getOutlineThickness()));
	} 
}