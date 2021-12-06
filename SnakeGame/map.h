#pragma once
#include "object.h"

class map : public object{
public: 
	unsigned short width, height;

public:
	map(unsigned short map_width, unsigned short map_Height);
	~map();

	void update();
	void draw();

};

