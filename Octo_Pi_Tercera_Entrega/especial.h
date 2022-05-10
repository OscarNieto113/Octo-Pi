  
/*************************************************************
* File: especial.h
* Author: Oscar Nieto
* Description: This file contains the especial class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
// Clase hija de la clase Item
#ifndef ESPECIAL_H
#define ESPECIAL_H

#include "item.h"

class Especial : public Item {
protected:
	std::string especial;

public:
	Especial(); //Constructo por default
	Especial(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, string especial_); // Constructor alterno
	Especial(const Especial&); // Constructor por copia

	string getEspecial() const;// Getter

	void setEspecial (string especial_); // Setter

  std::string toString() const;
};

Especial::Especial()
	: Item(), especial("") {
}

Especial::Especial(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, string especial_)
	: Item(nombreItem_, descripcionItem_, itemId_, precioItem_) {
	especial = especial_;
}

Especial::Especial(const Especial &item)
	: Item(item.nombreItem, item.descripcionItem, item.itemId, item.precioItem), 
	  especial(item.especial) {
}

string Especial::getEspecial() const {
	return especial;
}

void Especial::setEspecial(string especial_) {
	especial = especial_;
}

#endif