#pragma once
#include <conio.h>
#include "object.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class input : public object
{
public:
	input(int x, int y);
	~input();

public:
	void update() override;
	void draw() override;
};

