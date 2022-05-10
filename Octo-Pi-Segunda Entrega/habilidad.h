/*************************************************************
* File: Habilidad.h
* Author: Oscar Eduardo Nieto Espitia
* Description: This file contains the definition of Habilidad class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include <iostream>
#include<string>
#include <sstream>
using namespace std;

class Habilidad{
  private:
    string habilidadNombre;
    string habilidadDescripcion;
    unsigned int habilidadId;
    unsigned int habilidadPrecio;
    unsigned int powerUp;

  public:
    Habilidad();//Constructor por default / omision
    Habilidad (string habilidadNombre_, string habilidadDescripcion_, unsigned int habilidadId_, unsigned int habilidadPrecio_, unsigned int powerUp_); // Constructor alterno
    Habilidad (const Habilidad&); // Constructor de copia

    string getHabilidadNombre();//Getter nombre de la Habilidad
    void setHabilidadNombre(string habilidadNombre_); //Setter del Nombre de la Habilidad
    string getHabilidadDescripcion();//Getter de la descripcion de la Habilidad
    void setHabilidadDescripcion(string habilidadDescripcion_); //Setter de la descripcion de la Habilidad
    unsigned int getHabilidadId();//Getter de la Habilidad Id
    void setHabilidadId(unsigned int habilidadId_); //Setter de la Habilidad Id
    unsigned int getHabilidadPrecio();//Getter de la Habilidad precio
    void setHabilidadPrecio(unsigned int habilidadPrecio_); //Setter de la Habilidad precio
    unsigned int getPowerUp();//Getter de la Habilidad powerUp
    void setPowerUp(unsigned int powerUp_); //Setter de la Habilidad powerUp

    std::string toString() const;
};

//Constructor Item por omision
Habilidad::Habilidad(){
  habilidadNombre="";
  habilidadDescripcion="";
  habilidadId=0;
  habilidadPrecio=0;
  powerUp=0;
}

//Constructor Item alterno
Habilidad::Habilidad(string habilidadNombre_, string habilidadDescripcion_, unsigned int habilidadId_, unsigned int habilidadPrecio_, unsigned int powerUp_){
  habilidadNombre=habilidadNombre_;
  habilidadDescripcion=habilidadDescripcion_;
  habilidadId=habilidadId_;
  habilidadPrecio=habilidadPrecio_;
  powerUp=powerUp_;
}

//Constructor Item de copia
Habilidad::Habilidad(const Habilidad &habilidad)
  : habilidadNombre(habilidad.habilidadNombre), habilidadDescripcion(habilidad.habilidadDescripcion), habilidadId(habilidad.habilidadId), habilidadPrecio(habilidad.habilidadPrecio), powerUp(habilidad.powerUp){
}


//Getters
unsigned int Habilidad::getPowerUp(){
  return powerUp;
}

unsigned int Habilidad::getHabilidadPrecio(){
  return habilidadPrecio;
}

unsigned int Habilidad::getHabilidadId(){
  return habilidadId;
}

string Habilidad::getHabilidadNombre(){
  return habilidadNombre;
}

string Habilidad::getHabilidadDescripcion(){
  return habilidadDescripcion;
}

//Setters
void Habilidad::setHabilidadId(unsigned int habilidadId_){
  habilidadId=habilidadId_;
}

void Habilidad::setHabilidadNombre(string habilidadNombre_){
  habilidadNombre=habilidadNombre_;
}

void Habilidad::setHabilidadDescripcion(string habilidadDescripcion_){
  habilidadDescripcion=habilidadDescripcion_;
}

void Habilidad::setHabilidadPrecio(unsigned int habilidadPrecio_){
  habilidadPrecio=habilidadPrecio_;
}

void Habilidad::setPowerUp(unsigned int powerUp_){
  powerUp=powerUp_;
}

//toString
std::string Habilidad::toString() const {
	std::stringstream aux;

	aux << habilidadId << "," << habilidadId << "," << habilidadDescripcion << "," << habilidadPrecio << "," << powerUp ;
	return aux.str();
}