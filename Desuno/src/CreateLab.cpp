#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "CreateLab.h"

#define pihalf 3.1415926535 / 2

bool Lab::wall(int x, int y)
{
    int col = 0;
    if (x < 1 || x > width - 2 || y < 1 || y > height - 2) return false;
    if (x > 1) if (map[x - 1][y]) col++;
    if (x < width - 2) if (map[x + 1][y]) col++;
    if (y > 1) if (map[x][y - 1]) col++;
    if (y < height - 2) if (map[x][y + 1]) col++;
    return col == 1;
}
void Lab::Step(int x, int y)
{
    map[x][y] = true;
    for (int j = 0; j < 4; j++)
    {
        int angle = rand() % 4;
        for (int i = 0; i < 4; i++)
        {
            if (wall(x + (int)cos(angle * pihalf), y + (int)sin(angle * pihalf)))
            {
                x += (int)cos(angle * pihalf);
                y += (int)sin(angle * pihalf);
                Step(x, y);
                break;
            }
            angle++;
            angle %= 4;
        }
    }
}
bool Lab::GetPoint(int x, int y)
{
    return map[x][y];
}
Lab::Lab(int width, int height)
{
    this->width = width;
    this->height = height;
    map = new bool * [height];
	for (int i = 0; i < height; i++){
        map[i] = new bool[width];
	}
    Step(1, 1);
}
Lab::~Lab()
{
    for (int i = 0; i < width; i++)
    {
        delete[] map[i];
    }
    delete map;
}
