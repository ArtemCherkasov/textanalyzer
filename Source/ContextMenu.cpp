/*
 * ContextMenu.cpp
 *
 *  Created on: 17 марта 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/ContextMenu.h"

ContextMenu::ContextMenu(int width, int height, sf::RenderWindow *window, TextField *text_field){
	this->width = width;
	this->height = height;
	this->window = window;
	this->x = 0;
	this->y = 0;
	this->text_field = text_field;
	this->menu.setSize(sf::Vector2f(this->width, this->height));
	this->menu.setFillColor(sf::Color::Yellow);
	file_system = new FileSystem();
	if(!font.loadFromFile(file_system->getCurrentPath() + PATH_TO_FONT)){
			//printf("load font from file is error");
	}
	this->context_menu_list = new ContextMenuItemList(&this->font);
	this->context_menu_list->addItem("File");
	this->context_menu_list->addItem("Save");
}

void ContextMenu::draw(){
	if (visible){
		this->menu.setPosition(sf::Vector2f(this->x, this->y));
		this->window->draw(this->menu);
	}
}

void ContextMenu::setFullDictionary(FullDictionary *fullDictionary) {
	this->fullDictionary = fullDictionary;
}

ContextMenuItemList ContextMenu::getContextMenuList(){
	return *context_menu_list;
}

void ContextMenu::drawSomethingLines(){
	if (visible){
		sf::CircleShape circle;
		circle.setRadius(4.0);
		circle.setPosition(sf::Vector2f(this->x - 4, this->y - 4));
		circle.setFillColor(sf::Color::Green);
		this->window->draw(circle);
		/*
		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(0, this->y_above)),
			sf::Vertex(sf::Vector2f(1024, this->y_above))
		};
		*/
		sf::RectangleShape line;
		line.setPosition(0, this->y_above);
		line.setSize(sf::Vector2f(1024, 2));
		line.setFillColor(sf::Color::Black);
		this->window->draw(line);
		line.setPosition(0, this->y_belove);
		line.setSize(sf::Vector2f(1024, 2));
		line.setFillColor(sf::Color::Black);
		this->window->draw(line);
		line.setPosition(this->x_left, 0);
		line.setSize(sf::Vector2f(2, 768));
		line.setFillColor(sf::Color::Black);
		this->window->draw(line);
		line.setPosition(this->x_right, 0);
		line.setSize(sf::Vector2f(2, 768));
		line.setFillColor(sf::Color::Black);
		this->window->draw(line);
	}
}

void ContextMenu::setCoordinates(int x, int y){
	if (!this->mouse_cliked){
		this->x = x;
		this->y = y;
		this->mouse_cliked = true;

		std::vector<int> range = this->text_field->getRangeForDrawField(this->text_field->getPercent());

		for(int i = range[0]; i < range[1]; ++i){
			if (
					this->x >= this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleX() &&
					this->x <= (this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleX() + this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleWidth()) &&
					this->y >= this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleY() &&
					this->y <= (this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleY() + this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleHeight())
				)
				{
					//std::cout << this->fullDictionary->getOriginalWord(this->text_field->getTextLoader()->getWordBlockList()[i].getWordString()) << std::endl;
					std::cout << this->fullDictionary->getOriginalWord(this->text_field->getTextLoader()->getWordBlockList()[i].getWordString()) << " -> " << this->fullDictionary->getTranslate(this->fullDictionary->getOriginalWord(this->text_field->getTextLoader()->getWordBlockList()[i].getWordString())) << std::endl;
					this->y_above = this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleY();
					this->y_belove = this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleY() + this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleHeight();
					this->x_left = this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleX();
					this->x_right = this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleX() + this->text_field->getTextLoader()->getWordBlockList()[i].getRectangleWidth();
				}
		}

	}

}

void ContextMenu::setVisible(bool visible){
	this->visible = visible;
}

void ContextMenu::setMouseCliked(bool mouse_cliked){
	this->mouse_cliked = mouse_cliked;
}

bool ContextMenu::isClicked(int x, int y){
	return (x >= this->x && x <= this->x+this->width && y >= this->y && y <= this->y + this->height);
}
