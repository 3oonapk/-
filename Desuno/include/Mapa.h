#ifndef MAPA_H
#define MAPA_H

#include <ctime>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <cmath>

class Mapa
{
    public:
        Mapa(sf::String path);

        ~Mapa();
        void draw(sf::RenderWindow&window);
        char ** getMapPointer();
        void genLab(int cordi, int cordj);
        void setPlayer(Player &);
        int getWidth();
        int getHeight();
        bool wall(int x, int y);
    private:
        int x;
        int y;
        char ** TileMap;
        char block = '0';
        char floor = ' ';
        char l_palm = 'd';
        char r_palm = 's';
        char oazis = 'o';
        int height;
        int width;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // MAPA_H
