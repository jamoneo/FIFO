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
#include "FIFO_string.h"


//Inicializa la fifo y as banderas
void FIFO_string::reset()
{  
 //inicialización de FIFO
//Borra cualquier dato que exista e inicializa los punteros
  for(int i=0;i<LONG_FIFO_String+3;i++)
       { dato[i]="";    //borra los mesajes
         n[i]= -1;}// borra los indicadores
 indrFIFO=indwFIFO=0;    
 _error=false;  //Borra bandera de sobrecarga  
//Serial.println("reset buffer");

}


//escribe en la fifo. En caso de error marca una vandera que puede ser leida mediante la función error
void FIFO_string::send(int ind,String d)
{ //Serial.println("enviando datos");
//Serial.println(indwFIFO);
 if  (n[indwFIFO]==-1) 
                { //ENTRADA LIBRE
                dato[indwFIFO]= d;   //almacena el indice de la rampa
                n[indwFIFO]= ind;    //envía el indice de dato almacenado o indicador 
                if (indwFIFO<LONG_FIFO_String) indwFIFO++;  //LACE LA FIFO CIRCULAR
                else  indwFIFO=0;  //HACE LA FIFO CIRCULAR
                // Serial.println( String(ind)+","+d);  //test
                }         
                
 else _error=true;//Pone bandera de sobrecarga y

//Serial.println("Iw="+String(indwFIFO));
}

int FIFO_string::free()
{
  if(indwFIFO>=indrFIFO) return (LONG_FIFO_String-indwFIFO+indrFIFO);
  else return (indrFIFO+indwFIFO);
}


//lee el ultimo dato de la fifo. Si es una marca de incio añade directamente la 'D' al puerto serie
//y devuelve el dato
//si no hay dato devuelve -1
int FIFO_string::get(String *cadena)
{ int id; 

id=-1;   //marca de de dato no valido

 if( n[indrFIFO]!=-1 ) //hay dato en la FIFO
     { id=n[indrFIFO]; //Toma el indicador del menaje leido para posteriores consultas
         *cadena=dato[indrFIFO];          //Puntero para manejar el dato
     // Serial.println("Indr="+String(indrFIFO)+" indw="+ String(indwFIFO)+ " n="+String(n[indrFIFO])+" dato="+String(dato[indrFIFO]));
      n[indrFIFO]=-1; //BORRA EL DATO DE LA FIFO, borrando el indicador
      //Reestrucuta la fifo 
      if (indrFIFO<LONG_FIFO_String) indrFIFO++;  //HACE LA FIFO CIRCULAR
      else  indrFIFO=0;  //HACE LA FIFO CIRCULAR
  
     } 

return id;  //Devuelve el indicador pasado
}

//devuelve un  caracter de la cadena que se extraería
//devuelve 0 si no hay cadena para analizar
char FIFO_string::charAt(int i)
{ char c=0;
    if(!empty()) c=dato[indrFIFO].charAt(i); 

  return c;
}
