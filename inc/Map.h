#ifndef MAP_H
#define MAP_H

#include <string>
#include "TileMap.h"

using namespace std;

namespace Common
{
	class Map
	{
	private:
		TileMap* tilemap;
		int width;
		int height;

	public:
		Map(int width, int height);
		void setWidth(int width);
		void setHeight(int height);
		int getWidth();
		int getHeight();
		string getInfo();
	};
}

#endif
