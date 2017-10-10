#ifndef GRAFICO_H_INCLUDED
#define GRAFICO_H_INCLUDED
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "mecanica.h"


using namespace std;


void tomar_mensaje(char mensajes [30]);
void inicio(int tablero[64], char mensajes[30]); //función que determina los elementos iniciales de la partida
                                                        //como las 3 paradas iniciales de la mariposa, más la introduccion
                                                        //de los mensajes y las posiciones iniciales de la niña y el duende

void desarrollo(Juego &juego);
//realiza los doce movimientos del juego

void imprimir(int vec[64]); //imprime en consola el vector con todos los elementos
void imprimir_vector(int tablero[64]);//imprime en consola los valores del vector, función auxiliar
void limpiar(); //limpia la consola
#endif // GRAFICO_H_INCLUDED
