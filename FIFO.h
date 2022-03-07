/*
 * Calse Fifo de recogida de datos
 * Realizado por José Ángel Moneo
 */
#ifndef _FIFO_class_H
#define _FIFO_class_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#ifndef LONG_FIFO
#define LONG_FIFO 1000
#endif


 
class FIFO
{private:
bool  _error=false;  //bandera Sobrecarga en la fifo
int indrFIFO,indwFIFO;
int dato[LONG_FIFO+3],n[LONG_FIFO+3];
int id; //indice del último dato leido

public:
FIFO(){};
void reset();
void write(int id,int dato); //Guarda el dato. Si la pila está llena devuelve -1
int read();  //Lee dato FIFO
bool empty(){return (indrFIFO==indwFIFO); }  //India si la Fiffo está vacia
int readId();  //lee el indicadoro indice del proximimo dato almacenado en la cola
bool error(){return _error;}

};
#endif
