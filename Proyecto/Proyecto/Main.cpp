#include "SFML/Graphics.hpp"
#include "juego.h"
#include "Menu.h"
#include <iostream>
#include "NIVEL1.h"
#include "NIVEL2.h"
#include "NIVEL3.h"
#include "NIVEL4.h"
#include "NIVEL5.h"
#include "Instrucciones.h"

using namespace sf;
using namespace std;

int main() {

	menu* MENU = new menu(1100, 600, "Menu");

	//nivel1* NIVEL1 = new nivel1(1100, 600, "NIVEL 1");

	//nivel2* NIVEL2 = new nivel2(1100, 600, "NIVEL 2");

	//nivel3* NIVEL = new nivel3(1100, 600, "NIVEL 3");

	 //nivel4 * NIVEL = new nivel4(1100, 600, "NIVEL 4");

	 //nivel5* NIVEL = new nivel5(1100, 600, "NIVEL 5");

	//instrucciones ins = instrucciones(1100, 600, "INSTRUCCIONES");

	///////////////////////

	//bool GAME_OVER = false;
	//RenderWindow* VENTANA;

	//VENTANA = new RenderWindow(VideoMode(800, 500, 32), "PROYECTO");
	//
	//VENTANA->setFramerateLimit(60);//fps de la ventana 

	//while (!GAME_OVER) {
	//	VENTANA->clear(Color::Cyan);
	//	VENTANA->display();

	//}


	return 0;
}