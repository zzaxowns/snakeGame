#pragma once
#include <iostream>

class object
{
public:
	enum ObjectType {
		block = 0,
		Thorn,
		player,
		itemp,
		empty
	};

private:
	ObjectType objectType;

	object(ObjectType objType);

	virtual ~object() {};

public:
	ObjectType getObjectType();
};

