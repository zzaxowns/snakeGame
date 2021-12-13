#pragma once
#include "command.h"
#include "object.h"

class moveCommand : public command{
public:
	moveCommand();
	~moveCommand();

	void excute();
};

