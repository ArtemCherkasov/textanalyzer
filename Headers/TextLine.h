/*
 * TextLine.h
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_TEXTLINE_H_
#define HEADERS_TEXTLINE_H_

#include <iostream>
#include <vector>
#include <map>
#include "../Headers/WordBlock.h"

class TextLine {
private:
	int id;
	int width_parent;
	int height;
	int width;
	int margin_bottom;
	int space;
	int position_y;
public:
	std::vector<WordBlock> word_block_list;
	int word_block_list_size;
	TextLine(int id, int width, int height, int margin_bottom, int space);
	void addWordBlock(WordBlock word_block);
	int getHeight() const;
	void setHeight(int height);
	int getId() const;
	void setId(int id);
	int getMarginBottom() const;
	void setMarginBottom(int marginBottom);
	int getWidth() const;
	void setWidth(int realWidth);
	int getSpace() const;
	void setSpace(int space);
};


#endif /* HEADERS_TEXTLINE_H_ */
