#include "../inc/TileMap.h"

using namespace std;
using namespace Common;

TileMap::TileMap(int width, int height)
{
	this->sizeX = width;
	this->sizeY = height;

	this->tiles = new Tile*[this->sizeX]();

	for (int i = 0; i < this->sizeX; ++i)
	{
		this->tiles[i] = new Tile[this->sizeY]();
	}
}

int TileMap::GetWidth()
{
	return this->sizeX;
}


int TileMap::GetHeight()
{
	return this->sizeY;
}
