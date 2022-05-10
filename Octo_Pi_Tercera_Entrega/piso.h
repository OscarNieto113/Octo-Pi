/*************************************************************
* File: Habilidad.h
* Author: Oscar Eduardo Nieto Espitia
* Description: This file contains the Piso class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef PISO_H
#define PISO_H

#include <iostream>
#include<string>
#include <sstream>
using namespace std;

class Piso{
  protected:
    string nombrePiso;
    string nombreBoss;
    string descripcionPiso;

    //string pregunta [5];
    //string respuesta [15];

    //std::vector<std::string> respuestaCorrecta; //Arreglo de respuestas correctas

    unsigned int numeroPiso;
    
  public:
    Piso();//Constructor por default / omision
    Piso (unsigned int numeroPiso_, string nombrePiso_, string nombreBoss_, string descripcionPiso_); // Constructor alterno
    Piso (const Piso&); // Constructor de copia

    unsigned int getNumeroPiso ();
    string getNombrePiso ();
    string getNombreBoss ();
    string getDescripcionPiso ();

    void setNumeroPiso(unsigned int numeroPiso_);
    void setNombrePiso(string nombrePiso_);
    void setNombreBoss(string nombreBoss_);
    void setDescripcionPiso (string descripcionPiso_);

    string  toString() const;

    static std::string const piso1[]; //Arreglo de preguntas
    static std::string const piso2[];
    static std::string const piso3[];
    static std::string const piso4[];

    static std::string const respuesta1[]; //Arreglo de respuestas
    static std::string const respuesta2[];
    static std::string const respuesta3[];
    static std::string const respuesta4[];

    //Considero que no hace falta poner un setter ni un getter para los atributos
    //pregunta y respuesta, no es necesario cambiar la pregunta ni la respuesta, ademas
    //en el caso del getter, ambos atributos son complementarios, por esta razon se opto
    //por solo usar una funcion "preguntar"

    bool preguntar1 (int i_);
    //bool preguntar2 (int i_, string res_);
    //bool preguntar3 (int i_, string res_);
    //bool preguntar4 (int i_, string res_);
};

//Constructor Piso por omision
Piso::Piso(){
  numeroPiso=0;
  nombrePiso="";
  nombreBoss="";
  descripcionPiso="";
  //pregunta=[];
  //respuesta=[];
}

//Constructor Piso alterno
Piso::Piso(unsigned int numeroPiso_, string nombrePiso_, string nombreBoss_, string descripcionPiso_){
  numeroPiso=numeroPiso_;
  nombrePiso=nombrePiso_;
  nombreBoss=nombreBoss_;
  descripcionPiso=descripcionPiso_;
}

//Constructor Piso de copia
Piso::Piso(const Piso &piso)
  : numeroPiso(piso.numeroPiso), nombrePiso(piso.nombrePiso), nombreBoss(piso.nombreBoss), descripcionPiso(piso.descripcionPiso){
}


//Getters
unsigned int Piso::getNumeroPiso(){
  return numeroPiso;
}

string Piso::getNombrePiso(){
  return nombrePiso;
}

string Piso::getNombreBoss(){
  return nombreBoss;
}

string Piso::getDescripcionPiso(){
  return descripcionPiso;
}

//Setters
void Piso::setNumeroPiso(unsigned int numeroPiso_){
  numeroPiso=numeroPiso_;
}

void Piso::setNombrePiso(string nombrePiso_){
  nombrePiso=nombrePiso_;
}

void Piso::setNombreBoss(string nombreBoss_){
  nombreBoss=nombreBoss_;
}

void Piso::setDescripcionPiso(string descripcionPiso_){
  descripcionPiso=descripcionPiso_;
}

std::string const Piso::piso1[] = {"Cuánto es 12 + 49?", "Cuánto es 45 - 32?", "Cuánto es 28 / 4", "Cuánto es 12*14?", "Carlos tiene 38.5 litros de aceite y ha llenado 8 botellas  de tres cuartos de litro cada una. El resto lo pone en frascos de 125 ml cada una. Cuántas frascas llenas?"};
std::string const Piso::piso2[] = {"Cuánto es 2456 + 1394?", "Cuánto es 4564 - 3999?", "Que numero es este XVI en numeracion romana", "Que numero es este XXIV en numeracion romana", "Escribe en notacion numerica el siguiente numero : Tres millones quinientos veinticinco mil novecientos ochenta (Separalos por comas)"};
std::string const Piso::piso3[] = {"Trabajando con operaciones con fracciones. Cuanto es (3/5)-(1/7)", "Trabajando con operaciones con fracciones. Cuanto es (2/3)*(15/14)", "Trabajando con operaciones con fracciones. Cuanto es (6/7)*[(9/4)+(3/8)])", "Cuanto es 12.435+142.36", "Cuanto es 23.45 + 5.2 + 67.345"};
std::string const Piso::piso4[] = {"Cuánto es 804 * 37?", "Cuánto es 124 / 4 ?", "Cuanto es 7^3 ?", "Cuánto es 22^4?", "Cual es la raiz de 4761?"};

std::string const Piso::respuesta1[] = {"61", "13", "7", "148", "268"};
std::string const Piso::respuesta2[] = {"3850", "565", "16", "24", "3,525,980"};
std::string const Piso::respuesta3[] = {"16/35", "15/21", "63/28", "154.795", "95.995"};
std::string const Piso::respuesta4[] = {"29748", "31", "343", "10648", "69"};

//Método preguntar.
bool Piso::preguntar1(int i){

  std::cout << piso1[i] << std::endl;
  string res_;
  cin >> res_;
  if (res_ == respuesta1[i]){
    std::cout << "RESPUESTA CORRECTA \n \n";
    return true;
  } 
  else{
    std::cout << "RESPUESTA INCORRECTA \n" << "Recibiste uno de danio \n \n";
    return false;
  }
  std::cout << respuesta1[i] << std::endl;
}



#endif