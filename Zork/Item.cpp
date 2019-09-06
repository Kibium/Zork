#include <iostream>
#include "Item.h"

Item::Item(const char* theName, const char* theDesc, Entity* theParent, ItemType type, int buyValue, int sellValue) {
	name = theName;
	desc = theDesc;
	parent = theParent;
	item_type = type;

	buy_value = buyValue;
	sell_value = sellValue;
	
}

