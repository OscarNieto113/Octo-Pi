  
/*************************************************************
* File: pocion.h
* Author: Oscar Nieto
* Description: This file contains the pocion class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
// Clase hija de la clase Item
#ifndef POCION_H
#define POCION_H

#include "item.h"

class Pocion : public Item {
private:
	unsigned int pocion;

public:
	Pocion(); //Constructo por default
	Pocion(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, unsigned int pocion_); // Constructor alterno
	Pocion(const Pocion&); // Constructor por copia

	unsigned int getPocion() const;// Getter

	void setPocion (unsigned int pocion_); // Setter

  std::string toString() const;
};

Pocion::Pocion()
	: Item(), pocion(0) {
}

Pocion::Pocion(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_, unsigned int pocion_)
	: Item(nombreItem_, descripcionItem_, itemId_, precioItem_) {
	pocion = pocion_;
}

Pocion::Pocion(const Pocion &item)
	: Item(item.nombreItem, item.descripcionItem, item.itemId, item.precioItem), 
	  pocion(item.pocion) {
}

unsigned int Pocion::getPocion() const {
	return pocion;
}

void Pocion::setPocion(unsigned int pocion_) {
	pocion = pocion_;
}

std::string Pocion::toString() const {
	std::stringstream aux;

	aux <<"La " << nombreItem << "\n Descripcion: " << descripcionItem << "\nID del Item: " << itemId << ", Precio del Item: " << precioItem << ", Stat: " << pocion;
	return aux.str();
}


#endif