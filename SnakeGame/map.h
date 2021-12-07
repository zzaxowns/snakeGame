#pragma once
#include "object.h"

class map : public object{
public: 
	int width, height;

public:
	map(int map_width, int map_Height, int x, int y);
	~map();

	void update();
	void draw();

};

