#include <stdio.h>
#include <unistd.h>
#include "semaforo.h"

int main() {
    Semaforo s(0);
    char * texto = NULL;
    int i;

    if ( fork() ) {
       for (int i = 0; i < 10; i++ )
           printf( "Esperando para activar el semaforo %d \n", i );
       scanf( "%i", &i );
       s.Signal();
    }
    else {
       printf( "Esperando que el semaforo se active  ...\n" );
       s.Wait();
       printf( "Semaforo activado\n" );
    }
}
/*
   Salida esperada:
     Esperando para activar el semaforo ... (puede aparecer despues)
     Esperando que el semaforo se active
     Esperando para activar el semaforo ...
     Esperando para activar el semaforo ...
     ...
     [Debe escribir un numero para lectura por scanf ...]
     Semaforo activado
*/
