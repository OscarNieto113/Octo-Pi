/*************************************************************
* File: Jugador.h
* Author: Oscar Eduardo Nieto Espitia
* Description: This file contains the definition of Jugador class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include<string>
#include <sstream>
#include "habilidad.h"
#include "item.h"
using namespace std;

/*Clase Jugador*/

const int MAX=5;

class Jugador{
  private:
    Item** items; //Array de apuntadores del objeto item
    Habilidad** habilidades; //Array de apuntadores del objeto habilidad

    string nombre;
    unsigned int jugadorId;
    unsigned int vida;
    unsigned int maxVida;
    unsigned int experiencia;
    unsigned int mora;
    unsigned int respuestasCorrectas;
    unsigned int maxRespuestasCorrectas;
    unsigned int current;
    unsigned int max;

    long indexOfHabilidad (unsigned int) const;
    long indexOfItem (unsigned int) const;

  public:
    Jugador();//Constructor por default / omision
    Jugador (string nombre_, unsigned int jugadorId_, unsigned int vida_, unsigned int maxVida_, unsigned int experiencia_, unsigned int mora_, unsigned int respuestasCorrectas_, unsigned int maxRespuestasCorrectas, unsigned int max_, unsigned int current_); // Constructor alterno
    Jugador (const Jugador&); // Constructor de copia

    ~Jugador(); //Destructor

    Item* getItems(unsigned int ItemId_) const;
  	void addItem (Item*);
  	bool removeItemById(unsigned int itemId_);

    Habilidad* getHabilidad(unsigned int habilidadId_) const;
  	void addHabilidad (Habilidad*);
  	bool removeHabilidadById(unsigned int habilidadId_);

    string getNombre();//Getter nombre del Jugador
    void setNombre(string nombre_); //Setter del Nombre del Jugador
    unsigned int getJugadorId();//Getter del Jugador Id
    void setJugadorId(unsigned int jugadorId_); //Setter del Jugador Id
    unsigned int getVida();//Getter de la vida del jugador
    void setVida(unsigned int vida_); //Setter de la vida del jugador
    unsigned int getMaxVida();//Getter de la vida maxima del jugador
    void setMaxVida(unsigned int maxVida_); //Setter de la vida maxima del jugador
    unsigned int getExperiencia();//Getter de la experiencia del jugador
    void setExperiencia(unsigned int experiencia_); //Setter de la experiencia del Jugador
    unsigned int getMora();//Getter del deinero del jugador
    void setMora(unsigned int mora_); //Setter del dinero del jugador
    unsigned int getRespuestasCorrectas();//Getter de las respuestas correctas del jugador
    void setRespuestasCorrectas(unsigned int respuestasCorrectas_); //Setter dede las respuestas correctas del jugador
    unsigned int getMaxRespuestasCorrectas();//Getter del maximo de respuestas correctas del jugador
    void setMaxRespuestasCorrectas(unsigned int maxRespuestasCorrectas_); //Setter del maximo de respuestas correctas  del jugador
    unsigned int getCurrent(); //Getter del numero de objetos en el inventario
    void setCurrent(unsigned int current_); //Setter del numero de objetos del inventario
    unsigned int getMax();//Getter del maximo de items y habilidades
    void setMax(unsigned int max_); //Setter de items y habilidades

    std::string toString() const;

    /*
    void clearItems ();
    void clearHabilidades();
    bool load(string);
    bool save(string) const;
    */
};

#endif

Jugador::Jugador(){
  nombre="";
  jugadorId=0;
  vida=0;
  maxVida=0;
  experiencia=0;
  mora=0;
  respuestasCorrectas=0;
  maxRespuestasCorrectas=0;
  max=MAX;
  current=0;

  items = new Item*[max];
  habilidades = new Habilidad*[max];
}

Jugador::Jugador (string nombre_, unsigned int jugadorId_, unsigned int vida_, unsigned int maxVida_, unsigned int experiencia_, unsigned int mora_, unsigned int respuestasCorrectas_, unsigned int maxRespuestasCorrectas_, unsigned int max_, unsigned int current_){// Constructor alterno
  nombre=nombre_;
  jugadorId=jugadorId_;
  vida=vida_;
  maxVida=maxVida_;
  experiencia=experiencia_;
  mora=mora_;
  respuestasCorrectas=respuestasCorrectas_;
  maxRespuestasCorrectas=maxRespuestasCorrectas_;
  max=max_;
  current=current_;

  items = new Item*[max];
  habilidades = new Habilidad*[max];
} 

Jugador::Jugador (const Jugador &j){// Constructor de copia
  nombre=j.nombre;
  jugadorId=j.jugadorId;
  vida=j.vida;
  maxVida=j.maxVida;
  experiencia=j.experiencia;
  mora=j.mora;
  respuestasCorrectas=j.respuestasCorrectas;
  maxRespuestasCorrectas=j.maxRespuestasCorrectas;
  current=j.current;
  max=j.max;

  items = new Item*[max];
  for (int i = 0; i < current; i++) {
    items[i] = new Item ((*j.items[i]));
  }

  habilidades = new Habilidad*[max];
  for (int i=0; i<current; i++){
    habilidades[i] = new Habilidad ((*j.habilidades[i]));
  }
} 

Jugador::~Jugador(){//Destructor de habilidades e items
  for (int i = 0; i < current; i++) {
		delete items[i];
	}
	delete [] items;

  for (int i = 0; i < current; i++) {
		delete habilidades[i];
	}
	delete [] habilidades;
} 

long Jugador::indexOfItem(unsigned int itemId) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (items[i]->getItemId() == itemId) {
			pos = i;
			break;
		}
	}
	return pos;
}

long Jugador::indexOfHabilidad(unsigned int habilidadId) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (habilidades[i]->getHabilidadId() == habilidadId) {
			pos = i;
			break;
		}
	}
	return pos;
}

Item* Jugador::getItems(unsigned int itemId) const{// Getter de los items, apuntadores
	long pos;
	pos = indexOfItem(itemId);
	if (pos == -1) {
		return NULL;
	} else {
		return items[pos];
	}
};

void Jugador::addItem (Item *it){
  long pos;
	pos = indexOfItem(it->getItemId());

	if (pos == -1) {
		items[current] = it;
		current++;
	}
}

bool Jugador::removeItemById(unsigned int itemId){
  long pos;
	pos = indexOfItem(itemId);

	if (pos == -1) {
		return false;
	}

	delete items[pos];
	for (int i = pos; i < (current - 1); i++) {
		items[i] = items[i + 1];
	}
	current--;
	return true;
}

Habilidad* Jugador::getHabilidad(unsigned int habilidadId) const{// Getter de las habilidades, apuntadores
	long pos;
	pos = indexOfHabilidad(habilidadId);
	if (pos == -1) {
		return NULL;
	} else {
		return habilidades[pos];
	}
};

void Jugador::addHabilidad (Habilidad *ha){
  long pos;
	pos = indexOfHabilidad(ha->getHabilidadId());

	if (pos == -1) {
		habilidades[current] = ha;
		current++;
	}
}

bool Jugador::removeHabilidadById(unsigned int habilidadId){
  long pos;
	pos = indexOfHabilidad(habilidadId);

	if (pos == -1) {
		return false;
	}

	delete habilidades[pos];
	for (int i = pos; i < (current - 1); i++) {
		habilidades[i] = habilidades[i + 1];
	}
	current--;
	return true;
}

string Jugador::getNombre(){
  return nombre;
}

void Jugador::setNombre(string nombre_){
  nombre=nombre_;
}

unsigned int Jugador::getJugadorId(){
  return jugadorId;
}

void Jugador::setJugadorId(unsigned int jugadorId_){
  jugadorId=jugadorId_;
}

unsigned int Jugador::getVida(){
  return vida;
}

void Jugador::setVida(unsigned int vida_){
  vida=vida_;
}

unsigned int Jugador::getMaxVida(){
  return maxVida;
}

void Jugador::setMaxVida(unsigned int maxVida_){
  maxVida=maxVida_;
}

unsigned int Jugador::getExperiencia(){
  return experiencia;
}

void Jugador::setExperiencia(unsigned int experiencia_){
  experiencia=experiencia_;
}

unsigned int Jugador::getMora(){
  return mora;
}

void Jugador::setMora(unsigned int mora_){
  mora=mora_;
}

unsigned int Jugador::getRespuestasCorrectas(){
  return respuestasCorrectas;
}

void Jugador::setRespuestasCorrectas(unsigned int respuestasCorrectas_){
  respuestasCorrectas=respuestasCorrectas_;
}

unsigned int Jugador::getMaxRespuestasCorrectas(){
  return maxRespuestasCorrectas;
}

void Jugador::setMaxRespuestasCorrectas(unsigned int maxRespuestasCorrectas_){
  maxRespuestasCorrectas=maxRespuestasCorrectas_;
}

unsigned int Jugador::getMax(){
  return max;
}

void Jugador::setMax(unsigned int max_){
  max=max_;
}

//toString
std::string Jugador::toString() const {
	std::stringstream aux;

	aux << nombre << "," << jugadorId << "," << vida << "," << maxVida << "," << experiencia << "," << mora << "," << respuestasCorrectas << "," << maxRespuestasCorrectas;
	return aux.str();
}

/*
void Jugador::clearHabilidades() {
	for (int i = 0; i < current; i++) {
		delete habilidades[i];
	}
	delete [] habilidades;
	habilidades = NULL;
	max = 0;
	current = 0;
}

void Jugador::clearItems() {
	for (int i = 0; i < current; i++) {
		delete items[i];
	}
	delete [] items;
	items = NULL;
	max = 0;
	current = 0;
}


bool Jugador::load(std::string filename){
  std::ifstream file(filename);
	std::string input;

	if (!file.is_open()) {
		return false;
	}

	clearItems();
	file >> max >> current;
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << max << "\n" << current << "\n";
	habilidades = new Habilidad*[max];
	for (int i = 0; i < current; i++) {
		getline(file, input);
		habilidades[i] = new Habilidad(input);
	}
	return true;
}


bool Jugador::save(std::string filename) const{
  std::ofstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	file << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		file << habilidades[i]->toString() << "\n";
	}
	return true;
}

std::string Jugador::toString() const {
	std::stringstream aux;

	aux << max << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		aux << habilidades[i]->toString() << "\n";
	}
	return aux.str();
}

*/