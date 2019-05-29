#include "Mapa.h"
#define pihalf 3.1415926535 / 2
Mapa::Mapa(sf::String path)
{
    srand(time(0));
    x = 150;
    y = 150;

    height = (rand() % 10) + 15;
    width = (rand() % 8) + 15;

    if (height % 2 == 0) height += 1;   //Так как алгоритм генерации лабиринта работает только при нечетных высоте и ширине
    if (width % 2 == 0) width += 1;

    TileMap = new char *[height];           //Выделение памяти под карту
        for (int i = 0; i < height; i++)
        {
            TileMap[i] = new char[width];
        }

        for (int i = 0; i < height; i++)    //Заполнение карты пальмами
        {
            for(int j = 0; j < width; j++)
            {
                TileMap[i][j] = l_palm;
            }
        }
        genLab(1, 1);                       //Генерация лабиринта
        for(int i = 0; i < height; i++)     //Установление границ лабиринта
        {
            for (int j = 0; j < width; j++)
            {
                if ((i == 0)||(i == height - 1)||(j == 0)||(j == width - 1))
                {
                    TileMap[i][j] = block;
                }
            }
        }
        TileMap[height-2][width-2] = oazis;
        if ((TileMap[height-3][width-2] == l_palm)&&(TileMap[height-2][width-3] == l_palm))
        {
            int zakr = rand() % 2;
            switch (zakr)
            {
                case 0: TileMap[height-3][width-2] = floor;
                case 1: TileMap[height-2][width-3] = floor;
            }
        }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

Mapa::~Mapa()
{
    for (int i = 0; i < height; i++)
    {
        delete[] TileMap[i];
    }
    delete[] TileMap;
}

void Mapa::draw(sf::RenderWindow & window)
{
    for(int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            if (TileMap[i][j] == ' ') {sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));}
            if (TileMap[i][j] == 'd') {sprite.setTextureRect(sf::IntRect(100, 0, 100, 100));}
            if (TileMap[i][j] == 's') {sprite.setTextureRect(sf::IntRect(200, 0, 100, 100));}
            if (TileMap[i][j] == '0') {sprite.setTextureRect(sf::IntRect(300, 0, 100, 100));}
            if (TileMap[i][j] == 'o') {sprite.setTextureRect(sf::IntRect(400, 0, 100, 100));}

            sprite.setPosition(j * 100, i * 100);
            window.draw(sprite);

        }
    }
}

char ** Mapa::getMapPointer()
{
    return TileMap;
}
int Mapa::getWidth()
{
    return width;
}
int Mapa::getHeight()
{
    return height;
}

void Mapa::setPlayer(Player & p1)
{
    p1.playerSetPosition(this->x, this->y);
}

bool Mapa::wall(int x, int y)
	{
	    int a = 0;
        if(x != 1){
            if(TileMap[y][x-2] == floor)
                a+=1;
            }
        else a+=1;
        if(y != 1){
            if(TileMap[y-2][x] == floor)
                a+=1;
            }
        else a+=1;
        if(x != width-2){
            if(TileMap[y][x+2] == floor)
                a+=1;
            }
        else a+=1;
        if(y != height-2){
            if(TileMap[y+2][x] == floor)
                a+=1;
            }
        else a+=1;
        if(a == 4)
            return 1;
        else
            return 0;
	}

void Mapa::genLab(int cordi, int cordj)
{
    int x = 1;
    int y = 1;
    int dir;
    int schet = 0;
    while (schet<10000)
    {
        TileMap[y][x] = floor;
        schet++;
        while (1)
        {
            dir = rand() % 4;
            switch (dir)
            {
                case 0: if (y != 1)
                        if (TileMap[y-2][x] == l_palm)
                        {
                            TileMap[y-1][x] = floor;
                            TileMap[y-2][x] = floor;
                            y -= 2;
                        }
                case 1: if(y != height-2)
                        if(TileMap[y+2][x] == l_palm)
                        {
                            TileMap[y+1][x] = floor;
                            TileMap[y+2][x] = floor;
                            y += 2;
                        }
                case 2: if(x != 1)
                        if(TileMap[y][x-2] == l_palm)
                        {
                            TileMap[y][x-1] = floor;
                            TileMap[y][x-2] = floor;
                            x -= 2;
                        }
                case 3: if(x != width-2)
                        if(TileMap[y][x+2] == l_palm)
                        {
                            TileMap[y][x+1] = floor;
                            TileMap[y][x+2] = floor;
                            x += 2;
                        }
            }
            if (wall(x, y))
                break;
        }
        if (wall(x, y))
        do
        {
            x = 2*(rand()%((width - 1)/2)) + 1;
            y = 2*(rand()%((height - 1)/2)) + 1;
        }
        while (TileMap[y][x] != floor);
    }
}
