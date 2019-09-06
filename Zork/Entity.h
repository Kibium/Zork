#pragma once
#include <string>
#include <list>

using namespace std;

enum Type {
	ROOM,
	ITEM,
	EXIT,
	MONSTER,
	PLAYER
};

class Entity {
public:
	Entity();
	Entity(const char* name, const char* desc, Entity* parent);
	virtual ~Entity();

	Type type;
	string name;
	string desc;
	Entity* parent;
	list<Entity*> container;

	virtual void Update();
};