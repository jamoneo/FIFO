#include "FIFO.h"


//Inicializa la fifo y as banderas
void FIFO::reset()
{  
 //inicialización de FIFO
//Borra cualquier dato que exista e inicializa los punteros
  for(int i=0;i<LONG_FIFO+3;i++)
       { dato[i]=0;    
         n[i]= 0;} 
 indrFIFO=indwFIFO=0;    
 _error=false;  //Borra bandera de sobrecarga  
 id=0;   //Borra el indicador del último dato leido

}


//escribe en la fifo. En caso de error marca una vandera que puede ser leida mediante la función error
void FIFO::write(int ind,int d)
{ 
 if  (n[indwFIFO]==0) 
                { //ENTRADA LIBRE
                dato[indwFIFO]= d;   //almacena el indice de la rampa
                n[indwFIFO]= ind;    //envía el indice de dato almacenado
                if (indwFIFO<LONG_FIFO) indwFIFO++;  //LACE LA FIFO CIRCULAR
                else  indwFIFO=0;  //HACE LA FIFO CIRCULAR
                // Serial.println( String(id)+","+String(d));  //test
                }         
                
 else _error=true;//Pone bandera de sobrecarga y
}


//lee el ultimo dato de la fifo. Si es una marca de incio añade directamente la 'D' al puerto serie
//y devuelve el dato
//si no hay dato devuelve -1
int FIFO::read()
{ int salida; //Verifica que hay marca de dato escrito
salida=-1;   //marca de de dato no valido
 if( n[indrFIFO]!=0 ) //hay dato en la FIFO
     {  id=n[indrFIFO]; //Almacena el indice del dato leido para posteriores consultas
      // Serial.println( String(n[indrFIFO])+","+String(dato[indrFIFO]));  //Para Test
      salida=dato[indrFIFO];          //Puntero para manejar el dato
      n[indrFIFO]=0; //BORRA EL DATO DE LA FIFO
      //Reestrucuta la fifo 
      if (indrFIFO<LONG_FIFO) indrFIFO++;  //HACE LA FIFO CIRCULAR
      else  indrFIFO=0;  //HACE LA FIFO CIRCULAR
     } 
return salida;
}

//lee el indice almacenado del último dato leido
// Lo usaremos para ver si haydato valido y para ver si es el primer dato de la serie y sincronizar
// mediante "D" con el PC cada serie.
int FIFO::readId()
{ 
 return id; //devuelve el dato indicador correspondiente al ultimo dato leido en FIFO
}
