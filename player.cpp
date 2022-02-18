#include "player.h"
#include "const.h"


Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 2 - g_bounds.width/2,
		 WINDOW_HEIGHT - g_bounds.height - 20);
}
void Player::update() {
	sf::Vector2f position = sprite.getPosition();
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		position.x > 0)
		sprite.move(-5.1f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		position.x < WINDOW_WIDTH - g_bounds.width)
		sprite.move(5.1f, 0.f);
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }