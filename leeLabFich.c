/*
** Aran Iglesias Fernandez
** Telecomunicaciones
** Fihcero laberinto1.c
*/

#include <stdio.h>
#include <stdlib.h> //me da la funcion de atoi
#include <string.h>



#define PARAMERROR "ERROR: línea de comandos incorrecta. Utilice:\n\rleeLabFich fichero_de_entrada columna_inicio fila_inicio"
#define POSITIONERROR "El punto (%d, %d) no forma parte del laberinto.\n"
#define OBSTA "El punto (%d, %d) es un obstáculo. No es válido.\n"
#define NOSAL "Desde el punto (%d, %d) no hay salida.\n"


int main(int argc, char * argv[]){

 
  //tambien se puede hacer con variable error
  //para evitar if anidadods
     if(argc == 4){
      
       FILE * lab = fopen(argv[1], "r");

       int colms = 0;
       int fils = 0;
       if(lab != NULL){
	 //leo la primera linea y compruebo que son enteros
	 fscanf(lab, "%2d %2d", &colms, &fils);
	 
	 fclose(lab);
       }else
	 fprintf(stderr, "No se puede abrir el fichero de entrada.\n");
       
       
     }else
       fprintf(stderr,PARAMERROR);
     
     

     
  return 0;
}
