  
/*************************************************************
* File: skip.h
* Author: Oscar Nieto
* Description: This file contains the skip class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
// Clase hija de la clase Item
#ifndef SKIP_H
#define SKIP_H

#include "item.h"

class Skip : public Item {
private:
	unsigned int skip;

public:
	Skip(); //Constructo por default
	Skip(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, unsigned int skip_); // Constructor alterno
	Skip (const Skip&); // Constructor por copia

	unsigned int getSkip() const;// Getter

	void setSkip (unsigned int skip_); // Setter

  std::string toString() const;
};

/*************************************************************
* Implementation of Skip class
*************************************************************/

Skip::Skip()
	: Item(), skip(0) {
}

Skip::Skip(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, unsigned int skip_)
	: Item(nombreItem_, descripcionItem_, itemId_, precioItem_) {
	skip = skip_;
}

Skip::Skip(const Skip &item)
	: Item(item.nombreItem, item.descripcionItem, item.itemId, item.precioItem), 
	  skip(item.skip) {
}

unsigned int Skip::getSkip() const {
	return skip;
}

void Skip::setSkip(unsigned int skip_) {
	skip = skip_;
}


#endif