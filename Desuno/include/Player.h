#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player
{
    public:
        Player(sf::String F, int x, int y, float w, float h);
        void update(float time);
        float getplayercoordinateX();
        float getplayercoordinateY();
        void Animation(double time);
        void interactionWithMap();
        void setMap(char ** TileMap);
        void draw(sf::RenderWindow&window);
        void playerSetPosition(int x, int y);
    protected:

    private:
        char ** TileMap;
        float CurrentFrame;
        float x, y, w, h, dx, dy, speed = 0;
        int direct = 0;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // PLAYER_H
