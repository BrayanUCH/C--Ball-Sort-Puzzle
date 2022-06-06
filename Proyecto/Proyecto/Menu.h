#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
using namespace sf;
using namespace std;

class menu {

public:
	menu(int resolucion_x, int resolucion_y, string titulo);//constructor

	void dibujar();//dibuja la pnatlla

	void gameLoob();//repetidor

	void procesar_eventos();//escuchardor de eventos

	void procesar_mouse();//posicion del click del mouse
private:
	//ventana
	RenderWindow* VENTANA_menu;
	int fps;
	//fuente
	Font* fuente;
	//palabras
	Text* TXT_Titulo;
	Text* TXT_jugar;
	Text* TXT_instrucciones;
	Text* TXT_salir;
	//botones
	RectangleShape* rect_Jugar;
	RectangleShape* rect_instrucciones;
	RectangleShape* rect_salir;
	//fondo
	Texture* textura_Fondo;
	RectangleShape* rectangulo_Fondo;
	//eventos
	Event* evento1;
	Vector2i posicion_mouse;
	//tiempo
	Clock* reloj1;
	Time* tiempo_reloj1;
};
