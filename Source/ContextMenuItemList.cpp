/*
 * ContextMenuItem.cpp
 *
 *  Created on: 29 марта 2016 г.
 *      Author: artemcherkasov
 */
#include "../Headers/ContextMenuItemList.h"

ContextMenuItemList::ContextMenuItemList(sf::Font *font){
	this->font = *font;
}

void ContextMenuItemList::addItem(std::string item){
	this->item_list.push_back(sf::Text(item, this->font));
}
