#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
using namespace sf;
using namespace std;

class juego {

public:
	juego(int resolucion_x,int resolucion_y,string titulo);//constructor

	void dibujar();//dibuja la pnatlla

	void gameLoob();//repetidor

	void procesar_eventos();//escuchardoe de eventos

	void procesar_mouse();


private:

	RenderWindow * VENTANA;
	int fps;
	
	Texture * textura;
	Sprite* sprite1;
	CircleShape * circulo;

	Texture* texturaRec;
	RectangleShape* rectangulo;

	Event* evento1;

	Vector2i posicion_mouse;
	
	Clock* reloj1;
	Time* tiempo_reloj1;

	Font* fuente;
	Text* TXT_palabra;

};