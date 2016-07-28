#include"TextureBuffer.h"
const std::string filePath("grafiki\\");
Texture TextureBuffer::loadImage(const int & imagePath) {
	Texture texture;
	if (!texture.loadFromFile(filePath+std::to_string(imagePath)+".png")) {
		cout << "Error while loading image: "<<imagePath;
	}
	TextureBuffer::buffer[imagePath] = texture;
	return buffer[imagePath];
}

const Texture & TextureBuffer::getTexture(const int & path) {
	try { 
		return TextureBuffer::buffer.at(path);
	}
	catch (out_of_range e) {
		return loadImage(path);
	}
}