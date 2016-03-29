/*
 * ContextMenuItem.h
 *
 *  Created on: 29 марта 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_CONTEXTMENUITEMLIST_H_
#define HEADERS_CONTEXTMENUITEMLIST_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

class ContextMenuItemList{
private:
	std::vector<sf::Text> item_list;
	sf::Font font;
public:
	ContextMenuItemList(sf::Font *font);
	void addItem(std::string item);
};

#endif /* HEADERS_CONTEXTMENUITEMLIST_H_ */
