#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

enum Type {
	ROOM,
	ITEM,
	EXIT,
	DOOR,
	CREATURE,
	PLAYER
};

class Entity {
public:
	Entity();
	Entity(const char*, const char*, Entity*);
	virtual ~Entity();

	friend bool operator == (Entity const &e, Entity const &ww) {
		
		return e.name == ww.name;
	}

	Entity* Find(Entity* entity);

	Type type;
	string name;
	string desc;
	Entity* parent;
	list<Entity*> container;

	virtual void Update();
	void DeleteFromList(string);
	void ChangeParent(Entity* newParent);
};