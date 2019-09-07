#include <iostream>
#include "Item.h"

Item::Item(){}

Item::Item(const char* theName, const char* theDesc, Entity* theParent, ItemType type, int buyValue, int sellValue) {
	name = theName;
	desc = theDesc;
	parent = theParent;
	item_type = type;

	value = 0;

	buy_value = buyValue;
	sell_value = sellValue;

	parent->container.push_back(this);
	
}

