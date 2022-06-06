#include "NIVEL1.h"
#include "juego.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "nivel4.h"
#include "NIVEL5.h"

#include <windows.h>
#include <stdio.h>

using namespace sf;
using namespace std;

nivel4::nivel4(int resolucion_x, int resolucion_y, std::string titulo)
{

#pragma region ventana y fondo
	fps = 60;

	VENTANA_Level = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	VENTANA_Level->setFramerateLimit(fps);
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

	//TXT_Titulo->setFillColor(Color::Red);

	Color cppp = sf::Color::Red;
	TXT_Titulo->setFillColor(Color::Red);

	TXT_Titulo->setString("NIVEL 4");
	TXT_Titulo->setPosition(25, 10);
	TXT_Titulo->setCharacterSize(50);
#pragma endregion ventana y fondo

#pragma region Botones

	//Nuevo Juego
	TXT_nextLevel = new Text();
	TXT_nextLevel->setFont(*fuente);
	TXT_nextLevel->setFillColor(Color::Cyan);
	TXT_nextLevel->setString("Siguiente Nivel");
	TXT_nextLevel->setPosition(720, 15);
	TXT_nextLevel->setCharacterSize(40);
	//Instrucciones
	TXT_menu = new Text();
	TXT_menu->setFont(*fuente);
	TXT_menu->setFillColor(Color::Cyan);
	TXT_menu->setString("Menu");
	TXT_menu->setPosition(550, 15);
	TXT_menu->setCharacterSize(40);
	//Salir
	TXT_salir = new Text();
	TXT_salir->setFont(*fuente);
	TXT_salir->setFillColor(Color::Cyan);
	TXT_salir->setString("Salir");
	TXT_salir->setPosition(965, 545);
	TXT_salir->setCharacterSize(40);

	///////////////////////////////////

	//nextLevel 
	rect_nextLevel = new RectangleShape();
	rect_nextLevel->setPosition(720, 15);
	rect_nextLevel->setFillColor(Color::Black);
	//rect_nextLevel->setTexture(textura_contenedor);
	rect_nextLevel->setSize(Vector2f(365, 50));

	//menu
	rect_menu = new RectangleShape();
	rect_menu->setPosition(550, 15);
	rect_menu->setFillColor(Color::Black);
	rect_menu->setSize(Vector2f(116, 50));

	//Salir
	rect_salir = new RectangleShape();
	rect_salir->setPosition(965, 545);
	rect_salir->setFillColor(Color::Black);
	rect_salir->setSize(Vector2f(119, 50));

	//reinicar 
	TXT_reiniciar = new Text();
	TXT_reiniciar->setFont(*fuente);
	TXT_reiniciar->setFillColor(Color::Cyan);
	TXT_reiniciar->setString("Reinicar");
	TXT_reiniciar->setPosition(15, 545);
	TXT_reiniciar->setCharacterSize(40);

	rect_reiniciar = new RectangleShape();
	rect_reiniciar->setPosition(15, 545);
	rect_reiniciar->setFillColor(Color::Black);
	rect_reiniciar->setSize(Vector2f(190, 50));

	//movimientos 
	TXT_repeticion = new Text();
	TXT_repeticion->setFont(*fuente);
	TXT_repeticion->setFillColor(Color::Cyan);
	TXT_repeticion->setString("Ver repeticion");
	TXT_repeticion->setPosition(720, 80);
	TXT_repeticion->setCharacterSize(40);

	rect_repeticion = new RectangleShape();
	rect_repeticion->setPosition(720, 80);
	rect_repeticion->setFillColor(Color::Black);
	rect_repeticion->setSize(Vector2f(345, 50));

	//retroceder pasos
	rectangulo_retroceder = new RectangleShape();
	textura_retroceder = new Texture();

	textura_retroceder->loadFromFile("re.png");
	rectangulo_retroceder->setTexture(textura_retroceder);
	rectangulo_retroceder->setSize(Vector2f(50, 50));
	rectangulo_retroceder->setPosition(620, 80);

	Cont_retrocesos = 5;

	Contxt_retrosesos = new Text();
	Contxt_retrosesos->setFont(*fuente);
	Contxt_retrosesos->setString("5");
	Contxt_retrosesos->setPosition(550, 80);
	Contxt_retrosesos->setCharacterSize(40);
#pragma endregion Botones

#pragma region Bolas
	for (int i = 0; i < 6; i++)
	{
		texture_color[i] = new Texture();
	}
	texture_color[0]->loadFromFile("Amarillo.PNG");
	texture_color[1]->loadFromFile("Rojo.PNG");
	texture_color[2]->loadFromFile("Azul.PNG");
	texture_color[3]->loadFromFile("Verde.PNG");
	texture_color[4]->loadFromFile("Celeste.png");
	texture_color[5]->loadFromFile("SinFondo.png");

	for (int i = 0; i < 36; i++)
	{
		Bolas[i] = new CircleShape();
		Bolas[i]->setRadius(32);
		Bolas[i]->setTexture(texture_color[5]);
		Bolas[i]->setOrigin(Bolas[i]->getGlobalBounds().width / 2, Bolas[i]->getGlobalBounds().height / 2);
	}

	//pila 1
	Bolas[0]->setPosition(123, 379);
	Bolas[1]->setPosition(123, 318);
	Bolas[2]->setPosition(123, 257);
	Bolas[3]->setPosition(123, 196);
	//pila 2
	Bolas[4]->setPosition(333, 379);
	Bolas[5]->setPosition(333, 318);
	Bolas[6]->setPosition(333, 257);
	Bolas[7]->setPosition(333, 196);
	//pila 3
	Bolas[8]->setPosition(553, 379);
	Bolas[9]->setPosition(553, 318);
	Bolas[10]->setPosition(553, 257);
	Bolas[11]->setPosition(553, 196);
	//pila 4
	Bolas[12]->setPosition(773, 379);
	Bolas[13]->setPosition(773, 318);
	Bolas[14]->setPosition(773, 257);
	Bolas[15]->setPosition(773, 196);
	//pila 5
	Bolas[16]->setPosition(993, 379);
	Bolas[17]->setPosition(993, 318);
	Bolas[18]->setPosition(993, 257);
	Bolas[19]->setPosition(993, 196);
	//pila 6
	Bolas[20]->setPosition(443, 519);
	Bolas[21]->setPosition(443, 458);
	Bolas[22]->setPosition(443, 397);
	Bolas[23]->setPosition(443, 336);
	//pila 7
	Bolas[24]->setPosition(663, 519);
	Bolas[25]->setPosition(663, 458);
	Bolas[26]->setPosition(663, 397);
	Bolas[27]->setPosition(663, 336);

	//pila 8
	Bolas[28]->setPosition(233, 519);
	Bolas[29]->setPosition(233, 458);
	Bolas[30]->setPosition(233, 397);
	Bolas[31]->setPosition(233, 336);

	//pila 9
	Bolas[32]->setPosition(889, 519);
	Bolas[33]->setPosition(889, 458);
	Bolas[34]->setPosition(889, 397);
	Bolas[35]->setPosition(889, 336);
#pragma endregion Bolas

#pragma region contenedores

	texture_contenedor = new Texture();
	texture_contenedor->loadFromFile("contenedor.png");
	for (int i = 0; i < 9; i++)
	{
		Contenedores[i] = new RectangleShape();
		Contenedores[i]->setSize(Vector2f(75, 255));
		Contenedores[i]->setTexture(texture_contenedor);
		Contenedores[i]->setFillColor(Color::Black);
	}
	//1
	Contenedores[0]->setPosition(85, 160);
	//2
	Contenedores[1]->setPosition(295, 160);
	//3
	Contenedores[2]->setPosition(515, 160);
	//4
	Contenedores[3]->setPosition(735, 160);
	//5
	Contenedores[4]->setPosition(955, 160);
	//6
	Contenedores[5]->setPosition(405, 300);
	//7
	Contenedores[6]->setPosition(624, 300);
	//8
	Contenedores[7]->setPosition(195, 300);
	//9
	Contenedores[8]->setPosition(850, 300);
#pragma endregion contenedores

#pragma region Pilas

	push(PILA1, 4);
	push(PILA1, 3);
	push(PILA1, 0);
	push(PILA1, 1);
	colocar_colores_pilas(PILA1, 1);

	push(PILA2, 4);
	push(PILA2, 0);
	push(PILA2, 3);
	push(PILA2, 1);
	colocar_colores_pilas(PILA2, 2);

	push(PILA3, 0);
	push(PILA3, 2);
	push(PILA3, 4);
	push(PILA3, 1);
	colocar_colores_pilas(PILA3, 3);

	push(PILA4, 4);
	push(PILA4, 2);
	push(PILA4, 3);
	push(PILA4, 4);
	colocar_colores_pilas(PILA4, 4);

	push(PILA5, 4);
	push(PILA5, 0);
	push(PILA5, 2);
	push(PILA5, 3);
	colocar_colores_pilas(PILA5, 5);

	push(PILA6, 4);
	push(PILA6, 3);
	push(PILA6, 3);
	push(PILA6, 4);
	colocar_colores_pilas(PILA6, 6);
	//
	push(PILA7, 2);
	push(PILA7, 3);
	push(PILA7, 0);
	//push(PILA7, 0);
	colocar_colores_pilas(PILA7, 7);

	push(PILA8, 3);
	//push(PILA8, 0);
	//push(PILA8, 1);
	//push(PILA8, 0);
	colocar_colores_pilas(PILA8, 8);

	push(PILA9, 0);
	push(PILA9, 0);
	push(PILA9, 1);
	push(PILA9, 0);
	colocar_colores_pilas(PILA9, 9);
#pragma endregion Pilas


#pragma region Botones de las pilas 

	for (int i = 0; i < 9; i++)
	{
		btn_pilas[i] = new RectangleShape;
		btn_pilas[i]->setFillColor(Color::Black);
		btn_pilas[i]->setSize(Vector2f(75, 5));
	}
	//1
	btn_pilas[0]->setPosition(85, 150);
	//2
	btn_pilas[1]->setPosition(295, 150);
	//3
	btn_pilas[2]->setPosition(515, 150);
	//4
	btn_pilas[3]->setPosition(735, 150);
	//5
	btn_pilas[4]->setPosition(955, 150);
	//6
	btn_pilas[5]->setPosition(405, 290);
	//7
	btn_pilas[6]->setPosition(624, 290);
	//8
	btn_pilas[7]->setPosition(195, 290);
	//9
	btn_pilas[8]->setPosition(850, 290);

#pragma endregion Botones de las pilas 


#pragma region Eventos
	evento1 = new Event();
#pragma endregion Eventos

#pragma region time
	reloj1 = new Clock();
	tiempo_reloj1 = new Time();
#pragma endregion time
	GuardarMovimientos();
	gameLoob();
}

void nivel4::dibujar() {

	VENTANA_Level->clear();
	//dibujar
	VENTANA_Level->draw(*rectangulo_Fondo);
	VENTANA_Level->draw(*TXT_Titulo);

	VENTANA_Level->draw(*rect_nextLevel);
	VENTANA_Level->draw(*rect_menu);
	VENTANA_Level->draw(*rect_salir);

	VENTANA_Level->draw(*TXT_nextLevel);
	VENTANA_Level->draw(*TXT_menu);
	VENTANA_Level->draw(*TXT_salir);

	VENTANA_Level->draw(*rect_reiniciar);
	VENTANA_Level->draw(*TXT_reiniciar);

	VENTANA_Level->draw(*rect_repeticion);
	VENTANA_Level->draw(*TXT_repeticion);

	VENTANA_Level->draw(*rectangulo_retroceder);
	VENTANA_Level->draw(*Contxt_retrosesos);

	for (int i = 0; i < 36; i++)
	{
		VENTANA_Level->draw(*Bolas[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		VENTANA_Level->draw(*Contenedores[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		VENTANA_Level->draw(*btn_pilas[i]);
	}

	VENTANA_Level->display();

}

void nivel4::gameLoob() {
	while (VENTANA_Level->isOpen()) {

		rectangulo_Fondo->setRotation(rectangulo_Fondo->getRotation() + 0.5);
		rect_nextLevel->setFillColor(Color::Black);

		procesar_mouse();
		procesar_eventos();
		colocar_colores_pilas(PILA1, 1);
		colocar_colores_pilas(PILA2, 2);
		colocar_colores_pilas(PILA3, 3);
		colocar_colores_pilas(PILA4, 4);
		colocar_colores_pilas(PILA5, 5);
		colocar_colores_pilas(PILA6, 6);
		colocar_colores_pilas(PILA7, 7);
		colocar_colores_pilas(PILA8, 8);
		colocar_colores_pilas(PILA9, 9);
		dibujar();
		*tiempo_reloj1 = reloj1->getElapsedTime();
		//reloj1->restart();
		//cout << tiempo_reloj1->asSeconds() << endl;
	}
}

void nivel4::procesar_eventos() {

	while (VENTANA_Level->pollEvent(*evento1))//mientras alla un evento que escuchar repodir esto
	{
		switch (evento1->type)
		{
		case Event::Closed:
			VENTANA_Level->close();
			exit(1);
			break;

		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {

				Vector2i posicion_Mouse;
				posicion_Mouse = Mouse::getPosition(*VENTANA_Level);
				posicion_Mouse = (Vector2i)VENTANA_Level->mapPixelToCoords(posicion_mouse);

				cout << posicion_Mouse.x << "--" << posicion_Mouse.y << endl;

#pragma region Eventos de los botones
				if (rect_menu->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_menu->setFillColor(Color::Blue);
					VENTANA_Level->close();
					menu* Menu = new menu(1100, 600, "Menu");
				}
				if (rect_nextLevel->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_nextLevel->setFillColor(Color::Blue);
					if (GAME_OVER(PILA1) == true && GAME_OVER(PILA2) == true && GAME_OVER(PILA3) == true && GAME_OVER(PILA4) == true 
						&& GAME_OVER(PILA5) == true && GAME_OVER(PILA6) == true && GAME_OVER(PILA7) == true && GAME_OVER(PILA8) == true
						&& GAME_OVER(PILA9) == true) {
						VENTANA_Level->close();
						nivel5* nivel = new nivel5(1100, 600, "NIVEL 5");
					}
				}
				if (rect_salir->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_salir->setFillColor(Color::Blue);
					VENTANA_Level->close();
					exit(1);
				}
				if (rect_reiniciar->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					rect_reiniciar->setFillColor(Color::Blue);
					VENTANA_Level->close();
					nivel4* nivel = new nivel4(1100, 600, "NIVEL 4");
				}
				if (rect_repeticion->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					if (GAME_OVER(PILA1) == true && GAME_OVER(PILA2) == true && GAME_OVER(PILA3) == true && GAME_OVER(PILA4) == true 
						&& GAME_OVER(PILA5) == true && GAME_OVER(PILA6) == true && GAME_OVER(PILA7) == true && GAME_OVER(PILA8) == true
						&& GAME_OVER(PILA9) == true) {
						rect_repeticion->setFillColor(Color::Blue);
						MostrarRepeticion(MOVIMIENTOS);
						rect_repeticion->setFillColor(Color::Black);
					}
					
				}
				if (rectangulo_retroceder->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					regresarPasos(MOVIMIENTOS);
				}
#pragma endregion Eventos de los botones

#pragma region Eventos de las pilas 

				if (Contenedores[0]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[0]->setFillColor(Color::Cyan);
					btn_pilas[0]->setFillColor(Color::Cyan);
					if (Primero == "") {
						Primero = "1";
					}
					else if (Segundo == "") {
						Segundo = "1";
					}
				}
				if (Contenedores[1]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[1]->setFillColor(Color::Cyan);
					btn_pilas[1]->setFillColor(Color::Cyan);
					if (Primero == "") {
						Primero = "2";
					}
					else if (Segundo == "") {
						Segundo = "2";
					}
				}
				if (Contenedores[2]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[2]->setFillColor(Color::Cyan);
					btn_pilas[2]->setFillColor(Color::Cyan);
					if (Primero == "") {
						Primero = "3";
					}
					else if (Segundo == "") {
						Segundo = "3";
					}
				}
				if (Contenedores[3]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[3]->setFillColor(Color::Cyan);
					btn_pilas[3]->setFillColor(Color::Cyan);
					if (Primero == "") {
						Primero = "4";
					}
					else if (Segundo == "") {
						Segundo = "4";
					}
				}
				if (Contenedores[4]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[4]->setFillColor(Color::Cyan);
					btn_pilas[4]->setFillColor(Color::Cyan);

					if (Primero == "") {
						Primero = "5";
					}
					else if (Segundo == "") {
						Segundo = "5";
					}
				}
				if (Contenedores[5]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[5]->setFillColor(Color::Cyan);
					btn_pilas[5]->setFillColor(Color::Cyan);

					if (Primero == "") {
						Primero = "6";
					}
					else if (Segundo == "") {
						Segundo = "6";
					}
				}
				if (Contenedores[6]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[6]->setFillColor(Color::Cyan);
					btn_pilas[6]->setFillColor(Color::Cyan);

					if (Primero == "") {
						Primero = "7";
					}
					else if (Segundo == "") {
						Segundo = "7";
					}
				}
				if (Contenedores[7]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[7]->setFillColor(Color::Cyan);
					btn_pilas[7]->setFillColor(Color::Cyan);

					if (Primero == "") {
						Primero = "8";
					}
					else if (Segundo == "") {
						Segundo = "8";
					}
				}
				if (Contenedores[8]->getGlobalBounds().contains(posicion_Mouse.x, posicion_Mouse.y)) {
					Contenedores[8]->setFillColor(Color::Cyan);
					btn_pilas[8]->setFillColor(Color::Cyan);

					if (Primero == "") {
						Primero = "9";
					}
					else if (Segundo == "") {
						Segundo = "9";
					}
				}
				if (Primero != "" && Segundo != "") {
					Movimiento_entre_pilas();
				}
#pragma endregion Eventos de las pilas 


			}

		default:
			break;
		}
	}
}

void nivel4::procesar_mouse()
{
	posicion_mouse = Mouse::getPosition(*VENTANA_Level);
	posicion_mouse = (Vector2i)VENTANA_Level->mapPixelToCoords(posicion_mouse);  //cambiar de pixeles a cordenas 
}

void nivel4::push(pila& pil, int valor)
{
	pila aux;
	aux = new(struct nodo);
	aux->valor = valor;

	aux->N_siguiente = pil;
	pil = aux;
}

int nivel4::pop(pila& pil)
{
	int num;
	pila aux = NULL;

	aux = pil;
	num = aux->valor;

	pil = aux->N_siguiente;
	delete(aux);

	return num;
}

void nivel4::colocar_colores_pilas(pila pil, int i)
{
	///
	///1
	///
	int e = 0;
	int cont = 0;
	int numeros[4];
	if (i == 1) {
		while (pil != NULL && e < 4)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 0) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 1) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[0]->setTexture(texture_color[numeros[0]]);
		}
		if (e == 2) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[0]->setTexture(texture_color[numeros[1]]);
			Bolas[1]->setTexture(texture_color[numeros[0]]);
		}
		if (e == 3) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[0]->setTexture(texture_color[numeros[2]]);
			Bolas[1]->setTexture(texture_color[numeros[1]]);
			Bolas[2]->setTexture(texture_color[numeros[0]]);
		}
		if (e == 4) {
			Bolas[0]->setTexture(texture_color[numeros[3]]);
			Bolas[1]->setTexture(texture_color[numeros[2]]);
			Bolas[2]->setTexture(texture_color[numeros[1]]);
			Bolas[3]->setTexture(texture_color[numeros[0]]);
		}
	}
	///
	///2
	///
	int numeros2[4];
	e = 4;
	cont = 0;
	if (i == 2) {
		while (pil != NULL && e < 8)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros2[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 4) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 5) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[4]->setTexture(texture_color[numeros2[0]]);
		}
		if (e == 6) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[4]->setTexture(texture_color[numeros2[1]]);
			Bolas[5]->setTexture(texture_color[numeros2[0]]);
		}
		if (e == 7) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[4]->setTexture(texture_color[numeros2[2]]);
			Bolas[5]->setTexture(texture_color[numeros2[1]]);
			Bolas[6]->setTexture(texture_color[numeros2[0]]);
		}
		if (e == 8) {
			Bolas[4]->setTexture(texture_color[numeros2[3]]);
			Bolas[5]->setTexture(texture_color[numeros2[2]]);
			Bolas[6]->setTexture(texture_color[numeros2[1]]);
			Bolas[7]->setTexture(texture_color[numeros2[0]]);
		}
	}
	///
	///3
	///
	int numeros3[4];
	e = 8;
	cont = 0;
	if (i == 3) {
		while (pil != NULL && e < 12)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros3[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 8) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 9) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[8]->setTexture(texture_color[numeros3[0]]);
		}
		if (e == 10) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[8]->setTexture(texture_color[numeros3[1]]);
			Bolas[9]->setTexture(texture_color[numeros3[0]]);
		}
		if (e == 11) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[8]->setTexture(texture_color[numeros3[2]]);
			Bolas[9]->setTexture(texture_color[numeros3[1]]);
			Bolas[10]->setTexture(texture_color[numeros3[0]]);
		}
		if (e == 12) {
			Bolas[8]->setTexture(texture_color[numeros3[3]]);
			Bolas[9]->setTexture(texture_color[numeros3[2]]);
			Bolas[10]->setTexture(texture_color[numeros3[1]]);
			Bolas[11]->setTexture(texture_color[numeros3[0]]);
		}
	}
	///
	///4
	///
	int numeros4[4];
	e = 12;
	cont = 0;
	if (i == 4) {
		while (pil != NULL && e < 16)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros4[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 12) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 13) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[12]->setTexture(texture_color[numeros4[0]]);
		}
		if (e == 14) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[12]->setTexture(texture_color[numeros4[1]]);
			Bolas[13]->setTexture(texture_color[numeros4[0]]);
		}
		if (e == 15) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[12]->setTexture(texture_color[numeros4[2]]);
			Bolas[13]->setTexture(texture_color[numeros4[1]]);
			Bolas[14]->setTexture(texture_color[numeros4[0]]);
		}
		if (e == 16) {
			Bolas[12]->setTexture(texture_color[numeros4[3]]);
			Bolas[13]->setTexture(texture_color[numeros4[2]]);
			Bolas[14]->setTexture(texture_color[numeros4[1]]);
			Bolas[15]->setTexture(texture_color[numeros4[0]]);
		}
	}
	///
	///5
	///
	int numeros5[4];
	e = 16;
	cont = 0;
	if (i == 5) {
		while (pil != NULL && e < 20)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros5[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 16) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 17) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[16]->setTexture(texture_color[numeros5[0]]);
		}
		if (e == 18) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[16]->setTexture(texture_color[numeros5[1]]);
			Bolas[17]->setTexture(texture_color[numeros5[0]]);
		}
		if (e == 19) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[16]->setTexture(texture_color[numeros5[2]]);
			Bolas[17]->setTexture(texture_color[numeros5[1]]);
			Bolas[18]->setTexture(texture_color[numeros5[0]]);
		}
		if (e == 20) {
			Bolas[16]->setTexture(texture_color[numeros5[3]]);
			Bolas[17]->setTexture(texture_color[numeros5[2]]);
			Bolas[18]->setTexture(texture_color[numeros5[1]]);
			Bolas[19]->setTexture(texture_color[numeros5[0]]);
		}
	}
	///
	///6 
	///
	int numeros6[4];
	e = 20;
	cont = 0;
	if (i == 6) {
		while (pil != NULL && e < 24)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros6[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 20) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 21) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[20]->setTexture(texture_color[numeros6[0]]);
		}
		if (e == 22) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[20]->setTexture(texture_color[numeros6[1]]);
			Bolas[21]->setTexture(texture_color[numeros6[0]]);
		}
		if (e == 23) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[20]->setTexture(texture_color[numeros6[2]]);
			Bolas[21]->setTexture(texture_color[numeros6[1]]);
			Bolas[22]->setTexture(texture_color[numeros6[0]]);
		}
		if (e == 24) {
			Bolas[20]->setTexture(texture_color[numeros6[3]]);
			Bolas[21]->setTexture(texture_color[numeros6[2]]);
			Bolas[22]->setTexture(texture_color[numeros6[1]]);
			Bolas[23]->setTexture(texture_color[numeros6[0]]);
		}
	}
	///
	///7
	///
	int numeros7[4];
	e = 24;
	cont = 0;
	if (i == 7) {
		while (pil != NULL && e < 28)
		{
			//Bolas[e]->setTexture(texture_color[pil->valor]);
			numeros7[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 24) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 25) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[24]->setTexture(texture_color[numeros7[0]]);
		}
		if (e == 26) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[24]->setTexture(texture_color[numeros7[1]]);
			Bolas[25]->setTexture(texture_color[numeros7[0]]);
		}
		if (e == 27) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[24]->setTexture(texture_color[numeros7[2]]);
			Bolas[25]->setTexture(texture_color[numeros7[1]]);
			Bolas[26]->setTexture(texture_color[numeros7[0]]);
		}
		if (e == 28) {
			Bolas[24]->setTexture(texture_color[numeros7[3]]);
			Bolas[25]->setTexture(texture_color[numeros7[2]]);
			Bolas[26]->setTexture(texture_color[numeros7[1]]);
			Bolas[27]->setTexture(texture_color[numeros7[0]]);
		}
	}
	///
	///8
	///
	int numeros8[4];
	e = 28;
	cont = 0;
	if (i == 8) {
		while (pil != NULL && e < 32)
		{
			numeros8[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 28) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 29) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[28]->setTexture(texture_color[numeros8[0]]);
		}
		if (e == 30) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[28]->setTexture(texture_color[numeros8[1]]);
			Bolas[29]->setTexture(texture_color[numeros8[0]]);
		}
		if (e == 31) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[28]->setTexture(texture_color[numeros8[2]]);
			Bolas[29]->setTexture(texture_color[numeros8[1]]);
			Bolas[30]->setTexture(texture_color[numeros8[0]]);
		}
		if (e == 32) {
			Bolas[28]->setTexture(texture_color[numeros8[3]]);
			Bolas[29]->setTexture(texture_color[numeros8[2]]);
			Bolas[30]->setTexture(texture_color[numeros8[1]]);
			Bolas[31]->setTexture(texture_color[numeros8[0]]);
		}
	}
	///
	///9
	///
	int numeros9[4];
	e = 32;
	cont = 0;
	if (i == 9) {
		while (pil != NULL && e < 36)
		{
			numeros9[cont] = pil->valor;
			pil = pil->N_siguiente;
			e++;
			cont++;
		}
		if (e == 32) {
			Bolas[e]->setTexture(texture_color[5]);
		}
		if (e == 33) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[32]->setTexture(texture_color[numeros9[0]]);
		}
		if (e == 34) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[32]->setTexture(texture_color[numeros9[1]]);
			Bolas[33]->setTexture(texture_color[numeros9[0]]);
		}
		if (e == 35) {
			Bolas[e]->setTexture(texture_color[5]);
			Bolas[32]->setTexture(texture_color[numeros9[2]]);
			Bolas[33]->setTexture(texture_color[numeros9[1]]);
			Bolas[34]->setTexture(texture_color[numeros9[0]]);
		}
		if (e == 36) {
			Bolas[32]->setTexture(texture_color[numeros9[3]]);
			Bolas[33]->setTexture(texture_color[numeros9[2]]);
			Bolas[34]->setTexture(texture_color[numeros9[1]]);
			Bolas[35]->setTexture(texture_color[numeros9[0]]);
		}
	}
}

void nivel4::Movimiento_entre_pilas()
{
	///
	///1
	/// 
	if (Primero == "1" && PILA1 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA1));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA1));GuardarMovimientos();
		}
	}
	///
	///2
	/// 
	if (Primero == "2" && PILA2 != NULL) {
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA2));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA2));GuardarMovimientos();
		}
	}
	///
	///3
	/// 
	if (Primero == "3" && PILA3 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA3));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA3));GuardarMovimientos();
		}
	}
	///
	///4
	/// 
	if (Primero == "4" && PILA4 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA4));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA4));GuardarMovimientos();
		}
	}
	///
	///5
	/// 
	if (Primero == "5" && PILA5 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA5));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA5));GuardarMovimientos();
		}
	}
	///
	///6
	/// 
	if (Primero == "6" && PILA6 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA6));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA6));GuardarMovimientos();
		}
	}
	///
	///7
	/// 
	if (Primero == "7" && PILA7 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA7));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA7));GuardarMovimientos();
		}
	}
	///
	///8
	/// 
	if (Primero == "8" && PILA8 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA8));GuardarMovimientos();
		}
		if (Segundo == "9" && Pilas_llenas(PILA9) == true) {
			push(PILA9, pop(PILA8));GuardarMovimientos();
		}
	}
	///
	///9
	/// 
	if (Primero == "9" && PILA9 != NULL) {
		if (Segundo == "2" && Pilas_llenas(PILA2) == true) {
			push(PILA2, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "3" && Pilas_llenas(PILA3) == true) {
			push(PILA3, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "4" && Pilas_llenas(PILA4) == true) {
			push(PILA4, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "1" && Pilas_llenas(PILA1) == true) {
			push(PILA1, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "6" && Pilas_llenas(PILA6) == true) {
			push(PILA6, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "5" && Pilas_llenas(PILA5) == true) {
			push(PILA5, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "7" && Pilas_llenas(PILA7) == true) {
			push(PILA7, pop(PILA9));GuardarMovimientos();
		}
		if (Segundo == "8" && Pilas_llenas(PILA8) == true) {
			push(PILA8, pop(PILA9));GuardarMovimientos();
		}
	}

	Primero = "";
	Segundo = "";

	for (int i = 0; i < 9; i++)
	{
		btn_pilas[i]->setFillColor(Color::Black);
		Contenedores[i]->setFillColor(Color::Black);
	}
	
}

bool nivel4::Pilas_llenas(pila pil)
{
	int i = 0;

	while (pil != NULL)
	{
		cout << '(' << i << ") " << pil->valor << endl;
		pil = pil->N_siguiente;
		i++;
	}
	if (i == 4) {
		return false;
	}
	else {
		return true;
	}

}

bool nivel4::GAME_OVER(pila pil)
{
	cout << "Metodo GAME_OVER" << endl;
	if (pil == NULL) {
		cout << "bien" << endl;
		return true;
	}
	else {
		int i = 0;
		int valor = pil->valor;

		while (pil != NULL)
		{
			cout << '(' << i << ") " << pil->valor << endl;
			if (valor == pil->valor) {
				i++;
			}
			pil = pil->N_siguiente;
		}
		if (i == 4) {
			cout << "bien" << endl;
			return true;
		}
		else {
			cout << "mal" << endl;
			return false;
		}
	}
}

void nivel4::MostrarRepeticion(listaMovi listasMostrar)
{
	listaMovi q;
	pila t;
	t = new(struct nodo);
	q = new(struct nodoC);

	q = listasMostrar;

	if (q == NULL) {

	}
	else {
		for (int i = 0; i < 4; i++)
		{
			push(t, 5);
		}
		for (int i = 0; i < 9; i++)
		{
			colocar_colores_pilas(t, i + 1);
		}
		while (q != NULL)
		{
			Sleep(1000);

			colocar_colores_pilas(q->pila1, 1);
			colocar_colores_pilas(q->pila2, 2);
			colocar_colores_pilas(q->pila3, 3);
			colocar_colores_pilas(q->pila4, 4);
			colocar_colores_pilas(q->pila5, 5);
			colocar_colores_pilas(q->pila6, 6);
			colocar_colores_pilas(q->pila7, 7);
			colocar_colores_pilas(q->pila8, 8);
			colocar_colores_pilas(q->pila9, 9);

			Sleep(500);
			q = q->next;
			dibujar();
		}
	}
}

void nivel4::GuardarMovimientos()
{
	listaMovi t, q;
	q = new(struct nodoC);
	cout << endl << endl << endl << endl << endl << "GuardarMovimientos" << endl << endl << endl << endl << endl;

#pragma region Guardar datos
	//11111111111
	int numeros[4];
	int cont = 0;

	if (PILA1 != NULL) {
		pila e1 = PILA1;

		while (e1 != NULL && cont < 4)
		{
			numeros[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila1, numeros[0]);
		}
		if (cont == 2) {
			push(q->pila1, numeros[1]);
			push(q->pila1, numeros[0]);
		}
		if (cont == 3) {
			push(q->pila1, numeros[2]);
			push(q->pila1, numeros[1]);
			push(q->pila1, numeros[0]);
		}
		if (cont == 4) {
			push(q->pila1, numeros[3]);
			push(q->pila1, numeros[2]);
			push(q->pila1, numeros[1]);
			push(q->pila1, numeros[0]);
		}
	}
	else {
		q->pila1 = NULL;
	}
	//2222222222
	int numeros2[4];
	cont = 0;

	if (PILA2 != NULL) {
		pila e1 = PILA2;

		while (e1 != NULL && cont < 4)
		{
			numeros2[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila2, numeros2[0]);
		}
		if (cont == 2) {
			push(q->pila2, numeros2[1]);
			push(q->pila2, numeros2[0]);
		}
		if (cont == 3) {
			push(q->pila2, numeros2[2]);
			push(q->pila2, numeros2[1]);
			push(q->pila2, numeros2[0]);
		}
		if (cont == 4) {
			push(q->pila2, numeros2[3]);
			push(q->pila2, numeros2[2]);
			push(q->pila2, numeros2[1]);
			push(q->pila2, numeros2[0]);
		}
	}
	else {
		q->pila2 = NULL;
	}
	//3333333333
	int numeros3[4];
	cont = 0;

	if (PILA3 != NULL) {
		pila e1 = PILA3;

		while (e1 != NULL && cont < 4)
		{
			numeros3[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila3, numeros3[0]);
		}
		if (cont == 2) {
			push(q->pila3, numeros3[1]);
			push(q->pila3, numeros3[0]);
		}
		if (cont == 3) {
			push(q->pila3, numeros3[2]);
			push(q->pila3, numeros3[1]);
			push(q->pila3, numeros3[0]);
		}
		if (cont == 4) {
			push(q->pila3, numeros3[3]);
			push(q->pila3, numeros3[2]);
			push(q->pila3, numeros3[1]);
			push(q->pila3, numeros3[0]);
		}
	}
	else {
		q->pila3 = NULL;
	}
	//4444444444
	int numeros4[4];
	cont = 0;

	if (PILA4 != NULL) {
		pila e1 = PILA4;

		while (e1 != NULL && cont < 4)
		{
			numeros4[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila4, numeros4[0]);
		}
		if (cont == 2) {
			push(q->pila4, numeros4[1]);
			push(q->pila4, numeros4[0]);
		}
		if (cont == 3) {
			push(q->pila4, numeros4[2]);
			push(q->pila4, numeros4[1]);
			push(q->pila4, numeros4[0]);
		}
		if (cont == 4) {
			push(q->pila4, numeros4[3]);
			push(q->pila4, numeros4[2]);
			push(q->pila4, numeros4[1]);
			push(q->pila4, numeros4[0]);
		}
	}
	else {
		q->pila4 = NULL;
	}
	//5555555555
	int numeros5[4];
	cont = 0;

	if (PILA5 != NULL) {
		pila e1 = PILA5;

		while (e1 != NULL && cont < 4)
		{
			numeros5[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila5, numeros5[0]);
		}
		if (cont == 2) {
			push(q->pila5, numeros5[1]);
			push(q->pila5, numeros5[0]);
		}
		if (cont == 3) {
			push(q->pila5, numeros5[2]);
			push(q->pila5, numeros5[1]);
			push(q->pila5, numeros5[0]);
		}
		if (cont == 4) {
			push(q->pila5, numeros5[3]);
			push(q->pila5, numeros5[2]);
			push(q->pila5, numeros5[1]);
			push(q->pila5, numeros5[0]);
		}
	}
	else {
		q->pila5 = NULL;
	}
	//6666666666
	int numeros6[4];
	cont = 0;

	if (PILA6 != NULL) {
		pila e1 = PILA6;

		while (e1 != NULL && cont < 4)
		{
			numeros6[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila6, numeros6[0]);
		}
		if (cont == 2) {
			push(q->pila6, numeros6[1]);
			push(q->pila6, numeros6[0]);
		}
		if (cont == 3) {
			push(q->pila6, numeros6[2]);
			push(q->pila6, numeros6[1]);
			push(q->pila6, numeros6[0]);
		}
		if (cont == 4) {
			push(q->pila6, numeros6[3]);
			push(q->pila6, numeros6[2]);
			push(q->pila6, numeros6[1]);
			push(q->pila6, numeros6[0]);
		}
	}
	else {
		q->pila6 = NULL;
	}
	//7777777777
	int numeros7[4];
	cont = 0;

	if (PILA7 != NULL) {
		pila e1 = PILA7;

		while (e1 != NULL && cont < 4)
		{
			numeros7[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila7, numeros7[0]);
		}
		if (cont == 2) {
			push(q->pila7, numeros7[1]);
			push(q->pila7, numeros7[0]);
		}
		if (cont == 3) {
			push(q->pila7, numeros7[2]);
			push(q->pila7, numeros7[1]);
			push(q->pila7, numeros7[0]);
		}
		if (cont == 4) {
			push(q->pila7, numeros7[3]);
			push(q->pila7, numeros7[2]);
			push(q->pila7, numeros7[1]);
			push(q->pila7, numeros7[0]);
		}
	}
	else {
		q->pila7 = NULL;
	}
	//8888888888
	int numeros8[4];
	cont = 0;

	if (PILA8 != NULL) {
		pila e1 = PILA8;

		while (e1 != NULL && cont < 4)
		{
			numeros8[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila8, numeros8[0]);
		}
		if (cont == 2) {
			push(q->pila8, numeros8[1]);
			push(q->pila8, numeros8[0]);
		}
		if (cont == 3) {
			push(q->pila8, numeros8[2]);
			push(q->pila8, numeros8[1]);
			push(q->pila8, numeros8[0]);
		}
		if (cont == 4) {
			push(q->pila8, numeros8[3]);
			push(q->pila8, numeros8[2]);
			push(q->pila8, numeros8[1]);
			push(q->pila8, numeros8[0]);
		}
	}
	else {
		q->pila8 = NULL;
	}
	//9999999999
	int numeros9[4];
	cont = 0;

	if (PILA9 != NULL) {
		pila e1 = PILA9;

		while (e1 != NULL && cont < 4)
		{
			numeros9[cont] = e1->valor;
			e1 = e1->N_siguiente;
			cont++;
		}
		if (cont == 1) {
			push(q->pila9, numeros9[0]);
		}
		if (cont == 2) {
			push(q->pila9, numeros9[1]);
			push(q->pila9, numeros9[0]);
		}
		if (cont == 3) {
			push(q->pila9, numeros9[2]);
			push(q->pila9, numeros9[1]);
			push(q->pila9, numeros9[0]);
		}
		if (cont == 4) {
			push(q->pila9, numeros9[3]);
			push(q->pila9, numeros9[2]);
			push(q->pila9, numeros9[1]);
			push(q->pila9, numeros9[0]);
		}
	}
	else {
		q->pila9 = NULL;
	}
#pragma endregion

	//q->pila6 = NULL;
	//q->pila7 = NULL;
	//q->pila8 = NULL;
	//q->pila9 = NULL;

	q->next = NULL;

	if (MOVIMIENTOS == NULL)
	{
		MOVIMIENTOS = q;
	}
	else
	{
		t = MOVIMIENTOS;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = q;
	}
}


void nivel4::regresarPasos(listaMovi& listasMostrar)
{
	if (listasMostrar != NULL && Cont_retrocesos > 0) {
		listaMovi aux = NULL;
		aux = new(struct nodoC);

		aux = listasMostrar;
		if (aux->next != NULL) {

			while ((aux->next)->next != NULL) {
				aux = aux->next;
			}

			Cont_retrocesos--;
			if (Cont_retrocesos == 4) {
				Contxt_retrosesos->setString("4");
			}
			if (Cont_retrocesos == 3) {
				Contxt_retrosesos->setString("3");
			}
			if (Cont_retrocesos == 2) {
				Contxt_retrosesos->setString("2");
			}
			if (Cont_retrocesos == 1) {
				Contxt_retrosesos->setString("1");
			}
			if (Cont_retrocesos == 0) {
				Contxt_retrosesos->setString("0");
			}



			PILA1 = NULL;
			PILA2 = NULL;
			PILA3 = NULL;
			PILA4 = NULL;
			PILA5 = NULL;
			PILA6 = NULL;
			PILA7 = NULL;
			PILA8 = NULL;
			PILA9 = NULL;

			delete(aux->next);
			aux->next = NULL;
#pragma region pilas
			//11111111111
			int numeros[4];
			int cont = 0;

			if (aux->pila1 != NULL) {
				pila e1 = aux->pila1;

				while (e1 != NULL && cont < 4)
				{
					numeros[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA1, numeros[0]);
				}
				if (cont == 2) {
					push(PILA1, numeros[1]);
					push(PILA1, numeros[0]);
				}
				if (cont == 3) {
					push(PILA1, numeros[2]);
					push(PILA1, numeros[1]);
					push(PILA1, numeros[0]);
				}
				if (cont == 4) {
					push(PILA1, numeros[3]);
					push(PILA1, numeros[2]);
					push(PILA1, numeros[1]);
					push(PILA1, numeros[0]);
				}
			}
			else {
				PILA1 = NULL;
			}
			//2222222222
			int numeros2[4];
			cont = 0;

			if (aux->pila2 != NULL) {
				pila e1 = aux->pila2;

				while (e1 != NULL && cont < 4)
				{
					numeros2[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA2, numeros2[0]);
				}
				if (cont == 2) {
					push(PILA2, numeros2[1]);
					push(PILA2, numeros2[0]);
				}
				if (cont == 3) {
					push(PILA2, numeros2[2]);
					push(PILA2, numeros2[1]);
					push(PILA2, numeros2[0]);
				}
				if (cont == 4) {
					push(PILA2, numeros2[3]);
					push(PILA2, numeros2[2]);
					push(PILA2, numeros2[1]);
					push(PILA2, numeros2[0]);
				}
			}
			else {
				PILA2 = NULL;
			}
			//3333333333
			int numeros3[4];
			cont = 0;

			if (aux->pila3 != NULL) {
				pila e1 = aux->pila3;

				while (e1 != NULL && cont < 4)
				{
					numeros3[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA3, numeros3[0]);
				}
				if (cont == 2) {
					push(PILA3, numeros3[1]);
					push(PILA3, numeros3[0]);
				}
				if (cont == 3) {
					push(PILA3, numeros3[2]);
					push(PILA3, numeros3[1]);
					push(PILA3, numeros3[0]);
				}
				if (cont == 4) {
					push(PILA3, numeros3[3]);
					push(PILA3, numeros3[2]);
					push(PILA3, numeros3[1]);
					push(PILA3, numeros3[0]);
				}
			}
			else {
				PILA3 = NULL;
			}
			//4444444444
			int numeros4[4];
			cont = 0;

			if (aux->pila4 != NULL) {
				pila e1 = aux->pila4;

				while (e1 != NULL && cont < 4)
				{
					numeros4[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA4, numeros4[0]);
				}
				if (cont == 2) {
					push(PILA4, numeros4[1]);
					push(PILA4, numeros4[0]);
				}
				if (cont == 3) {
					push(PILA4, numeros4[2]);
					push(PILA4, numeros4[1]);
					push(PILA4, numeros4[0]);
				}
				if (cont == 4) {
					push(PILA4, numeros4[3]);
					push(PILA4, numeros4[2]);
					push(PILA4, numeros4[1]);
					push(PILA4, numeros4[0]);
				}
			}
			else {
				PILA4 = NULL;
			}
			//5555555555
			int numeros5[4];
			cont = 0;

			if (aux->pila5 != NULL) {
				pila e1 = aux->pila5;

				while (e1 != NULL && cont < 4)
				{
					numeros5[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA5, numeros5[0]);
				}
				if (cont == 2) {
					push(PILA5, numeros5[1]);
					push(PILA5, numeros5[0]);
				}
				if (cont == 3) {
					push(PILA5, numeros5[2]);
					push(PILA5, numeros5[1]);
					push(PILA5, numeros5[0]);
				}
				if (cont == 4) {
					push(PILA5, numeros5[3]);
					push(PILA5, numeros5[2]);
					push(PILA5, numeros5[1]);
					push(PILA5, numeros5[0]);
				}
			}
			else {
				PILA5 = NULL;
			}
			//6666666666
			int numeros6[4];
			cont = 0;

			if (aux->pila6 != NULL) {
				pila e1 = aux->pila6;

				while (e1 != NULL && cont < 4)
				{
					numeros6[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA6, numeros6[0]);
				}
				if (cont == 2) {
					push(PILA6, numeros6[1]);
					push(PILA6, numeros6[0]);
				}
				if (cont == 3) {
					push(PILA6, numeros6[2]);
					push(PILA6, numeros6[1]);
					push(PILA6, numeros6[0]);
				}
				if (cont == 4) {
					push(PILA6, numeros6[3]);
					push(PILA6, numeros6[2]);
					push(PILA6, numeros6[1]);
					push(PILA6, numeros6[0]);
				}
			}
			else {
				PILA6 = NULL;
			}
			//7777777777
			int numeros7[4];
			cont = 0;

			if (aux->pila7 != NULL) {
				pila e1 = aux->pila7;

				while (e1 != NULL && cont < 4)
				{
					numeros7[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA7, numeros7[0]);
				}
				if (cont == 2) {
					push(PILA7, numeros7[1]);
					push(PILA7, numeros7[0]);
				}
				if (cont == 3) {
					push(PILA7, numeros7[2]);
					push(PILA7, numeros7[1]);
					push(PILA7, numeros7[0]);
				}
				if (cont == 4) {
					push(PILA7, numeros7[3]);
					push(PILA7, numeros7[2]);
					push(PILA7, numeros7[1]);
					push(PILA7, numeros7[0]);
				}
			}
			else {
				PILA7 = NULL;
			}
			//8888888888
			int numeros8[4];
			cont = 0;

			if (aux->pila8 != NULL) {
				pila e1 = aux->pila8;

				while (e1 != NULL && cont < 4)
				{
					numeros8[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA8, numeros8[0]);
				}
				if (cont == 2) {
					push(PILA8, numeros8[1]);
					push(PILA8, numeros8[0]);
				}
				if (cont == 3) {
					push(PILA8, numeros8[2]);
					push(PILA8, numeros8[1]);
					push(PILA8, numeros8[0]);
				}
				if (cont == 4) {
					push(PILA8, numeros8[3]);
					push(PILA8, numeros8[2]);
					push(PILA8, numeros8[1]);
					push(PILA8, numeros8[0]);
				}
			}
			else {
				PILA8 = NULL;
			}
			//9999999999
			int numeros9[4];
			cont = 0;

			if (aux->pila9 != NULL) {
				pila e1 = aux->pila9;

				while (e1 != NULL && cont < 4)
				{
					numeros9[cont] = e1->valor;
					e1 = e1->N_siguiente;
					cont++;
				}
				if (cont == 1) {
					push(PILA9, numeros9[0]);
				}
				if (cont == 2) {
					push(PILA9, numeros9[1]);
					push(PILA9, numeros9[0]);
				}
				if (cont == 3) {
					push(PILA9, numeros9[2]);
					push(PILA9, numeros9[1]);
					push(PILA9, numeros9[0]);
				}
				if (cont == 4) {
					push(PILA9, numeros9[3]);
					push(PILA9, numeros9[2]);
					push(PILA9, numeros9[1]);
					push(PILA9, numeros9[0]);
				}
			}
			else {
				PILA5 = NULL;
			}
#pragma endregion

		}
	}
}

