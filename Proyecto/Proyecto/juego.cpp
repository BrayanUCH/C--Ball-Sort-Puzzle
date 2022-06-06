#include "juego.h"
#include "Menu.h"
#include <iostream>
using namespace sf;
using namespace std;

juego::juego(int resolucion_x, int resolucion_y, std::string titulo)
{
	/*menu* MENU{};

	MENU->CERRAR();*/

	fps = 60;

	VENTANA = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	VENTANA->setFramerateLimit(fps);
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	textura = new Texture();
	sprite1 = new Sprite();

	textura->loadFromFile("Amarillo.png");
	circulo = new CircleShape();
	circulo->setPosition(200, 300);
	circulo->setFillColor(Color::Blue);
	circulo->setRadius(50);
	//RectangleShape s;
	sprite1->setTexture(*textura);//poner el * por ser puntero
	sprite1->setPosition(300, 300);
	//2.f=2.0  // se hacer asi para que la divicion de exacta 
	sprite1->setOrigin(sprite1->getTexture()->getSize().x / 2.f, sprite1->getTexture()->getSize().y / 2.f);//cambiar el punto de origen 
	sprite1->setRotation(90);
	Color colorJPG(255, 255, 255);//colores RGB (r,g,b) r=red g=green b=blue
	Color colorPNG(255, 255, 255, 22);//colores RGBA (r,g,b,a) r=red g=green b=blue a=alfa=transparencia/opacidad
	//sprite1->setColor(Color::Blue);
	sprite1->setColor(colorPNG);
	sprite1->setScale(50.f / sprite1->getTexture()->getSize().x, 50.f / sprite1->getTexture()->getSize().y);//para ponerlo en x dimenciones
	//sprite1->setScale(VENTANA->getSize().x, VENTANA->getSize().y); //ocupe toda la ventana
	//sprite1->setScale(VENTANA->getSize().x / sprite1->getTexture()->getSize().x , VENTANA->getSize().y / sprite1->getTexture()->getSize().y); //ocupe toda la ventana

	rectangulo = new RectangleShape();
	texturaRec = new Texture();
	texturaRec->loadFromFile("fondo.jpg");
	rectangulo->setTexture(texturaRec);
	rectangulo->setPosition(200,200);
	rectangulo->setSize(Vector2f(200, 200));
	//texts = new Text("");
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//

	Vector2i posicion;//un vector con dos variables//i de que son datos int
	posicion.x = 0;
	posicion.y = 1;

	Vector2f floats;
	floats.x = 0;
	floats.y = 1;
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
	fuente = new Font();
	fuente->loadFromFile("Fuente.ttf");
	
	TXT_palabra = new Text();
	TXT_palabra->setFont(*fuente);

	TXT_palabra->setString("ooooh");
	TXT_palabra->setFillColor(Color::Cyan);
	TXT_palabra->setPosition(300, 300);
	TXT_palabra->setOrigin(TXT_palabra->getGlobalBounds().width / 2, TXT_palabra->getGlobalBounds().height / 2);

	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	gameLoob();
}

void juego::dibujar() {

	VENTANA->clear();
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	VENTANA->draw(*sprite1);//poner el * por ser puntero
	VENTANA->draw(*circulo);
	//VENTANA->draw(*rectangulo);
	VENTANA->draw(*TXT_palabra);
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	VENTANA->display();

}

void juego::gameLoob() {
	while (VENTANA->isOpen()) {

		sprite1->setRotation(sprite1->getRotation() + 3);

		procesar_mouse();
		procesar_eventos();
		dibujar();
		*tiempo_reloj1 = reloj1->getElapsedTime();
		//reloj1->restart();
		//cout << tiempo_reloj1->asSeconds() << endl;
	}

}


void juego::procesar_eventos() {

	while (VENTANA->pollEvent(*evento1))//mientras alla un evento que escuchar repodir esto
	{
		switch (evento1->type)
		{
		case Event::Closed:
			VENTANA->close();
			exit(1);
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				sprite1->setPosition(sprite1->getPosition().x, sprite1->getPosition().y - 2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				sprite1->setPosition(sprite1->getPosition().x, sprite1->getPosition().y + 2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				sprite1->setPosition(sprite1->getPosition().x-2, sprite1->getPosition().y);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				sprite1->setPosition(sprite1->getPosition().x+2, sprite1->getPosition().y);
			}
			break;
			
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (posicion_mouse == (Vector2i)sprite1->getPosition()) {
					circulo->setFillColor(Color::Red);
					circulo->setPosition(Vector2f(posicion_mouse)); //toma la posicion del mouse
				}
				else {
					circulo->setPosition(Vector2f(posicion_mouse)); //toma la posicion del mouse
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i poscicion_mouse;
				poscicion_mouse = Mouse::getPosition();
				cout << posicion_mouse.x << "--" << posicion_mouse.y << endl;

				if (sprite1->getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y)) {
					circulo->setFillColor(Color::Green);
				}

			}

		default:
			break;
		}
	}
}

void juego::procesar_mouse()
{
	posicion_mouse = Mouse::getPosition(*VENTANA);
	posicion_mouse = (Vector2i)VENTANA->mapPixelToCoords(posicion_mouse);  //cambiar de pixeles a cordenas 
}



