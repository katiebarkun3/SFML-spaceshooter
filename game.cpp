#include "game.h"
#include "const.h"


Game::Game():
window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_TITLE,
    sf::Style::Titlebar | sf::Style::Close)
{
    window.setVerticalSyncEnabled(true);
    for (size_t i = 0; i < METEORS_QTY; i++) {
        Meteor* meteor = new Meteor();
        meteors.push_back(meteor);
    }
}

void Game::play() {
    while (window.isOpen()) {
        check_events();
        update();
        draw();
}
}
void Game::check_events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }
}
void Game::update() {
    player.update();
    for (size_t i = 0; i < METEORS_QTY; i++) {
        meteors[i]->update();
    }


}
void Game::draw() {
    window.clear(sf::Color::Black);
        player.draw(window);
        for (size_t i = 0; i < METEORS_QTY; i++) {
            meteors[i]->draw(window);
        }
    window.display();
}
