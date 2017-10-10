#include "grafico.h"

using namespace std;

Juego juego; //estructura que contiene todas las variables necesarias para el desarrollo del juego

int main()
{
    for(int i=0;i<30;i++){
        *(juego.mensajes+i)=0;
    };
    *(juego.mensajes+30)='\0';

    *(juego.captura)=false;
    *(juego.captura+1)=false;
    *(juego.captura+2)=false;

    juego.gameover=false;

    srand (time(NULL));

    inicio(juego.tab,juego.mensajes);
    desarrollo(juego);
    return 0;
}
