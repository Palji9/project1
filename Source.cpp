#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "RPG Game", Style::Default, settings);

	//---------------------load--------------------
	Texture playerTexture;
	Sprite playerSprite;

	if (playerTexture.loadFromFile("Assests/Player/BODY_skeleton.png")) {
		cout << " Player Images Loaded! " << endl;
		playerSprite.setTexture(playerTexture);
		int XIndex=0;
		int YIndex=0;
		playerSprite.setTextureRect(IntRect(XIndex*64,YIndex*64, 64, 64));
		playerSprite.scale(Vector2f(2, 2));
	}
	else {
		cout << " Player Images Loaded! " << endl;

	}

	// game loop
	while (window.isOpen()) {
		//------------------------Update----------------------------
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
			{
				window.close();

				
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				Vector2f position = playerSprite.getPosition();
				playerSprite.setPosition(position + Vector2f(10, 0));
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				Vector2f position = playerSprite.getPosition();
				playerSprite.setPosition(position - Vector2f(10, 0));
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				Vector2f position = playerSprite.getPosition();
				playerSprite.setPosition(position + Vector2f(0, 10));
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				Vector2f position = playerSprite.getPosition();
				playerSprite.setPosition(position - Vector2f(0, 10));
			}
			window.clear(Color::Black);
			window.draw(playerSprite);
			window.display();
		}
	}


}
