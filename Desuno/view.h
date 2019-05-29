#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

    sf::View view;

    void getPlayerCoordinateForView(float x, float y){
        view.setCenter(x, y);
    }

    void viewmap(float time) {
        if ((Keyboard::isKeyPressed(Keyboard::Down))) {
            view.move(0, 0.3*time);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            view.move(0, -0.3*time);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            view.move(0.3*time, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            view.move(-0.3*time, 0);
        }
    }

#endif // VIEW_H_INCLUDED
