#include "object.h"


object::object(int x, int y) {
	this->x = x;
	this->y = y;
	cout << "object 持失切" << endl;
}

object::~object() {
	cout << "object 社瑚切" << endl;
}

int object::getObjectX() {
	return x;
}

int object::getObjectY() {
	return y;
}


