#include <iostream>
#include <vector>
#include "jugador.h"
//#include "date.h"

int main() {
  std::cout << "Hello World!\n";
  Habilidad ataque("Golpe ligero", "Lanza un pequenio golpe al oponente, +1 aldanio", 1, 15, 1);
  //Habilidad: Nombre, Descripcion, Id, precio, powerUp

  Item pocionDanio("Pocio de danio instantaneo", "Hace 1 punto de danio al oponente", 1, 10);
  //Item: Nombre, Descripcion, Id, precio

  Jugador chunchunmaru("Chunchunmaru", 1, 5, 5, 0, 0, 0, 5, 5, 0);
  //Jugador: Nombre, Id, vida, Maximo de vida, experiencia, Dinero, respuestasCorrectas, maximo de respuestas correctas, capacidad items/habilidades, numero de habilidades/items

  chunchunmaru.addHabilidad(new Habilidad("Golpe ligero", "Lanza un pequenio golpe al oponente, +1 aldanio", 1, 15, 1));
  std::cout << chunchunmaru.toString();

  chunchunmaru.addItem(new Item("Pocio de danio instantaneo", "Hace 1 punto de danio al oponente", 1, 10));
  std::cout << chunchunmaru.toString();

  /*
  chunchunmaru.save("jugador.txt");
  chunchunmaru.load("jugador.txt");
  */
}