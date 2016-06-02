#ifndef TILE_H
#define TILE_H

namespace Common
{
	class Tile
	{
	private:
		int x;
		int y;
	public:
		Tile();
		Tile* NextX();
		Tile* PreviousX();
		Tile* NextY();
		Tile* PreviousY();

	};
}

#endif
