#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "jugador.h"
#include "pocion.h"
#include "skip.h"
#include "especial.h"
#include "piso.h"
using namespace std;
#include <chrono>
#include <thread>

struct slowly_printing_string { std::string data; long int delay; };

std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
    for (const auto& c : s.data) {
        out << c << std::flush;        
        std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
    }
    return out;
}

void menu(){
  cout<<"Menu"<<endl;
  cout<<"\n1. Instrucciones del Juego"<<endl;
  cout<<"2. Iniciar Aventura"<<endl;
  cout<<"3. Salir\n"<<endl;
}

//Funcion leer el archivos
string instrucciones(string arch){
  ifstream archivo;
  string texto;
  archivo.open(arch,ios::in);
  getline(archivo,texto);
  return texto;

}

int main() {
  //Objetos tipo Habilidad
  //Habilidad: Nombre, Descripcion, Id, precio, powerUp
  Habilidad postura1("Corte de Superficie", "El usuario genera un corte poderoso formando una ola por el movimiento de su arma potenciando su ataque capaz de decapitar fácilmente a cualquier objetivo", 1, 15, 0.1);
  Habilidad postura2("Rueda de Agua", "El usuario realiza un giro de 360° en cualquier dirección manteniendo su espada firme formando un circulo de agua realizando un potente corte al enemigo", 2, 15, 0.2);
  Habilidad postura3("Danza de las Corrientes", "El usuario balancea su espada contra su oponente de una manera que imita el movimiento de las corrientes de agua siendo así un ataque fluido en un movimiento circular", 3, 15, 0.3);
  Habilidad postura4("Golpe de Marea", "El usuario realiza diversos cortes de manera consecutiva mientras gira fluidamente simulando una marea alrededor del objetivo", 4, 15, 0.2);
  Habilidad postura5("Lluvia tras la Sequía", "Un corte que acaba con la vida del objetivo sin producir dolor alguno", 5, 15, 0.4);
  Habilidad postura6("Torbellino Sinuoso", "Torciendo ferozmente la parte superior e inferior de su cuerpo, crea un remolino que corta cualquier cosa atrapada en el", 6, 15, 0.5);
  Habilidad postura7("Gotas de Lluvia Penetrantes", "Una puñalada rápida y precisa, esta postura destaca entre las otras por la rapidez con la que se puede realizar", 7, 15, 0.6);
  Habilidad postura8("Lago de la Cascada", "El espadachin realiza un corte en vertical causando un daño devastador sobre el objetivo", 8, 15, 0.7);
  Habilidad postura9("Salpicadura Caótica", "Minimiza el tiempo de aterrizaje y la superficie necesaria al aterrizar, lo que permite al usuario moverse sin límites. Ideal cuando peleas en un lugar sin un punto de apoyo sólido", 9, 15, 0.8);
  Habilidad postura10("El dragon del Cambio", "Un ataque continuo que incrementa su fuerza con cada rotación creando poderosos cortes", 10, 15, 0.9);

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
  //Jugador:Nombre, jugadorId, vida, Vida Maxima, experiencia, mora, respuestasCorrectas, maxRespuestasCorrectas, Maximo de items, Cantidad de Items actuales, Maximo de habilidades, Cantidad de Habilidades actuales
  Jugador chunchunmaru("", 1, 5, 5, 30, 30, 0.0, 3, 5, 0, 10, 0);
  //std::cout << chunchunmaru.toString();

  //Objetos tipo piso 
  //Piso: numeroPiso_, nombrePiso_, nombreBoss, descripcionPiso, DescripcionBoss
  Piso piso1(1, "El Borde del Abismo ", "Nikikabane", "\nEs el lindero entre el territorio de shark-τ y el mar de Ojotsk, este se le considera como el limbo ya que es un punto medio entre ambos territorios. En este terriotrio no existen muchos peligros ni seres importantes, aunque depredadores de capas inferiores suelen venir a buscar alimento. La vegetacion es la misma que en el mar de Ojotsk y no hay muchas diferencias geograficas entre ambas regiones. Se dice que cualquier aventurero pude ir a esta area con seguridad", "\nNikikabane es un gran pez que habita en la primera capa. Su aspecto se caracteriza por tener grandes bigotes junto con colores blanco y negro dificiles de olvidar. Nikikabane es uno de los mas recientes secuaces de shark-τ. Nikikabane no es un contrincante especialmente fuerte.");
  
  Piso piso2(2, "El bosque de la tentación ", "Ottobasu ", "\nEn esta capa es donde el ambiente se torna peligroso. Los animales se vuelven mas agresivos y territoriales. A los 2000 metros aproximadamente el arrecife se voldea y se convierte en lo que se le conoce como “el arrecife inverido”. En este, el ambiente se vuelve frio e inestable y depredadores muy intrepidos aparecen. Solo los aventureros experimentados puden venir a esta capa. En esta area se creo el campamento de observacion para aquellos que necesitan un descanso.", "\nOttobasu es un delfin bastante inteligente. Este destaca mas que nada por su particular color rosa, que no te engañe su aspecto, Ottobasu es alguien que se especializa en manipular a su presa de diferentes maneras, a veces las hace dudar de sus capacidades, otras veces simplemente no tiene ganas de perder el tiempo y pueden acabar las cosas muy mal. Ottobasu es un antiguo ser marino casi extinto debido a su particular piel, el pasó a ser vasallo de shark-τ debido a que queria conservar su especie, ahora vive bajo la protección de shark-τ.");

  Piso piso3(3, "La Gran Falla ", "Mandíbula Escarlata ", "\nLa tercera capa es un largo decenso vertical, de forma tubular, dicha area se vuelve sumamente dificil de explorar. En las paredes del tubo existe un sistema de cuevas entrelazadas que funcionan como medida de descenso para aquellos que osen explorar este territorio. En el el centro de la tercera capa viven criaturas extremadamente rapidas debido a que se han acostumbrado a las grandes areas que hay que recorrer para conseguir comida. Solo aventureros que esten seguros de sus capacidades puden venir a explorar esta capa.", "\nMandibula Escarlata o tambien conocido como Splitjaw es una especie de anguila roja gigante que vive principalmente en los acantiados de la tercera capa. Mandibula escarlata como su nombre lo indica se caracteriza por tener la mandibula color carmesi o escarlata,  el resto del cuerpo es color gris. Es un depredador feroz que atacan a cualquier presa a la vista. El es la mano derecha de Shark-τ, cuida que nadie entre a la cuarta capa y tambien es un gran combatiente, este ha ayudado a ganar gran parte de las guerras de shark-τ.");

  Piso piso4(4, "Cáliz de los Gigantes", "Shark-τ", "\nLa cuarta y ultima capa es un extraña y oscuro ecosistema lleno de enredaderas que se entrelazan para formar discos concavos, se cree que en los discos concavos viven criaturas con piel extremadamente dura, esto se debe a lo profundo que se encuentra esta capa. El peligro de las bestias que habitan aqui tienen un nivel de peligro extremadamente alto. Solo aquellos viajeros los mas fuertes pueden entrar aqui.", "\nShark-τ es un tiburon blanco que se caracteriza por su cuerpo fusiforme y gran robustesz, tiene una boca muy grande y cientos de dientes tan filosos como cualquier katana. Es ferozmente temperamental y territorial. Actualmente es el gobernante del mar de Ojotsk.");

  chunchunmaru.addHabilidad(new Habilidad(postura1));
  //std::cout << chunchunmaru.toString();

  //pelear (chunchunmaru, piso1);

  chunchunmaru.addItem(new Item("Pocio de danio instantaneo", "Hace 1 punto de danio al oponente", 1, 10));

  //std::cout << chunchunmaru.getHabilidad(3);
  
  //std::cout << chunchunmaru.toString();

  string archivo1 = "instrucciones.txt";
  string archivo2 = "sinopsis.txt";
  
  //chunchunmaru.save("catlogJugador.txt");
  //chunchunmaru.load("catlogJugador.txt");
  
  bool bandera = true;
  //Ciclo para que el sistema siga corriendo mientras no elija la opcion salir.
  while (bandera){
    menu();
    int opcion;
    cout << "Selecciona una opcion: ";
    cin >> opcion;
    if (opcion==1){
      instrucciones (archivo1);
    }
    else if (opcion==2){
      string sinopsis = instrucciones (archivo2); //Sinopsis del Juego 
      std::cout << slowly_printing_string{ sinopsis,1}; //Sinopsis
      string descripcion = "\n \nAhora te encuentras en: " + piso1.getNombrePiso() + "\n" + piso1.getDescripcionPiso();//Descripcion del piso
      std::cout << slowly_printing_string{ descripcion,1};//Descripcion del piso
      cout<<"\n \nCual es tu nombre aventurero?\n";//Elegir nombre
      string nombre;
      cin >> nombre;//Elegir nombre
      chunchunmaru.setNombre(nombre);// nombre
      
      string dialogo = "\nOcto-π : Antes de que te vayas, ten mi Katana junto con esta pocion de vida. Espero que cuides de ella " + chunchunmaru.getNombre() + "\n";
      std::cout << slowly_printing_string{dialogo, 10};

      chunchunmaru.addHabilidad(new Habilidad(postura1));
      chunchunmaru.addHabilidad(new Habilidad(postura2));
      chunchunmaru.addHabilidad(new Habilidad(postura3));
      chunchunmaru.addHabilidad(new Habilidad(postura4));
      chunchunmaru.addHabilidad(new Habilidad(postura5));
      chunchunmaru.addItem(new Pocion(pocionVida));

      string dialogo2 = "\nHaz adquirido: \n" + pocionVida.getNombreItem() + " y " + postura5.getHabilidadNombre() + "\n";
      std::cout << slowly_printing_string{dialogo2, 10};


      std::cout << slowly_printing_string{"\nAntes de entrar quieres ver tu personaje? \n   Y/N\n",10};
      string personaje;
      cin >> personaje;
      if (personaje == "Y" || personaje =="y"){
        std::cout <<slowly_printing_string{chunchunmaru.toString(),10};
        cout << "Ver inventario / Ver habilidades \n I/H";
        string inventario;
        cin >> inventario;
        if (inventario == "I" || inventario =="i"){

        }
        else if (inventario == "H" || inventario =="h"){
          cout << chunchunmaru.getHabilidad(1);
        }        
      }     

      string dialogo3 = "\nOcto-π : Ahora que estas preparado ve y derrotalos " + chunchunmaru.getNombre() + "\n";
      std::cout << slowly_printing_string{dialogo3, 10};
      string dialogo4 = "\nConforme vas avanzando en '" + piso1.getNombrePiso() + "' te encuentras con " + piso1.getNombreBoss() + ", " + piso1.getDescripcionBoss() + "\nTendras que derrotarlo si quieres pasar al siguiente piso\n\n";
      std::cout << slowly_printing_string{dialogo4, 10};
      bool encuentro1;
      encuentro1=piso1.encuentro(&chunchunmaru, &piso1);
      if (encuentro1==true){
        std::cout << slowly_printing_string{"Ahora que venciste vas a pasar a la siguiente zona", 10};
        //definir siguiente zona
      }
      else{
        bandera=false;
      }

    }
    else if (opcion==3){
      cout << "Nos vemos, aventurero de las profundidades. \n";
    }
    else {
      cout <<"Opcion Invalida \n";
    }
  }
  std::cout << pocionVida.toString();
};
