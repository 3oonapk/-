#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <vector>
#include "Mapa.h"
#include "view.h"
#include "Player.h"

using namespace std;
using namespace sf;

int finish = 1;
bool game(RenderWindow&);
void menu(RenderWindow&);
void manualF(RenderWindow&);
int main()
{
     unsigned int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    unsigned int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали
    srand(time(0));
    RenderWindow window(VideoMode(iWidth, iHeight), "Game", Style::Fullscreen);
    window.setFramerateLimit(70);

   while (true)
   {
        switch (finish)
        {
            case 1: menu(window);
            case 2: game(window);
            case 3: manualF(window);
        }
   }
    return 0;
}
void menu(RenderWindow & window)
{
    unsigned int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    unsigned int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали

    View cam;
    cam.setCenter(iWidth / 2, iHeight / 2);
    Texture background, start, exit, manual;
    background.loadFromFile("sprites\\Menu.png");
    start.loadFromFile("sprites\\Start.png");
    exit.loadFromFile("sprites\\Exit.png");
    manual.loadFromFile("sprites\\Manual.png");
    Sprite backgroundS(background);
    Sprite startS(start);
    Sprite exitS(exit);
    Sprite manualS(manual);
    bool isMenu = true;
    int num = 0;
    backgroundS.setPosition(iWidth / 2 - background.getSize().x / 2, 0);
    manualS.setPosition(iWidth / 2 - manual.getSize().x / 2, iHeight / 2 + manual.getSize().y * 2);
    startS.setPosition(iWidth / 2 - start.getSize().x / 2, manualS.getPosition().y - manual.getSize().y);
    exitS.setPosition(iWidth / 2 - exit.getSize().x / 2, manualS.getPosition().y + manual.getSize().y);
    Event event;
    while(window.pollEvent(event))
    {
    while (isMenu)
    {
        num = 0;


        if (IntRect(startS.getPosition().x, startS.getPosition().y, start.getSize().x, start.getSize().y).contains(Mouse::getPosition(window)))
        {
            startS.setColor(Color::Green);
            num = 1;
        }
        else
        {
            startS.setColor(Color::Yellow);
        }
        if (IntRect(exitS.getPosition().x, exitS.getPosition().y, exit.getSize().x, exit.getSize().y).contains(Mouse::getPosition(window)))
        {
            exitS.setColor(Color::Red);
            num = 2;
        }
        else
        {
            exitS.setColor(Color::Yellow);
        }
        if (IntRect(manualS.getPosition().x, manualS.getPosition().y, manual.getSize().x, manual.getSize().y).contains(Mouse::getPosition(window)))
        {
            manualS.setColor(Color::Green);
            num = 3;
        }
        else
        {
            manualS.setColor(Color::Yellow);
        }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (num == 1) {isMenu = false; finish = 2;}
            if (num == 2) {window.close(); isMenu = false;}
            if (num == 3) {isMenu = false; finish = 3;}
        }
        if (event.type == Event::Closed)
                window.close();

        window.setView(cam);
        window.clear();
        window.draw(backgroundS);
        window.draw(startS);
        window.draw(manualS);
        window.draw(exitS);
        window.display();
    }
    }
}
bool game(RenderWindow & window)
{

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            Mapa level("sprites\\Karta.png");   //Создание объекта класса Mapa

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            Player p1("Obrasez2.png", 150, 150, 24, 45);    //Создание объекта класса Player
            p1.setMap(level.getMapPointer());
            level.setPlayer(p1);

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            view.reset(FloatRect(0, 0, 640, 480));

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            Clock clock;

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////




     while (window.isOpen())    //Пока открыто окно
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/1000;


        p1.Animation(time);
        p1.update(time);
        viewmap(time);

        // Проверяем все события, произошедшие в окне
        Event event;
        while (window.pollEvent(event))
        {
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            getPlayerCoordinateForView(p1.getplayercoordinateX(), p1.getplayercoordinateY());
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            finish = 1;
            return false;
        }

            if (event.type == Event::Closed)
                window.close();

            // "close requested" Закрытие окна

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


        }
        if ((p1.getplayercoordinateX() > 100*(level.getWidth() - 2))&&(p1.getplayercoordinateY() > 100*(level.getHeight() - 2)))
        {

            finish = 1;
            return true;
        }
            window.setView(view);
            window.clear();
            level.draw(window);
            p1.draw(window);
            window.display();
    }
}

void manualF(RenderWindow & window)
{
    Event event;
    while (window.pollEvent(event))
    {
    Font font;
    font.loadFromFile("fonts\\16768.otf");

    Text text("'Esc' - go to the Menu\n'Enter' - bring camera to the charachter\n'Arrows' - move camera\n'WASD' - move charachter\n\nGood luck, have fun!", font);
    text.setCharacterSize(20);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::White);
    window.clear();
    window.draw(text);
    if (event.type == Event::Closed)
                window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        finish = 1;
    }
}
