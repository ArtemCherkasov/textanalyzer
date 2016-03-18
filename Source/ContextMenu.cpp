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
		this->window->draw(this->menu);
	}
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

		if (this->text_field->text_line_list.size() > 1){
			int id = this->text_field->getTextLineId();

			//std::cout << this->text_field->text_line_list[2].word_block_list[2].getWord() << std::endl;
			for(int i = id; i < (id + 50); ++i){

				int size_line = this->text_field->text_line_list[i].word_block_list.size();

				for (int j = 0; j < size_line; ++j){
					//std::cout << sizeof(this->text_field->text_line_list[i].word_block_list[j]) << std::endl;
					if (
						this->x >= this->text_field->text_line_list[i].word_block_list[j].getX() &&
						this->x <= (this->text_field->text_line_list[i].word_block_list[j].getX() + this->text_field->text_line_list[i].word_block_list[j].getWidth()) &&
						this->y >= this->text_field->text_line_list[i].word_block_list[j].getY() &&
						this->y <= (this->text_field->text_line_list[i].word_block_list[j].getY() + this->text_field->text_line_list[i].word_block_list[j].getHeigth())
					)
					{
						std::cout << this->text_field->text_line_list[i].word_block_list[j].getWord() << std::endl;
						this->y_above = this->text_field->text_line_list[i].word_block_list[j].getY();
						this->y_belove = this->text_field->text_line_list[i].word_block_list[j].getY() + this->text_field->text_line_list[i].word_block_list[j].getHeigth();
						this->x_left = this->text_field->text_line_list[i].word_block_list[j].getX();
						this->x_right = this->text_field->text_line_list[i].word_block_list[j].getX() + this->text_field->text_line_list[i].word_block_list[j].getWidth();
					}

				}

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
