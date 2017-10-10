#ifndef MECANICA_H_INCLUDED
#define MECANICA_H_INCLUDED
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

#define arriba 72 //asocia el 72 al código de la tecla presionada
#define zoe 5           //dentro del vector, el numero 5 establece la posicion de la niña
#define duende 10       //dentro del vector, el numero 10 establece la posicion del duende
#define msg1 2          //dentro del vector, el numero 2 establece la posicion del mensaje 1
#define msg2 3          //dentro del vector, el numero 3 establece la posicion del mensaje 2
#define msg3 4          //dentro del vector, el numero 4 establece la posicion del mensaje 3
#define turnos 23
using namespace std;

struct Juego{
    int tab[64];        //vector que contiene toda la informacion sobre el tablero, la niña, la mariposa y el duende
    char mensajes [30];    //arreglo donde guardaremos los mensajes
    bool captura[3];        //arreglo de banderas para determinar si algún mensaje ha sido descubierto
    bool gameover;          //determina si el juego ha finalizado por diversos motivos
};


int dado_8();   //metodo para obtener un numero aleatorio entre 1 y 8
int dado_64();  //metodo para obtener un numero aleatorio entre 1 y 64



int get_pos_zoe(int tablero[64]);   //funcion que retorna la posicion de la niña dentro del vector
int get_pos_duende(int tablero[64]);//funcion que retorna la posicion del duende dentro del vector

void set_pos_zoe(int tablero[64], int d, bool capturados[3], bool &gameover);
                                /* funcion que determina la posision de la niña con base al numero obtenido en el dado
                                    de ocho caras, verifica que la jugada sea posible, y si no, efectua la siguiente posible
                                    de acuerdo con las manecillas del reloj, tambien verifica si se obtuvo algún mensaje y actualiza
                                    el vector tablero además de verificar si la niña se destrajo o no.
                                */

void set_pos_duende(int tablero[64], int d, bool &gameover);
                                /* funcion que determina la posision del duende con base al numero obtenido en el dado
                                    de ocho caras, verifica que la jugada sea posible, y si no, efectua la siguiente posible
                                    de acuerdo con las manecillas del reloj, veriica ademas si el duende logra distraer a la niña
                                */

void juego_ganado(char mensajes[30],bool capturados[3], bool &gameover);/* verifica si se han obtenido los tres mensajes
para llevarlos donde el oso de anteojos, él los leerá y el bosque será un lugar primaveral, establece el fin del juego como
ganado*/



#endif // MECANICA_H_INCLUDED
