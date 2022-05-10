/*************************************************************
* File: item.h
* Author: Oscar Eduardo Nieto Espitia
* Description: This file contains the definition of Item class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include<string>
#include <sstream>
using namespace std;

/*La clase PADRE Item contiene los items que se le van a asignar al Jugador
*/
class Item{
  protected:
    string nombreItem;
    string descripcionItem;
    unsigned int itemId;
    unsigned int precioItem;
    

  public:
    Item();//Constructor por default / omision
    Item (string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_); // Constructor alterno
    Item (const Item&); // Constructor de copia

    string getNombreItem();//Getter nombre del Item
    void setNombreItem(string nombreItem_); //Setter del Nombre del Item
    string getDescripcionItem();//Getter de la descripcion del Item
    void setDescripcionItem(string descripcionItem_); //Setter de la descripcion del item
    unsigned int getItemId();//Getter del
    void setItemId(unsigned int itemId_); //Setter del 
    unsigned int getPrecioItem();//Getter del precio del Item
    void setPrecioItem(unsigned int precioItem_); //Setter del precio del item

    std::string toString() const;
};

/*************************************************************
* Implementation of Item class
*************************************************************/

//Constructor Item por omision
Item::Item(){
  nombreItem="";
  itemId=0;
  precioItem=0;
  descripcionItem="";
}

//Constructor Item alterno
Item::Item(string nombreItem_, string descripcionItem_, unsigned int itemId_, unsigned int precioItem_){
  nombreItem=nombreItem_;
  itemId=itemId_;
  precioItem=precioItem_;
  descripcionItem=descripcionItem_;
}

//Constructor Item de copia
Item::Item(const Item &item)
  : nombreItem(item.nombreItem), descripcionItem(item.descripcionItem), itemId(item.itemId), precioItem(item.precioItem){
}

//Getters
unsigned int Item::getItemId(){
  return itemId;
}

unsigned int Item::getPrecioItem(){
  return precioItem;
}

string Item::getNombreItem(){
  return nombreItem;
}

string Item::getDescripcionItem(){
  return descripcionItem;
}

//Setters
void Item::setItemId(unsigned int itemId_){
  itemId=itemId_;
}

void Item::setNombreItem(string nombreItem_){
  nombreItem=nombreItem_;
}

void Item::setDescripcionItem(string descripcionItem_){
  descripcionItem=descripcionItem_;
}

void Item::setPrecioItem(unsigned int precioItem_){
  precioItem=precioItem_;
}

//toString
std::string Item::toString() const {
	std::stringstream aux;

	aux << nombreItem << "," << itemId << "," << descripcionItem << "," << precioItem;
	return aux.str();
}


#endif