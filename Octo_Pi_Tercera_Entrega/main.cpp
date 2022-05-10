#include <iostream>
#include <vector>
#include "jugador.h"
#include "pocion.h"
#include "skip.h"
#include "especial.h"
#include "piso.h"

int main() {
  //Objetos tipo Habilidad
  //Habilidad: Nombre, Descripcion, Id, precio, powerUp
  Habilidad postura1("Corte de Superficie", "El usuario genera un corte poderoso formando una ola por el movimiento de su arma potenciando su ataque capaz de decapitar fácilmente a cualquier objetivo, +0.2 al danio", 1, 15, 0.2);
  Habilidad postura2("Rueda de Agua", "El usuario realiza un giro de 360° en cualquier dirección manteniendo su espada firme formando un circulo de agua realizando un potente corte al enemigo, +0.2 aldanio", 2, 15, 0.2);
  Habilidad postura3("Danza de las Corrientes", "El usuario balancea su espada contra su oponente de una manera que imita el movimiento de las corrientes de agua siendo así un ataque fluido en un movimiento circular, +0.2 aldanio", 3, 15, 0.2);
  Habilidad postura4("Golpe de Marea", "El usuario realiza diversos cortes de manera consecutiva mientras gira fluidamente simulando una marea alrededor del objetivo, +0.2 aldanio", 4, 15, 0.2);
  Habilidad postura5("Lluvia tras la Sequía", "Un corte que acaba con la vida del objetivo sin producir dolor alguno, +0.2 aldanio", 5, 15, 0.2);
  Habilidad postura6("Torbellino Sinuoso", "Torciendo ferozmente la parte superior e inferior de su cuerpo, crea un remolino que corta cualquier cosa atrapada en el, +0.2 aldanio", 6, 15, 0.2);
  Habilidad postura7("Gotas de Lluvia Penetrantes", "Una puñalada rápida y precisa, esta postura destaca entre las otras por la rapidez con la que se puede realizar, +0.2 aldanio", 7, 15, 0.2);
  Habilidad postura8("Lago de la Cascada", "El espadachin realiza un corte en vertical causando un daño devastador sobre el objetivo, +0.2 aldanio", 8, 15, 0.2);
  Habilidad postura9("Salpicadura Caótica", "Minimiza el tiempo de aterrizaje y la superficie necesaria al aterrizar, lo que permite al usuario moverse sin límites. Ideal cuando peleas en un lugar sin un punto de apoyo sólido, +0.2 aldanio", 9, 15, 0.2);
  Habilidad postura10("El dragon del Cambio", "Un ataque continuo que incrementa su fuerza con cada rotación creando poderosos cortes, +0.2 aldanio", 10, 15, 0.2);

  //Objetos tipo Item
  //Item: Nombre, Descripcion, Id, precio
  //Pocion: Nombre, Descripcion, Id, precio, StatUp
  Pocion pocionVida("Pocion Vida Instantanea", "La poción de vida restaura un punto a tu vida actual", 1, 10, 1);
  
  //Pocion: Nombre, Descripcion, Id, precio, StatUp
  Skip skip ("Skip", "Skip te permite saltar de pregunta, además proporciona +1 a tus respuestas correctas", 2, 30, 1);
  
  //Especial: Nombre, Descripcion, Id, precio, especial
  Especial dulce("Dulce", "Este objeto te permite canjearlo ante el profesor por un Dulce ", 10, 10, "Vale para un dulce");
  Especial tareaAtrasada("Entrega tarea atrasada", "Este objeto te permite entregar una tarea atrasada al profesor Octo-Pi", 11, 15, "Vale para excentar Tarea Atrasada");
  Especial excentarTarea("Exentar tarea", "Este objeto te permite excentar una tarea en la materia impartida por el profesor Octo-Pi", 12, 20, "Vale para excentar Tarea");
  Especial excentarProyecto("Excentar proyecto", "Este objeto te permite excentar un Proyecto en la materia impartida por el profesor Octo-Pi", 13, 30, "Vale para excentar Proyecto");
  Especial excentarExamen("Excentar Examen", "Este objeto te permite excentar un Examen en la materia impartida por el profesor Octo-Pi", 14, 40, "Vale para excentar Examen");
  Especial excentarMateria("Excentar Materia", "Este objeto te permite excentar la materia en la materia impartida por el profesor Octo-Pi", 15, 100, "Vale para excentar Materia");

  //Objetos tipo Jugador
  //Jugador: Nombre, Id, vida, Maximo de vida, experiencia, Dinero, respuestasCorrectas, maximo de respuestas correctas, capacidad items/habilidades, numero de habilidades/items
  Jugador chunchunmaru("Chunchunmaru", 1, 5, 5, 0, 0, 0, 5, 5, 0);

  //Piso: numeroPiso_, nombrePiso_, nombreBoss, descripcionPiso
  Piso piso1(1, "El Borde del Abismo ", "Nikikabane", "a");

  //chunchunmaru.addHabilidad(new Habilidad("Golpe ligero", "Lanza un pequenio golpe al oponente, +1 aldanio", 1, 15, 1));
  //std::cout << chunchunmaru.toString();

  //chunchunmaru.addItem(new Item("Pocio de danio instantaneo", "Hace 1 punto de danio al oponente", 1, 10));
  //std::cout << chunchunmaru.toString();

  /*
  chunchunmaru.save("jugador.txt");
  chunchunmaru.load("jugador.txt");
  */

  while (chunchunmaru.vivo()){
    for (int i = 0; i <= 5; i++){
      bool a = piso1.preguntar1(i);
      if (a==true){
        chunchunmaru.atacar();
        cout << "Respuestas correctas: " <<chunchunmaru.getRespuestasCorrectas() << "\n \n";
      } else {
        chunchunmaru.recibirDanio();
        cout << "Vida actual: " <<chunchunmaru.getVida() << "\n \n";
      }      

    }
  }

  

  std::cout << pocionVida.toString();



}
