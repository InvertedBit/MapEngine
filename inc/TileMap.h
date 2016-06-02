#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

namespace Common
{
	class TileMap
	{
	private:
		Tile** tiles;
		int sizeX;
		int sizeY;

	public:
		TileMap(int sizeX, int sizeY);
		int GetWidth();
		int GetHeight();
	};
}

#endif
