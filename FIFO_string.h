/* FIFO String
 * (c) José Angel Moneo Fernández
 * Almacena cadenas string en un formato FIFO.
 * La estuctura lleva asociada una cadena y un número entero que sirve de indicador axiliar
 * Este indicador puede ser usado para caracterizar la cadena almacenada o para almacenar cualquier dato extra asociado 
 * a a la cadena.
 *  El uso más común de este indicador sería, por ejemplo, en el caso de un gestor de comandos,
 *  el solicitante del comando, de forma que se pueden gesitonar comandos procedentes de varios
 *  puertos, identificando posteriormente la procedencia para dar la respuesta adecuada.
 * 
 */
#ifndef _FIFO_string_class_H
#define _FIFO_string_class_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


#ifndef LONG_FIFO_String
#define LONG_FIFO_String 100
#endif


 
class FIFO_string
{private:
bool  _error=false;  //bandera Sobrecarga en la fifo
int indrFIFO,indwFIFO;
String dato[LONG_FIFO_String+3];
int n[LONG_FIFO_String+3]; //marcador


public:
FIFO_string(){};
void reset(); //borra la fifo
void send(int id,String dato); //Guarda el dato. Si la pila está llena devuelve -1
int get(String *cadena);  //Lee dato FIFO
char charAt(int i); //devuelve un caracter de la siguiene cadena de la fifo, sin sacarla de esta
bool empty(){return (indrFIFO==indwFIFO); }  //India si la Fiffo está vacia
int free();  //devuelve el espacio libre  de la pila
bool error(){return _error;}
};
#endif
