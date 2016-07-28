#pragma once
#include <unordered_map>
#include <iostream>
#include<SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class TextureBuffer {
private:
	std::unordered_map<int, Texture> buffer;
	Texture loadImage(const int &);
public:
	const Texture & getTexture(const int &);
};