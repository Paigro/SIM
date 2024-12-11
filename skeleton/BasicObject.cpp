#include "BasicObject.h"

BasicObject::BasicObject()
{

}

BasicObject::~BasicObject()
{

}

bool BasicObject::update(float t)
{
	return true;
}

void BasicObject::setActive(bool act)
{
	isActive = act;
}
