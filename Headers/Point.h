/*
 * Point.h
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_POINT_H_
#define HEADERS_POINT_H_

class Point {
private:
	int x;
	int y;
public:
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};



#endif /* HEADERS_POINT_H_ */
