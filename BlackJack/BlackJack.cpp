// BlackJack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>  
#include<time.h>  
#include<windows.h>  
#include<string.h>  
#include <cmath>
#include <cstring>
#include <clocale>
#include <cstring>

using namespace std;

//atributos jugador
string jugador;
int puntosJugador = 0;
bool derrota = false;
bool victoria = false;
bool rendirse = false;

//atributos del Crupiere
string crupi = "Gilbau";
int puntosCrupi = 0;
bool derrota2 = false;
bool victoria2 = false;
bool rendirse2 = false;

//atributos de las cartas
int picas [13];
int diamantes [13];
int treboles [13];
int corazones [13];

int opcion = 0;
int eleccion = 0;

bool loPuntoh(int& puntosJugador, bool& victoria, bool& derrota);
void introduccion() {

	cout << "============================================================================\n";
	cout << "=                                BLACK JACK                                =\n";
	cout << "=                             Solo para Ludopatas                          =\n";
	cout << "============================================================================\n";
	cout << "Bienvenido, como se llama usted?" <<" " << jugador;
	cin >> jugador;
	cout << jugador << " " <<"no se admite comida y bebidas externas, si quieres algo, te lo compras aqui\n";
	Sleep(2500);
	cout << "Estamos apunto de empezar la partida. Voy a citar como ira el juego\n";
	Sleep(2000);
	cout<<"A usted " << jugador << " se le entregaran 2 cartas \n";
	Sleep(2000);
	cout << "A usted " << crupi << " se le asignara 1 carta \n";
	Sleep(2000);
	cout << "Hay que llegar a 21 o acercarse lo maximo possible.\n";
	Sleep(2000);
	cout << "Si se pasan de 21 pierden instantaneamente. Si no llegan a 21 gana el que mas cerca este.\n";
	Sleep(2000);
	cout << "Caballeros, que empieze la partida\n";
	Sleep(2000);

}
//para ver cuando se repite una carta
void arrayCartas(int(&arraCard)[13]) {
	for (int i = 0; i < 13; i++) {
		arraCard[i] = 1;
	}
}
//se reparten las cartas para los jugadores y vemos los puntos que tienen cada 1
void repartirCartas(string jugador, int& totalpoints) {
	bool choosed = false;
	//variables y tipos  de las cartas
	int cartas = 0;
	int paloCarta;
	string tipoCarta;

	while (!choosed) {
		//carta random del 1 al 12
		paloCarta = rand() % 4;
		cartas = rand() % 13;
		if (paloCarta == 0) {
			if (picas[cartas] == 1) {
				picas[cartas] = 0;
				choosed = true;
				tipoCarta = "Picas";

			}
		}
		else if (paloCarta == 1) {
			if (diamantes[cartas] == 1) {
				diamantes[cartas] = 0;
				choosed = true;
				tipoCarta = "Diamantes";
			}
		}
		else if (paloCarta == 2) {
			if (treboles[cartas] == 1) {
				treboles[cartas] = 0;
				choosed = true;
				tipoCarta = "Treboles";
			}
		}
		else if (paloCarta == 3) {
			if (corazones[cartas] == 1) {
				corazones[cartas] = 0;
				choosed = true;
				tipoCarta = "Corazones";
			}
		}
	}

	if (cartas == 0) {
		if (crupi == "Gilbau") {
			if (totalpoints <= 10) {
				totalpoints += 11;
			}
			else {
				totalpoints += 1;
			}
			cout << jugador << "ha sacado un AS DE " << tipoCarta << " y tiene un total de " << totalpoints << "\n";
		}
		else {

			do {
				cout << "Quieres que cuente como un 1 o como un 11? \n";
				cin >> eleccion;
				if (eleccion == 1) {
					totalpoints += 1;
				}
				else if (eleccion == 11) {
					totalpoints += 11;
				}
			} while (eleccion != 1 && eleccion != 11);
		}
	}

	else if (cartas > 9) {
		totalpoints += 10;
	}

	else {

		totalpoints += cartas + 1;
	}

	if (cartas == 10) {
		cout << jugador << " ha sacado una J de " << tipoCarta << " y tiene un total de " << totalpoints << "\n";
	}

	else if (cartas == 11) {
		cout << jugador << " ha sacado una Qde " << tipoCarta << " y tiene un total de " << totalpoints << "\n";
	}

	else if (cartas == 12) {
		cout << jugador << " ha sacado una K de " << tipoCarta << " y tiene un total de " << totalpoints << "\n";
	}
	 else{
	
	Sleep(2000);

	totalpoints += cartas + 1;
	cout << jugador << " ha sacado un " << cartas + 1 << " de " << tipoCarta << " y tiene un total de " << totalpoints << "\n";

	}

	}


//comprovaciones

bool loPuntoh(int& puntos, bool& victoria, bool& derrota) {
    if(puntos == 21){
		victoria = true;
        return true;
	
    }else if(puntos > 21){
       derrota= true;
	   
	   return true;
	
    }
	return false;
  
}




bool QuienZeForra(int puntosJugador, int puntosCrupi, bool victoria2){
    
	if(puntosCrupi > puntosJugador){
       victoria2 = true;
        return true;
    }
	
	else{
		return false;
    }
}




int main(){

	srand(time(NULL));

	arrayCartas(picas);
	arrayCartas(diamantes);
	arrayCartas(treboles);
	arrayCartas(corazones);
	Sleep(1000);
	introduccion();
	repartirCartas(jugador, puntosJugador);
	repartirCartas(jugador, puntosJugador);
	rendirse = QuienZeForra(puntosJugador, victoria, derrota);
	repartirCartas(crupi, puntosCrupi);

	cout << "---------------------------------------------------\n";
     

	while (!rendirse) {

		int opcion = 0;
		while (opcion != 1 && opcion != 2) {
			cout << jugador << " " << "Quieres otra carta o te plantas? \n";
			cout << " 1. CARTA AQUI \n";
			cout << " 2. ME PLANTO, SOY UN CAGAO \n";
			cout << "\n";
			cin >> opcion;
		}

		if (opcion == 1) {
			repartirCartas(jugador, puntosJugador);
			rendirse = loPuntoh(puntosJugador, victoria, derrota);
		}

		else {
			rendirse = true;
		}
	}
	//frases para el jugador
	 if (victoria && victoria2) {
		 cout << "Habeis empatado la partida, os lo repartis en partes iguales \n";
	 }
	 else if (victoria) {
		 cout << jugador << "has conseguido forrarte y arruinar a " << crupi << "\n";
	 }
	 else if (derrota){
		 cout << "HAS PERIDO ERES UN INUTIL \n";
	 }
	 else {
		
		 while (!rendirse2) {
			 repartirCartas(crupi, puntosCrupi);
			 rendirse2 = loPuntoh(puntosCrupi, victoria2, derrota2);

			 if (!rendirse2) {

				 rendirse2 = QuienZeForra(puntosJugador, puntosCrupi, victoria2);
			 }
		 }
		 //FRASES DEL CRUPIER
			 if (victoria && victoria2) {
				 cout << "Habeis empatado la partida, os lo repartis en partes iguales \n";
			 }
			 else if (victoria2) {
				 cout << crupi << "has conseguido forrarte y arruinar a " << jugador << "\n";
			 }
			 else if (derrota2) {
				 cout << "Crupier has perdido, no sirves para nada \n";
			 }
	 }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
