#include "Instrucciones.h"
#include "juego.h"
#include "NIVEL1.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
using namespace sf;
using namespace std;

instrucciones::instrucciones(int resolucion_x, int resolucion_y, std::string titulo)
{
#pragma region Ventana y fonado 

	fps = 60;

	VENTANA_ins = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	VENTANA_ins->setFramerateLimit(fps);
	//
	//FONDO
	//
	rectangulo_Fondo = new RectangleShape();
	textura_Fondo = new Texture();

	textura_Fondo->loadFromFile("Fondo_menu.jpg");
	rectangulo_Fondo->setTexture(textura_Fondo);
	rectangulo_Fondo->setSize(Vector2f(1500, 1500));
	rectangulo_Fondo->setPosition(550, 300);
	rectangulo_Fondo->setOrigin(rectangulo_Fondo->getGlobalBounds().width / 2, rectangulo_Fondo->getGlobalBounds().height / 2);
	//
	//Fuente
	//
	fuente = new Font();
	fuente->loadFromFile("Fuente.ttf");
	//
	//Titulo
	//
	TXT_Titulo = new Text();
	TXT_Titulo->setFont(*fuente);

	TXT_Titulo->setFillColor(Color::Cyan);
	TXT_Titulo->setString("Ball Sort puzzle");
	TXT_Titulo->setPosition(10,10);
	TXT_Titulo->setCharacterSize(50);

#pragma endregion Ventana y fonado 

#pragma region Botones

	//Menu
	TXT_Menu = new Text();
	TXT_Menu->setFont(*fuente);
	TXT_Menu->setFillColor(Color::Cyan);
	TXT_Menu->setString("Menu");
	TXT_Menu->setPosition(33, 550);
	TXT_Menu->setCharacterSize(40);
	//Instrucciones
	TXT_instrucciones = new Text();
	TXT_instrucciones->setFont(*fuente);
	TXT_instrucciones->setFillColor(Color::White);
	TXT_instrucciones->setString("Instrucciones");
	TXT_instrucciones->setPosition(370, 70);
	TXT_instrucciones->setCharacterSize(40);
	//Salir
	TXT_salir = new Text();
	TXT_salir->setFont(*fuente);
	TXT_salir->setFillColor(Color::Cyan);
	TXT_salir->setString("Salir");
	TXT_salir->setPosition(950, 550);
	TXT_salir->setCharacterSize(40);

	//Menu
	rect_Menu = new RectangleShape();
	rect_Menu->setPosition(33, 550);
	rect_Menu->setFillColor(Color::Black);
	rect_Menu->setSize(Vector2f(116, 50));
	//Salir
	rect_salir = new RectangleShape();
	rect_salir->setPosition(950, 550);
	rect_salir->setFillColor(Color::Black);
	rect_salir->setSize(Vector2f(119, 50));

#pragma endregion Botones

#pragma region Instrucciones 
	
	//TXT_salir = new Text();
	//TXT_salir->setFont(*fuente);
	//TXT_salir->setFillColor(Color::Cyan);
	//TXT_salir->setString("Salir");
	//TXT_salir->setPosition(950, 550);
	//TXT_salir->setCharacterSize(40);

	//Fuente Fresco Stamp   Fuente mytype

	fuente2 = new Font();
	fuente2->loadFromFile("Fuente mytype.ttf");
	for (int i = 0;  i < 11;  i++)
	{
		TXT_todas_instrucciones[i] = new Text();
		TXT_todas_instrucciones[i]->setFont(*fuente2);
		TXT_todas_instrucciones[i]->setFillColor(Color::Black);
		TXT_todas_instrucciones[i]->setCharacterSize(22); 
	}
	TXT_todas_instrucciones[0]->setString("=Debe colocar todas las bolas del mismo color en un contenedor o tubo.");
	TXT_todas_instrucciones[0]->setPosition(10, 120);
	TXT_todas_instrucciones[1]->setString("=Unicamente puede mover la bola superior es decir la bola que esta en la ");
	TXT_todas_instrucciones[1]->setPosition(10, 145);
	TXT_todas_instrucciones[2]->setString("  parte de arriba del tubo.");
	TXT_todas_instrucciones[2]->setPosition(10, 170);
	TXT_todas_instrucciones[3]->setString("=Para poder mover una bola de uno de los tubos al otro debe tocar la superficie ");
	TXT_todas_instrucciones[3]->setPosition(10, 195);
	TXT_todas_instrucciones[4]->setString("  del primero y despues del segundo para moverla.");
	TXT_todas_instrucciones[4]->setPosition(10, 220);
	TXT_todas_instrucciones[5]->setString("=Tiene la posibilidad de deshacer unicamente 5 pasos por nivel, si el nivel es");
	TXT_todas_instrucciones[5]->setPosition(10, 245);
	TXT_todas_instrucciones[6]->setString("	reiniciado el conteo de deshacer los movimientos vuelve a 5.");
	TXT_todas_instrucciones[6]->setPosition(10, 270);

	TXT_todas_instrucciones[7]->setString("=Tiene una opción de ver la repeticion de la partida, podra ver la repeticion ");
	TXT_todas_instrucciones[7]->setPosition(10, 295);
	TXT_todas_instrucciones[8]->setString("	cuando allá terminado la partida. ");
	TXT_todas_instrucciones[8]->setPosition(10, 320);
	TXT_todas_instrucciones[9]->setString("=Para pasar al siguiente nivel debe colocar todas las botas del mismo color ");
	TXT_todas_instrucciones[9]->setPosition(10, 345);
	TXT_todas_instrucciones[10]->setString("	en un contenedor o tubo.");
	TXT_todas_instrucciones[10]->setPosition(10, 370);

#pragma endregion Instrucciones

	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	evento1 = new Event();
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	reloj1 = new Clock();
	tiempo_reloj1 = new Time();
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	gameLoob();
}

void instrucciones::dibujar() {

	VENTANA_ins->clear();
	//dibujar
	VENTANA_ins->draw(*rectangulo_Fondo);
	VENTANA_ins->draw(*TXT_Titulo);

	VENTANA_ins->draw(*rect_Menu);
	VENTANA_ins->draw(*rect_salir);

	VENTANA_ins->draw(*TXT_Menu);
	VENTANA_ins->draw(*TXT_instrucciones);
	VENTANA_ins->draw(*TXT_salir);

	for (int i = 0; i < 11; i++)
	{
		VENTANA_ins->draw(*TXT_todas_instrucciones[i]);
	}

	VENTANA_ins->display();

}

void instrucciones::gameLoob() {
	while (VENTANA_ins->isOpen()) {

		rectangulo_Fondo->setRotation(float(rectangulo_Fondo->getRotation() + 0.5));

		procesar_mouse();
		procesar_eventos();
		dibujar();
		*tiempo_reloj1 = reloj1->getElapsedTime();
		//reloj1->restart();
		//cout << tiempo_reloj1->asSeconds() << endl;
	}

}

void instrucciones::procesar_eventos() {

	while (VENTANA_ins->pollEvent(*evento1))//mientras alla un evento que escuchar repodir esto
	{
		switch (evento1->type)
		{
		case Event::Closed:
			VENTANA_ins->close();
			exit(1);
			break;

		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i posicion_Mouse;
				posicion_Mouse = Mouse::getPosition(*VENTANA_ins);
				posicion_Mouse = (Vector2i)VENTANA_ins->mapPixelToCoords(posicion_mouse);

				cout << posicion_Mouse.x << "--" << posicion_Mouse.y << endl;

				if (rect_Menu->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_Menu->setFillColor(Color::Blue);
					VENTANA_ins->close();
					menu* MENU = new menu(1100, 600, "Menu");
				}
				if (rect_salir->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_salir->setFillColor(Color::Blue);
					VENTANA_ins->close();
					exit(1);
				}
			}

		default:
			break;
		}
	}
}

void instrucciones::procesar_mouse()
{
	posicion_mouse = Mouse::getPosition(*VENTANA_ins);
	posicion_mouse = (Vector2i)VENTANA_ins->mapPixelToCoords(posicion_mouse);  //cambiar de pixeles a cordenas 
}
