#include <string>
#include "../inc/Map.h"

using namespace std;
using namespace Common;

	Map::Map(int width, int height)
	{
		this->tilemap = new TileMap(width, height);
		return;
	}

	void Map::setWidth(int width)
	{

	}

	void Map::setHeight(int height)
	{

	}

	int Map::getWidth()
	{
		return this->tilemap->GetWidth();
	}

	int Map::getHeight()
	{
		return this->tilemap->GetHeight();
	}

	string Map::getInfo()
	{
		string s;

		s.append("Width: ");
		s.append(std::to_string(this->tilemap->GetWidth()));

		s.append("Height: ");
		s.append(std::to_string(this->tilemap->GetHeight()));

		return s;
	}
