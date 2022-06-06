#include "Menu.h"
#include "juego.h"
#include "NIVEL1.h"
#include "Instrucciones.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;

menu::menu(int resolucion_x, int resolucion_y, std::string titulo)
{
	fps = 60;

	VENTANA_menu = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	VENTANA_menu->setFramerateLimit(fps);
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
	TXT_Titulo->setPosition(275, 10);
	TXT_Titulo->setCharacterSize(50);

	//
	//Botones
	//

	//Nuevo Juego
	TXT_jugar = new Text();
	TXT_jugar->setFont(*fuente);
	TXT_jugar->setFillColor(Color::Cyan);
	TXT_jugar->setString("Nuevo Juego");
	TXT_jugar->setPosition(380, 200);
	TXT_jugar->setCharacterSize(40);
	//Instrucciones
	TXT_instrucciones = new Text();
	TXT_instrucciones->setFont(*fuente);
	TXT_instrucciones->setFillColor(Color::Cyan);
	TXT_instrucciones->setString("Instrucciones");
	TXT_instrucciones->setPosition(370, 350);
	TXT_instrucciones->setCharacterSize(40);
	//Salir
	TXT_salir = new Text();
	TXT_salir->setFont(*fuente);
	TXT_salir->setFillColor(Color::Cyan);
	TXT_salir->setString("Salir");
	TXT_salir->setPosition(480, 500);
	TXT_salir->setCharacterSize(40);
	
	//Jugar
	rect_Jugar = new RectangleShape();
	rect_Jugar->setPosition(380, 200);
	rect_Jugar->setFillColor(Color::Black);
	rect_Jugar->setSize(Vector2f(308, 50));
	//Instrucciones
	rect_instrucciones = new RectangleShape();
	rect_instrucciones->setPosition(370, 350);
	rect_instrucciones->setFillColor(Color::Black);
	rect_instrucciones->setSize(Vector2f(335, 50));
	//Salir
	rect_salir = new RectangleShape();
	rect_salir->setPosition(480, 500);
	rect_salir->setFillColor(Color::Black);
	rect_salir->setSize(Vector2f(119, 50));
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

void menu::dibujar() {

	VENTANA_menu->clear();
	//dibujar
	VENTANA_menu->draw(*rectangulo_Fondo);
	VENTANA_menu->draw(*TXT_Titulo);
	
	VENTANA_menu->draw(*rect_Jugar);
	VENTANA_menu->draw(*rect_instrucciones);
	VENTANA_menu->draw(*rect_salir);
	
	VENTANA_menu->draw(*TXT_jugar);
	VENTANA_menu->draw(*TXT_instrucciones);
	VENTANA_menu->draw(*TXT_salir);

	VENTANA_menu->display();

}

void menu::gameLoob() {
	while (VENTANA_menu->isOpen()) {

		rectangulo_Fondo->setRotation(rectangulo_Fondo->getRotation() + 0.5);

		procesar_mouse();
		procesar_eventos();
		dibujar();
		*tiempo_reloj1 = reloj1->getElapsedTime();
		//reloj1->restart();
		//cout << tiempo_reloj1->asSeconds() << endl;
	}

}

void menu::procesar_eventos() {

	while (VENTANA_menu->pollEvent(*evento1))//mientras alla un evento que escuchar repodir esto
	{
		switch (evento1->type)
		{
		case Event::Closed:
			VENTANA_menu->close();
			exit(1);
			break;

		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i posicion_Mouse;
				posicion_Mouse = Mouse::getPosition(*VENTANA_menu);
				posicion_Mouse = (Vector2i)VENTANA_menu->mapPixelToCoords(posicion_mouse);

				cout << posicion_Mouse.x << "--" << posicion_Mouse.y << endl;

				if (rect_Jugar->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_Jugar->setFillColor(Color::Blue);
					VENTANA_menu->close();
					nivel1* NIVEL1 = new nivel1(1100, 600, "NIVEL 1");
				}
				if (rect_instrucciones->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_instrucciones->setFillColor(Color::Blue);
					VENTANA_menu->close();
					instrucciones* Instrucciones = new instrucciones(1100, 600, "Instrucciones");
				}
				if (rect_salir->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_salir->setFillColor(Color::Blue);
					VENTANA_menu->close();
					exit(1);
				}
			}

		default:
			break;
		}
	}
}

void menu::procesar_mouse()
{
	posicion_mouse = Mouse::getPosition(*VENTANA_menu);
	posicion_mouse = (Vector2i)VENTANA_menu->mapPixelToCoords(posicion_mouse);  //cambiar de pixeles a cordenas 
}
