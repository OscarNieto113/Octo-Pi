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
#include <string>
#include <fstream>
using namespace std;
#include <chrono>
#include <thread>

class Piso{
  protected:
    string nombrePiso;
    string nombreBoss;
    string descripcionBoss;
    string descripcionPiso;

    unsigned int numeroPiso;

    static std::string const preguntas1[]; //Arreglo de preguntas
    static std::string const preguntas2[];
    static std::string const preguntas3[];
    static std::string const preguntas4[];

    static std::string const respuestas1[]; //Arreglo de respuestas
    static std::string const respuestas2[];
    static std::string const respuestas3[];
    static std::string const respuestas4[];

    std::vector<std::vector<std::string> > preguntas;
    
  public:
    Piso();//Constructor por default / omision
    Piso (unsigned int numeroPiso_, string nombrePiso_, string nombreBoss_, string descripcionPiso_, string descripcionBoss_); // Constructor alterno
    Piso (const Piso&); // Constructor de copia

    unsigned int getNumeroPiso ();
    string getNombrePiso ();
    string getNombreBoss ();
    string getDescripcionPiso ();
    string getDescripcionBoss();

    void setNumeroPiso(unsigned int numeroPiso_);
    void setNombrePiso(string nombrePiso_);
    void setNombreBoss(string nombreBoss_);
    void setDescripcionPiso (string descripcionPiso_);
    void setDescripcionBoss(string descripcionBoss_);

    string  toString() const;

    bool preguntar1 (int i_);
    bool encuentro(Jugador*, Piso*);
    //bool preguntar2 (int i_, string res_);
    //bool preguntar3 (int i_, string res_);
    //bool preguntar4 (int i_, string res_);
};

/*************************************************************
* Implementation of piso class
*************************************************************/
struct slowly_printing_string2 { std::string data; long int delay; };

std::ostream& operator<<(std::ostream& out, const slowly_printing_string2& s) {
  for (const auto& c : s.data) {
    out << c << std::flush;        
    std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
  }
  return out;
};

//Constructor Piso por omision
Piso::Piso(){
  numeroPiso=0;
  nombrePiso="";
  nombreBoss="";
  descripcionPiso="";
  descripcionBoss="";
}

//Constructor Piso alterno
Piso::Piso(unsigned int numeroPiso_, string nombrePiso_, string nombreBoss_, string descripcionPiso_, string descripcionBoss_){
  numeroPiso=numeroPiso_;
  nombrePiso=nombrePiso_;
  nombreBoss=nombreBoss_;
  descripcionPiso=descripcionPiso_;
  descripcionBoss=descripcionBoss_;
}

//Constructor Piso de copia
Piso::Piso(const Piso &piso)
  : numeroPiso(piso.numeroPiso), nombrePiso(piso.nombrePiso), nombreBoss(piso.nombreBoss), descripcionPiso(piso.descripcionPiso), descripcionBoss(piso.descripcionBoss){
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

string Piso::getDescripcionBoss(){
  return descripcionBoss;
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

void Piso::setDescripcionBoss(string descripcionBoss_){
  descripcionBoss=descripcionBoss_;
}

string const Piso::preguntas1[] = {"\nCuánto es 12 + 49?", "\nCuánto es 45 - 32?", "\nCuánto es 28 / 4", "\nCuánto es 12*14?", "\nCarlos tiene 38.5 litros de aceite y ha llenado 8 botellas  de tres cuartos de litro cada una. El resto lo pone en frascos de 125 ml cada una. Cuántas frascas llenas?"};
string const Piso::preguntas2[] = {"\nCuánto es 2456 + 1394?", "\nCuánto es 4564 - 3999?", "\nQue numero es este XVI en numeracion romana", "\nQue numero es este XXIV en numeracion romana", "\nEscribe en notacion numerica el siguiente numero : Tres millones quinientos veinticinco mil novecientos ochenta (Separalos por comas)"};
string const Piso::preguntas3[] = {"\nTrabajando con operaciones con fracciones. Cuanto es (3/5)-(1/7)", "\nTrabajando con operaciones con fracciones. Cuanto es (2/3)*(15/14)", "\nTrabajando con operaciones con fracciones. Cuanto es (6/7)*[(9/4)+(3/8)])", "\nCuanto es 12.435+142.36", "\nCuanto es 23.45 + 5.2 + 67.345"};
string const Piso::preguntas4[] = {"\nCuánto es 804 * 37?", "\nCuánto es 124 / 4 ?", "\nCuanto es 7^3 ?", "\nCuánto es 22^4?", "\nCual es la raiz de 4761?"};

string const Piso::respuestas1[] = {"61", "13", "7", "148", "268"};
string const Piso::respuestas2[] = {"3850", "565", "16", "24", "3,525,980"};
string const Piso::respuestas3[] = {"16/35", "15/21", "63/28", "154.795", "95.995"};
string const Piso::respuestas4[] = {"29748", "31", "343", "10648", "69"};

//agrega pregunta (Piso, pregunta string, pos i correcta string)
//preguntas[piso].push_back(pregunta);

/*
for (int i = 0; i < piso[1].size(); i++) {
     cout << piso[1][i];
}
*/

bool Piso::encuentro(Jugador *jugador, Piso *piso){
  char opcion;
  bool bandera;
  cout << "";
  string dialogo = "\nConforme vas avanzando en '" + piso->getNombrePiso() + "' te encuentras con " + piso->getNombreBoss() + ", " + piso->getDescripcionBoss() + "\nTendras que derrotarlo si quieres pasar al siguiente piso\n\n";
  std::cout << slowly_printing_string2{dialogo, 10};
  int i;
  i=0;
  bandera = true;
  do {
    std::cout << slowly_printing_string2{"\nQue quieres hacer?\n c) Correr p) Pelear\n", 10};
    std::cin >> opcion;
    if (opcion == 'c'){
      bandera = false;
      continue;
    }
    
    //for
    std::string dialogo1 = "\nEl contrincante esta a punto de atacar\n Que quieres hacer?\n  a) Atacar  b) Usar habilidad para atacar  i) Usar Item\n";
    std::cout << slowly_printing_string2{dialogo1, 10};

    char accion;
    cin >> accion;

    if (accion == 'a'){
      std::cout << slowly_printing_string2{"\nHaz decidido atacar, responde a la pregunta:\n", 10};
      bool respu=preguntar1(i);
      if (respu==true){
        jugador->atacar(0.0);
      }
      else {
        jugador->recibirDanio();
      }
    }

    else if (accion == 'b'){
      std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, elige la habilidad a usar:\n", 10};
      for (int j = 1; j <= jugador->getCurrent2(); j++){
        std::cout << "Opcion: (";
        std::cout << j;
        std::cout << ") ";
        std::cout << jugador->getHabilidad(j);
        std::cout << "\n";
      }
      std::cout << "\nSelecciona una habilidad (Numero de la opcion)\n";
      int hab;
      cin >> hab;
      if (hab == 1){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.1);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 2){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.2);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 3){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.3);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 4){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.4);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 5){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.5);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 6){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.6);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 7){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.7);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 8){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.8);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 9){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(0.9);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else if (hab == 10){
        std::cout << slowly_printing_string2{"\nHaz decidido atacar con habilidad, responde a la pregunta:\n", 10};
        bool respu=preguntar1(i);
        if (respu==true){
          jugador->atacar(1.0);
        }
        else {
          jugador->recibirDanio();
        }
      }
      else{
        cout << "Habilidad no valida\n";
      }
    }

    else if (accion == 'i'){
      for (int k = 1; k <= jugador->getCurrent(); k++){
        std::cout << "Opcion: (";
        std::cout << k;
        std::cout << ") ";
        std::cout << jugador->getItems(k);
        std::cout << "\n";
      }
      std::cout << "\nSelecciona un Item (Numero de la opcion)\n";
      int ite;
      cin >> ite;
      if (ite == 1){
        cout << "Haz usado una pocion \n";
        jugador -> usarPocion(ite);        
      }
    }

    else {
      std::cout << slowly_printing_string2{"\nAccion incorrecta\n", 10};
    }
    i=i+1;

  }while (bandera==true && jugador->vivo() && jugador->getRespuestasCorrectas()<=jugador->getMaxRespuestasCorrectas());

  if (!jugador->vivo()){
    std::cout << "\n" << piso->getNombreBoss() << " GANA\n\n";
		return false;
  }

  if (jugador->vivo()) {
		jugador->addTesoro();
    string dialogo9 = "\n" + jugador->getNombre() +" GANA\n\n Puedes pasar a la siguiente zona\n";
    std::cout << slowly_printing_string2{dialogo9, 10};
		return true;
	}
  return true; 
}

//Método preguntar.
bool Piso::preguntar1(int i){
  string dialogo8 = "El contrincante te pregunta: \n" + preguntas1[i] + "\nTu respusta es:  ";
  std::cout << slowly_printing_string2{dialogo8, 10};
  string resp;
  std::cout << "                         CheatSheet: " << respuestas1[i] << "\n";
  cin >> resp;
  if (resp == respuestas1[i]){
    cout << "RESPUESTA CORRECTA \n";
    return true;

  } 
  else{
    string dialogo7 = "RESPUESTA INCORRECTA \nLa respuesta correcta es: " + respuestas1[i] + "\nRecibiste uno de danio \n";
    std::cout << slowly_printing_string2{dialogo7, 10};
    return false;

  }    

}



#endif