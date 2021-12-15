#pragma once
#include "command.h"
#include "object.h"

class moveCommand : public command{

private:
	object* m_moveObejct;
	int dx,dy;
public:
	moveCommand(object* moveObj, int dx, int dy);
	~moveCommand();

	void excute();
};

