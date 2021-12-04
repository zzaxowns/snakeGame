#pragma once
#include <iostream>

using namespace std;

class object
{
	
public:
	int x, y;

	object(int x, int y);

	virtual ~object();

public:
	virtual int getObjectX();
	virtual int getObjectY();
	virtual void update() =0;
	virtual void draw() =0;
};

