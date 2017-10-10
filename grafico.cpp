#include "grafico.h"


void tomar_mensaje(char mensajes [30], int n){        //
    int tecla=0;
    int i=0;

    while(tecla!=arriba && i<10){
        tecla=getch();
        if(tecla==arriba && i==0){
            cout<<"Ingrese algun mensaje\n";
            tecla=0;
        };
        if(tecla!=arriba && tecla!= 0 &&
         (tecla==32 ||tecla==164 || tecla==165 ||
         (tecla>=65 && tecla<=90) ||
         (tecla>=97 && tecla<=122))){
            *(mensajes+(10*n+i))=tecla;
            cout<<*(mensajes+(10*n+i));
            i++;
        };
    };
};

void inicio(int tablero[64], char mensajes[30]){
    int pos;
    imprimir(tablero);

    cout<<"introduzca el primer mensaje de paz:\n";
    tomar_mensaje(mensajes,0);

    pos=dado_64();
    *(tablero+pos)=msg1;//lugar dentro del vector donde se guarda el mensaje uno
    limpiar();
    imprimir(tablero);


    cout<<"introduzca el segundo mensaje de paz:\n";
    tomar_mensaje(mensajes,1);
    do{pos=dado_64();
    }while(*(tablero+pos)!=0);

    *(tablero+pos)=msg2;//lugar dentro del vector donde se guarda el mensaje dos
    limpiar();
    imprimir(tablero);


    cout<<"introduzca el tercer mensaje de paz:\n";
    tomar_mensaje(mensajes,2);

    do{pos=dado_64();
    }while(*(tablero+pos)!=0);
    *(tablero+pos)=msg3;//lugar dentro del vector donde se guarda el mensaje tres
    limpiar();
    imprimir(tablero);

    do{pos=dado_64();       //genera la posicion aleatoria de la niña
    }while(*(tablero+pos)!=0);
    *(tablero+pos)=zoe;


    do{pos=dado_64();       //genera la posicion aleatoria del duende
    }while(*(tablero+pos)!=0);
    *(tablero+pos)=duende;
    limpiar();
    imprimir(tablero);

};

void desarrollo(Juego &juego){
    int tecla=0;//variable int donde se guardará el valor obtenido en la consola al presionar la tecla arriba
    int d;      //variable donde quedará guardado temporalmente el valor del dado de ocho caras
    int i=0;    //variable para el ciclo while
    while(i<turnos&&!juego.gameover){          //ciclo while para los 24 movimientos de la partida o antes si se finaliza el juego por
                                    //algun motivo

        while(tecla!=arriba){         //la consola está a la espera de que la tecla arriba sea presionada y solo
            tecla=getch();              //continuará cuando sea ésta la tecla presionada
        };
        if(i%2==0){                   //turno de la niña
            limpiar();                  //liampiamos la consola para solo tener un tablero pintado a la vez
            d=dado_8();                 //lanzamiento del dado de ocho caras
            set_pos_zoe(juego.tab,d,juego.captura,juego.gameover);//actualizamos la posicion de la niña y verificamos si el juego puede continuar
            imprimir(juego.tab);      //actualizada la posicion de la niña imprimimos el tablero con éstas modificaciones
            cout<<"turno "<<((i+1)/2)+1<<" de zoe\n";
            cout<<"valor del dado: "<<d<<endl;
        }else{
            limpiar();                          //turno del duende
            d=dado_8();
            set_pos_duende(juego.tab,d,juego.gameover);
            imprimir(juego.tab);
            cout<<"turno "<<(i+1)/2<<" de rumpelstiltnskin\n";
            cout<<"valor del dado: "<<d<<endl;
        };

        juego_ganado(juego.mensajes,juego.captura,juego.gameover);//verificamos si la niña ha obtenido todos los mensajes
      tecla=0;                      //reinicia el valor de tecla para poder observar el siguiente movimiento
      i++;
    };

    //condiciones para el fin del juego
    if(i<turnos&&(!juego.captura[0]||!juego.captura[1]||!juego.captura[2])){
        cout<<"Zoe se ha distraido, fin del juego\n";//el juego finaliza si la niña no obtuvo todos los mensajes y se distrajo
    }else if(i==turnos){
        cout<<"Juego postergado para un futuro , hasta pronto!.\n";
    };
};

void imprimir(int tablero[64]){
    char x=219; //simbolo cuadrito completo
    char temp;
    for(int i=0;i<64;i++){
        if(tablero[i]!=0){
            if(tablero[i]>1 && tablero[i]<5){temp='X';}
            else if(tablero[i]==zoe ||
           tablero[i]==zoe+msg1 ||
           tablero[i]==zoe+msg2 ||
           tablero[i]==zoe+msg3){temp='Z';}
            else if(tablero[i]==duende
                    || tablero[i]==duende+msg1
                    || tablero[i]==duende+msg2
                    || tablero[i]==duende+msg3){temp='D';}
        };
        if(i%8==0){ //imprime linea blanca
          for(int a=0;a<17;a++)cout<<x<<x;
          cout<<endl;
        };

        cout<<x<<x<<(*(tablero+i)==0?' ':temp)<<x;
        if((i+1)%8==0)cout<<x<<x<<endl;
    };
    for(int a=0;a<17;a++)cout<<x<<x;
    cout<<endl;
};


void imprimir_vector(int tablero[64]){
    for(int i=0;i<64;i++){
        cout<<tablero[i];
        if((i+1)%8==0)cout<<endl;
    }
    cout<<endl;
};

void limpiar(){
    system("cls");
};
