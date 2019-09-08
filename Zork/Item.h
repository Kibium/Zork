#pragma once
#include "Entity.h"

enum ItemType {
	NORMAL,
	CHEST,
	WEAPON,
	ARMOR
	
};

class Item : public Entity {
public:
	Item();
	Item(const char* name, const char* desc, Entity* parent, ItemType type, int buy, int sell);
	~Item()	{}

	void Look();

	//Both damage or armor, depending on the type
	int value;
	bool poison;

	bool can_store;
	bool pickable;

	int buy_value;
	int sell_value;
	ItemType item_type;

};