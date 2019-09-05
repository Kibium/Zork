#pragma once
#include "Entity.h"

enum ItemType {
	NORMAL,
	WEAPON,
	ARMOR
	
};

class Item : public Entity {
public:
	Item(const char* name, const char* desc, Entity* parent, ItemType type);
	Item(const char* name, const char* desc, Entity* parent, ItemType type, int buy, int sell);
	~Item()	{}

	void Look();
	
	int buy_value;
	int sell_value;
	ItemType item_type;
};