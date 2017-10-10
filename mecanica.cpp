#include "mecanica.h"



int dado_8(){
    int dado=rand()%8+1;
    return dado;
};


int dado_64(){
    int dado=rand()%63;
    return dado;
};


int get_pos_zoe(int tablero[64]){
    int a;              //variable temporal para guardar el valor i dentro del ciclo
    bool flag=false;    //bandera para detener el ciclo cuando se encuentre la posicion de la niña
    for(int i=0;i<64&&!flag;i++){
        if(tablero[i]==zoe ||           //verifica si la casilla es ocupada por la niña
           tablero[i]==zoe+msg1 ||      //verifica si la casilla es ocupada por la niña junto al mensaje 1
           tablero[i]==zoe+msg2 ||      //verifica si la casilla es ocupada por la niña junto al mensaje 2
           tablero[i]==zoe+msg3){       //verifica si la casilla es ocupada por la niña junto al mensaje 3
            a=i;                        //guarda la posicion i en a
            flag=!flag;                 //la bandera se activa para detener el ciclo
        };
    };
    return a;                           //retornamos la posicion de la niña
};
int get_pos_duende(int tablero[64]){
    int a;                  //variable temporal para guardar el valor i dentro del ciclo
    bool flag=false;        //bandera para detener el ciclo cuando se encuentre la posicion de la niña
    for(int i=0;i<64&&!flag;i++){
        if(tablero[i]==duende ||            //verifica si la casilla es ocupada por el duende solo
           tablero[i]==duende+msg1 ||       //verifica si la casilla es ocupada por el duende junto al mensaje 1
           tablero[i]==duende+msg2 ||       //verifica si la casilla es ocupada por ll duende junto al mensaje 2
           tablero[i]==duende+msg3){        //verifica si la casilla es ocupada por el duende junto al mensaje 3
            a=i;                            //guarda la posicion i en a
            flag=!flag;                     //la bandera se activa para detener el ciclo
        };
    };
    return a;                               //retornamos la posicion del duende
};

int col(int n){             //funcion auxiliar que determina la "columna" donde está la casilla n dentro del vector
    return n%8;
};

int fila(int n){            //funcion auxiliar que determina la "fila" donde está la casilla n dentro del vector
    return n/8;
};

bool condicion(int x, int y){               //funcion auxiliar que determina si la posicion x,y es válido dentro del vector
    return (x>=0 && x<=7 && y>=0 && y<=7);
};

int new_pos(int x, int y){//funcion auxiliar que tomando las "coordenadas" x,y nos devuelve la casilla dentro del vector
    return 8*y+x;
};

bool* mensaje_adquirido(bool capturados[3],int suma){//funcion auxiliar que determina si la niña obtuvo un mensaje
    switch (suma){
        case 7:{
            capturados[0]=true;
            cout<<"mensaje 1 capturado\n";
            break;
        };
        case 8:{
            capturados[1]=true;
            cout<<"mensaje 2 capturado\n";
            break;
        };
        case 9:{
            capturados[2]=true;
            cout<<"mensaje 3 capturado\n";
            break;
        };
        default:{
            break;
        };
    };
    return capturados;
};
//funcion auxiliar que modifica el vector actualizando la posicion de la niña verificando si se obtuvo un mensaje
// o si la niña se distrajo finalizando el juego
bool validar_pos_zoe(int tablero[64],int &d, int x, int y, int n, bool capturados[3], bool &gameover ){
    int sum;                                //variable auxiliar para guardar temporalmente el valor de la nueva casilla a ocupar
    if(condicion(x,y)){                     //verificamos si el movimiento es válido
        tablero[n]-=zoe;                  //de la casilla n se quita el valor zoe=5, la niña
        sum=tablero[new_pos(x,y)]+zoe;      //en "sum" guardamos el valor de la nueva casilla más el valor de zoe=5
        tablero[new_pos(x,y)]=sum;          //actualizamos el vector, donde estará la niña y los demás objetos que se encuentren ahí
        if(sum<10&&sum>5)mensaje_adquirido(capturados,sum);//si sum<10 significa que la niña obtuvo algun mensaje, se verifica, cuál mensaje fue
        if(sum >= zoe + duende)gameover=true;    //si la casilla es ocupada por la niña y el duende a la vez, el juego finaliza
        return true;
    }else{  //si el movimiento es inválido avanzamos de acuardo a las manecillas del reloj
        if(d==8){
            d=1;
        }else{
            d++;
        };
        return false;
    };
};
//funcion similar a la anterior, solo que no tenemos en cuenta si el duende obtiene o no mensajes, pues es irrelevante
bool validar_pos_duende(int tablero[64],int &d, int x, int y, int n, bool &gameover ){
    int sum;
    if(condicion(x,y)){
        tablero[n]-=10;
        sum=tablero[new_pos(x,y)]+10;
        tablero[new_pos(x,y)]=sum;
        if(sum >= zoe + duende){
            gameover=true;
        };
         return true;
    }else{
        if(d==8){d=1;}
        else{d++;
        };
        return false;
    };
};

void set_pos_zoe(int tablero[64], int d, bool capturados[3], bool &gameover){
    int n=get_pos_zoe(tablero); //obtenemos el n: la posicion de la niña en el vector
    int x,y;                    //variables auxiliares para guardar las "coordenadas" de la niña
    bool flag=false;            //bandera que nos permite saber si el movimiento fue exitoso o no

    while(!flag){               //mientras el movimiento no sea válido, se evaluará el siguiente de acuerdo a las manecillas del reloj
        switch(d){              //observamos los ocho casos del dado
            case 1:{
                x=col(n)+1;     //la nueva posicion en "x" si el dado cae 1
                y=fila(n)-2;    //la nueva posicion en "y" si el dado cae 2
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);//validamos la posicion, si no es válida, pasamos a la siguiente
                break;
            };
            case 2:{
                x=col(n)+2;
                y=fila(n)-1;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 3:{
                x=col(n)+2;
                y=fila(n)+1;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 4:{
                x=col(n)+1;
                y=fila(n)+2;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 5:{
                x=col(n)-1;
                y=fila(n)+2;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 6:{
                x=col(n)-2;
                y=fila(n)+1;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 7:{
                x=col(n)-2;
                y=fila(n)-1;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            case 8:{
                x=col(n)-1;
                y=fila(n)-2;
                flag=validar_pos_zoe(tablero,d,x,y,n,capturados,gameover);
                break;
            };
            default:{
                break;
            };
        };
    };
};


//funcion similar a la anterior
void set_pos_duende(int tablero[64], int d, bool &gameover){
   int n=get_pos_duende(tablero);
    int x,y;
    bool flag=false;

    while(!flag){
        switch(d){
            case 1:{
                x=col(n)+1;
                y=fila(n)-1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 2:{
                x=col(n)+1;
                y=fila(n);
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 3:{
                x=col(n)+1;
                y=fila(n)+1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 4:{
                x=col(n);
                y=fila(n)+1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 5:{
                x=col(n)-1;
                y=fila(n)+1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 6:{
                x=col(n)-1;
                y=fila(n);
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 7:{
                x=col(n)-1;
                y=fila(n)-1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            case 8:{
                x=col(n);
                y=fila(n)-1;
                flag=validar_pos_duende(tablero,d,x,y,n,gameover);
                break;
            };
            default:{
                break;
            };
        };
    };
};



void juego_ganado(char mensajes[30],bool capturados[3], bool &gameover){
    if(capturados[0] && capturados[1] && capturados[2]){        //evaluamos si los 3 mensajes fueron obtenidos
      cout<<"Has encontrado todos los mensajes, el oso de anteojos procede a leerlos:\n";
      for(int i=0;i<30;i++){
        cout<<*(mensajes + i);
        if((i+1)%10==0 && i!=0)cout<<endl;
      };
      gameover=true;//el juego termina
    };
};
