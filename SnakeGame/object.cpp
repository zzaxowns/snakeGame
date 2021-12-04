#include "object.h"


object::object(ObjectType objType) {
	this->objectType = objType;
	
}

object::ObjectType object::getObjectType(){
	return this->objectType;
}

