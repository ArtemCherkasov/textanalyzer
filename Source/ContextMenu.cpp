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
}

void ContextMenu::draw(){
	if (visible){
		this->menu.setPosition(sf::Vector2f(this->x, this->y));
		int id = this->text_field->getTextLineId();

		for(int i = id; i < (id + 50); ++i){

			int size_line = this->text_field->text_line_list.size();

			for (int j = 0; j < size_line; ++j){
				if (this->x >= this->text_field->text_line_list[i].word_block_list[j].getX()
						&& this->x <= this->text_field->text_line_list[i].word_block_list[j].getX() + this->text_field->text_line_list[i].word_block_list[j].getWidth()
						&& this->y >= this->text_field->text_line_list[i].word_block_list[j].getY()
						&& this->y <= this->text_field->text_line_list[i].word_block_list[j].getY() + this->text_field->text_line_list[i].word_block_list[j].getHeigth())
				{
					std::string s = this->text_field->text_line_list[i].word_block_list[j].getWord();
					//std::cout << this->text_field->text_line_list[i].word_block_list[j].getWidth() << std::endl;
				}
			}

		}
		this->window->draw(this->menu);
	}
}

void ContextMenu::setCoordinates(int x, int y){
	if (!this->mouse_cliked){
		this->x = x;
		this->y = y;
		this->mouse_cliked = true;

		/*
		for(int i = this->text_field->getTextLineId(); i < (this->text_field->getTextLineId() + 50); ++i){

			int size_line = this->text_field->getTextLineList()[i].word_block_list.size();
			for (int j = 0; j < size_line; ++j){
				std::cout << i << " " << j << std::endl;
				if (this->x >= this->text_field->getTextLineList()[i].word_block_list[j].getX()
						&& this->x <= this->text_field->getTextLineList()[i].word_block_list[j].getX() + this->text_field->getTextLineList()[i].word_block_list[j].getWidth()
						&& this->y >= this->text_field->getTextLineList()[i].word_block_list[j].getY()
						&& this->y <= this->text_field->getTextLineList()[i].word_block_list[j].getY() + this->text_field->getTextLineList()[i].word_block_list[j].getHeigth())
				{

				}


			}
		}*/
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
