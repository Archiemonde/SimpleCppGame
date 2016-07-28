//#include <SFML/Graphics.hpp>
//#include "ImageBuffer.h"
//using namespace sf;
//int main()
//{
//	RenderWindow window(sf::VideoMode(800, 600,32), "Game window");
//	
//	CircleShape shape(100.f);
//	shape.setFillColor(Color::Blue);
//	ImageBuffer imbuff;
//	while (window.isOpen())
//	{
//		Event event;
//		
//		/*Petla w ktorej obs³ugiwane s¹ wszystkie komunikaty*/
//		while (window.pollEvent(event))
//		{
//			
//			
//			if (event.type == Event::Closed)
//				window.close();
//			else if (event.type == sf::Event::Resized) //nie bedzie skalowac obiektow w oknie podczas skalowania okna
//				window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
//		}
//
//		window.clear();
//		window.draw(shape);
//		
//		Texture texture;
//		texture.loadFromImage(imbuff.getImage("E:\\Studia\\CppGame\\grafiki\\101.png"));
//		Sprite sprite;
//		sprite.setTexture(texture);
//		sprite.setPosition(50, 50);
//		window.draw(sprite);
//		window.display();
//	}
//
//	return 0;
//}