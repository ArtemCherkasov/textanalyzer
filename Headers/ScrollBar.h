/*
 * ScrollBar.h
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_SCROLLBAR_H_
#define HEADERS_SCROLLBAR_H_

#include "SFML/Graphics.hpp"
#include <iostream>

#define CIRCLE_RADIUS 8

class ScrollBar{
private:
	int width_client;
	int hight;
	int x_shape;
	int y_shape;
	int x_center;
	int y_center;
	int x_delta;
	int y_delta;
	float position_0;
	float position_100;
	int position_procent;
	bool clicked;
	sf::RectangleShape line;
	sf::CircleShape circle;
	sf::RenderWindow *window;
public:
	ScrollBar(int width_client, int higth_client_window, sf::RenderWindow *window);
	void draw();
	bool isPressed(sf::Vector2i position);
	void setPosition(int y);
	bool isClicked();
	void setClicked(bool click);
	void setDelta(int x_delta, int y_delta);
	void setPosition_0(float position);
	void setPosition_100(float position);
	float getPosition_0();
	float getPosition_100();
	int getPositionProcent();
};



#endif /* HEADERS_SCROLLBAR_H_ */
