#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
using namespace sf;
using namespace std;

class instrucciones {

public:
	instrucciones(int resolucion_x, int resolucion_y, string titulo);//constructor

	void dibujar();//dibuja la pnatlla

	void gameLoob();//repetidor

	void procesar_eventos();//escuchardor de eventos

	void procesar_mouse();//posicion del click del mouse
private:
	//ventana
	RenderWindow* VENTANA_ins;
	int fps;
	//fuente
	Font* fuente;
	Font* fuente2;
	//palabras
	Text* TXT_Titulo;
	Text* TXT_Menu;
	Text* TXT_instrucciones;
	Text* TXT_salir;
	Text* TXT_todas_instrucciones[11];
	//botones
	RectangleShape* rect_Menu;
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
