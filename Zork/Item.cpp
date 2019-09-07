#include <iostream>
#include "Item.h"

Item::Item(){}

Item::Item(const char* theName, const char* theDesc, Entity* theParent, ItemType itType, int buyValue, int sellValue) {
	type = ITEM;
	name = theName;
	desc = theDesc;
	theParent->container.push_back(this);
	parent = theParent;
	item_type = itType;

	value = 0;

	buy_value = buyValue;
	sell_value = sellValue;

	
	
}

