# FIFO
FIFO Calss
  FIFO STRING Almacena cadenas string en un formato FIFO.
  FIFO Almacena int en un formato FIFO.
  
  La estuctura asocia el dato a un número entero que sirve de indicador axiliar
  Este indicador puede ser usado para caracterizar el dato almacenado o para almacenar cualquier dato extra asociado 
  a a la cadena.
   El uso más común de este indicador sería, por ejemplo, en el caso de un gestor de comandos,
   el solicitante del comando, de forma que se pueden gesitonar comandos procedentes de varios
   puertos, identificando posteriormente la procedencia para dar la respuesta adecuada al remitente que hizo 
   la solicitud
