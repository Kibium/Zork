#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(const char* theName, const char* theDesc, Entity* theParent) {
	name = theName;
	desc = theDesc;
	parent = theParent;
}

Entity::~Entity() {

}


void Entity::Update() {

}

