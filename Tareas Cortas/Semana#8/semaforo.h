/*
LUIS EDUARDO ROJAS CARRILLO - B86875.
SEMÁFORO.H.
DEFINICIÓN DE MÉTODOS.
*/
#ifndef SEMAFORO_H
#define SEMAFORO_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>

using namespace std;

class Semaforo {//CLASE SEMÁRO.
   	public:
      		Semaforo( int, int);
      		~Semaforo();
      		int Signal();	//SIGNAL.
      		int Wait();	//WAIT.
      		void borrar();

        	union semun{//STRUCT PARA SEMCTL.
        	int val;
		struct semid_ds *buf;
		ushort *array;
        	struct seminfo *_buf;
		};

	private:
      		int id;	
		int llave;
};
#endif
