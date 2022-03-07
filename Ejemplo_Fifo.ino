#include "FIFO_string.h"

#define LONG_FIFO_String 120 //redefine la longitud de la fifo. Sin redefinir serán 100
FIFO_string fifo;

void setup() {
  String T;
  
  Serial.begin(115200);
   Serial.println("Pulse ENTER");  
  while(!Serial.available());  //espera un caracter
  fifo.reset();  //Inicial el buffer de comandos
  

  
  //Crea 100 mensajes y se guardan e la fifo indicando en cada uno si fue par o impar en el bucle
   for(int i =0;i<100;i++)
    if(fifo.free()>0) {fifo.send(i&1,"Mensaje "+String(i)); // guarda un mensaje con el indicador de par o impar Par=0, Impar=1
                      Serial.println("Mensaje "+String(i)); //lista los mensajes según se crean y guardan.
                      }
     Serial.println("Recuperando mensajes de Cola");                  
  // Saca todos los mensajes de la cola separandolos segun el marcador de par,
 //colocando los pares a la derecha y los impares a la izquierda
  while(!fifo.empty()) 
    {   //toma el dato de la fifo y el identificador almacenado
      //para procesar la posicion
      if(fifo.get(&T)) Serial.println(T);
      else Serial.print(T+"\t"); 

    }
  
}


void loop() {
 

}
