#include "object.h"


object::object(int x, int y) {
	this->x = x;
	this->y = y;
	//cout << "object ������" << endl;
}

object::~object() {
	//cout << "object �Ҹ���" << endl;
}

int object::getObjectX() {
	return x;
}

int object::getObjectY() {
	return y;
}

void object::update()
{
}

void object::draw()
{
}


