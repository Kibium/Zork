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

Entity* Entity::Find(Entity* entity)
{
	//This supposedly returns the entity we look for

	for (auto it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->name == entity->name)
			return *it;
	}

	return nullptr;
}

