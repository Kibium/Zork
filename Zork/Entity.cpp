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

void Entity::ChangeParent(Entity* newparent) {
	if (parent != nullptr)
		parent->container.remove(this);

	parent = newparent;

	if (parent != nullptr)
		parent->container.push_back(this);
}

void Entity::DeleteFromList(string s) {
	int aux = 0;
	std::cout << "To delete: " << s << endl;

	for (auto it = container.begin(); it != container.end(); aux++ ) {
		//Entity* e = *it;
		cout << "Found: " << (*it)->name << endl;

		/*if (e->name == s) {
			it = container.erase(it);
		}
		else {
			
			++it; // move the increment to here
		}*/
	}
}

