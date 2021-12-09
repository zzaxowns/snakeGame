#pragma once
#include <iostream>
#include "object.h"
class snake :public object{

	enum direction {
		left,
		right,
		up,
		down
	};

public:
	snake(int x, int y);
	~snake();

	void update() override;
	void draw() override;
};

