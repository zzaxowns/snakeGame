#pragma once
#include "command.h"
#include "object.h"

class moveCommand : public command{

private:
	object* m_moveObejct;

public:
	moveCommand(object* moveObj);
	~moveCommand();

	void excute();
};

