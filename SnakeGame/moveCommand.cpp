#include "moveCommand.h"

moveCommand::moveCommand(object* moveObj, int dx, int dy)
{
	m_moveObejct = moveObj;
	this->dx = dx;
	this->dy = dy;
}

moveCommand::~moveCommand()
{
}

void moveCommand::excute(){
	m_moveObejct->x += dx;
	m_moveObejct->y += dy;
}
