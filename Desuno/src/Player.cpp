#include "Player.h"

    Player::Player(sf::String F, int x, int y, float w, float h) {
        this->w = w;
        this->h = h;
        image.loadFromFile("sprites\\" + F);
        image.createMaskFromColor(sf::Color(0, 0, 100));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
        sprite.setOrigin(w / 2, h / 2);
        this->x = x;
        this->y = y;
        CurrentFrame = 0;
    }

    void Player::update(float time) {
        switch(direct) {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed;  break;
            case 3: dx = 0; dy = -speed; break;
        }

        x += dx*time;
        y += dy*time;

        speed = 0;
        sprite.setPosition(x, y);

        interactionWithMap();
    }

    float Player::getplayercoordinateX()
    {
        return x;
    }
    float Player::getplayercoordinateY()
    {
        return y;
    }

    void Player::Animation(double time)
    {
        const float v = 0.1;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
            direct = 2;
            speed = v;
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до двух суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 2) CurrentFrame -= 2; // если пришли ко второму кадру - откидываемся назад.
			sprite.setTextureRect(sf::IntRect(24 * int(CurrentFrame), 0, 24, 45)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
            //getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
        } else
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
            direct = 3;
            speed = v;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 2) CurrentFrame -= 2;
            sprite.setTextureRect(sf::IntRect(24 * int(CurrentFrame), 50, 24, 45));
            //getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
        } else
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
            direct = 1;
            speed = v;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            sprite.setTextureRect(sf::IntRect(30 * int(CurrentFrame), 100, 30, 45));
            //getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
        } else
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
            direct = 0;
            speed = v;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            sprite.setTextureRect(sf::IntRect(30 * int(CurrentFrame)+30, 100, -30, 45));
            //getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
        }
        else {
            sprite.setTextureRect(sf::IntRect(51, 0, 26, 45));
        }
    }
    void Player::interactionWithMap() {
        for (int i = y / 100; i < (y + h / 2) / 100; i++){
            for (int j = x / 100; j < (x + w / 2) / 100; j++){
                if ((TileMap[i][j] == '0')||(TileMap[i][j] == 'd')||(TileMap[i][j] == 's')) {
                    if (dy > 0) y = i * 100 - h / 2;
                    if (dy < 0) y = i * 100 + 100;
                    if (dx > 0) x = j * 100 - w / 2;
                    if (dx < 0) x = j * 100 + 100;
                }
            }
        }

    }
    void Player::setMap(char ** TileMap) {
        this->TileMap = TileMap;
    }
    void Player::draw(sf::RenderWindow&window) {
        window.draw(sprite);
    }
    void Player::playerSetPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }
