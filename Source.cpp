#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "My first projext", Style::Default,settings);
	CircleShape shape(50.0f, 8);
	shape.setFillColor(Color::Red);
	shape.setPosition(Vector2f(100, 100));
	RectangleShape rectange({ 220.f, 100.f });
	rectange.setFillColor(Color::White);
	rectange.setPosition(Vector2f(100, 100));
	rectange.setOutlineThickness(10);
	rectange.setOutlineColor(Color::Blue);
	rectange.setOrigin(rectange.getSize()/2.0f);
	rectange.setRotation(-45);


	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		
		window.clear(Color::Black);
		window.draw(rectange);
		window.draw(shape);
		window.display();
	}
}
