#include "map.h"

map::map(int map_width, int map_Height) :object(x, y)
{
	width = map_width;
	height = map_Height;
}

map::~map()
{
}

void map::update()
{
}

void map::draw()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i == 0 && j == 0 && i == width - 1 || k = height - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}
}
