#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}



 /* RectangleShape rect(Vector2f(30, 15));
            rect.setPosition(iWidth - 30, 0);
            rect.setFillColor(Color::Red);

            RectangleShape sver(Vector2f(window.getSize().x - rect.getSize().x, 15));
            sver.setPosition(0, 0);
            sver.setFillColor(Color::White);


            RectangleShape cloz1;
            cloz1.setSize(Vector2f(rect.getSize().x - rect.getSize().x / 4, rect.getSize().y - 3 * rect.getSize().y / 4));
            cloz1.setFillColor(Color::Black);
            cloz1.setPosition(rect.getPosition().x + rect.getSize().x / 4, rect.getPosition().y);
            cloz1.rotate(30);

            RectangleShape cloz2;
            cloz2.setSize(Vector2f(rect.getSize().x - rect.getSize().x / 4, rect.getSize().y - 3 * rect.getSize().y / 4));
            cloz2.setFillColor(Color::Black);
            cloz2.setPosition(rect.getPosition().x + rect.getSize().x / 4, rect.getPosition().y + 3 * rect.getSize().y / 4);
            cloz2.rotate(330);*/

             /* Vector2i mouse_c = Mouse::getPosition(window);
            if ((mouse_c.x >= rect.getPosition().x)&&(mouse_c.y >= rect.getPosition().y)&&(mouse_c.y <= 15)){
                rect.setFillColor(Color::Blue);
                cloz1.setFillColor(Color::White);
                cloz2.setFillColor(Color::White);
                if (Mouse::isButtonPressed(Mouse::Left)){
                    window.close();
                }
            } else {
                rect.setFillColor(Color::Red);
                cloz1.setFillColor(Color::Black);
                cloz2.setFillColor(Color::Black);

            }
            if ((mouse_c.x >= sver.getPosition().x)&&(mouse_c.x <= sver.getSize().x)&&(mouse_c.y >= sver.getPosition().y)&&(mouse_c.y <= sver.getSize().y)){
                window.setMouseCursorGrabbed(false);
                while (Mouse::isButtonPressed(Mouse::Left)){
                    Vector2i mouse_c2 = Mouse::getPosition(window);
                    mouse_c2.x -= mouse_c.x;
                    mouse_c2.y -= mouse_c.y;
                    window.setPosition(Vector2i(window.getPosition().x + mouse_c2.x, window.getPosition().y + mouse_c2.y));
                }
            }*/


            /* window.draw(rect);
            window.draw(sver);
            window.draw(cloz1);
            window.draw(cloz2);*/
