
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
using namespace sf;
using namespace std;

Vector2f NormalizeVector(Vector2f vector) {
	float m = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

	Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;
	return normalizedVector;
}

int main() {
	//------------------------INITIALIZE--------------
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1920, 1080), "RPG Game", Style::Default, settings);
	//------------------------INITIALIZE--------------





	//-------------------Calculate direction of the bullet-----------

	//---------------------load--------------------
	// 
	vector<RectangleShape> bullet;
	float bulletspeed = 5.0f;
	//--------------------enemyTexture------------------
	Texture enemyTexture;
	Sprite enemySprite;
	if (enemyTexture.loadFromFile("Assests/enemyPlayer/BODY_skeleton.png")) {
		cout << " enemyPlayer Images Loaded! " << endl;
		enemySprite.setTexture(enemyTexture);
		int XIndex = 0;
		int YIndex = 2;
		enemySprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		enemySprite.scale(Vector2f(2, 2));
		enemySprite.setPosition(Vector2f(400, 300));
	}
	else {
		cout << " enemyPlayer Images Loaded! " << endl;

	}
	//-------------------Player texture--------------
	Texture playerTexture;
	Sprite playerSprite;

	if (playerTexture.loadFromFile("Assests/MainPlayer/BODY_skeleton.png")) {
		cout << " Player Images Loaded! " << endl;
		playerSprite.setTexture(playerTexture);
		int XIndex = 0;
		int YIndex = 0;
		playerSprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(Vector2f(2, 2));
		playerSprite.setPosition(Vector2f(1680, 900));
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

			//bullet.setPosition(bullet.getPosition() + direction*bulletspeed);
			Vector2f position = playerSprite.getPosition();
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				playerSprite.setPosition(position + Vector2f(10, 0));
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				playerSprite.setPosition(position - Vector2f(10, 0));
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				playerSprite.setPosition(position + Vector2f(0, 10));
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				playerSprite.setPosition(position - Vector2f(0, 10));
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				bullet.push_back(RectangleShape(Vector2f(50, 25)));
				bullet[bullet.size() - 1].setPosition(playerSprite.getPosition());
			}

			for (size_t i = 0; i < bullet.size(); i++) {
				Vector2f bulletDirection = enemySprite.getPosition() - bullet[i].getPosition();
				bulletDirection = NormalizeVector(bulletDirection);

				bullet[i].setPosition(bullet[i].getPosition() + bulletDirection * bulletspeed);
			}

			window.clear(Color::Black);
			window.draw(playerSprite);
			window.draw(enemySprite);
			for (size_t i = 0; i < bullet.size(); i++) {
				window.draw(bullet[i]);
			}
			window.display();
		}
	}


}
