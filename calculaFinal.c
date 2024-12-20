/* Arán Iglesias Fernandez
** Fichero : calculaFInal.c
** Ingenieria de las tecnol. de 
** las telecomunicaciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculaFinal.h"

int main(int argc, char * argv[]){
  FILE * file = NULL;
  
  char DNI[MAXDNI];
  
  float n1 = 0; float n2 = 0; float n3 = 0; //nota 1 2 y 3
  float nt = 0;
  int argr = 0; // argumentos leidos de sscanf
  int lc = 0; //numero lineas correctas
  int l = 0; //contador de lineas contadas
  float m1 = 0;
  float m2 = 0; float m3 = 0;  //Medias de cada parte 1 2 3 y la total
  float mt = 0;
 

  if(argc == NUM_ARG){
    if((file = fopen(argv[1], "r")) == NULL)
      fprintf(stderr, MENSA_APERTURA, argv[1]);
    else{
      
      /* Aqui empezará el programa
      ** Se lee las lineas completas 
      ** con fgets y luego se 
      ** lee con sscanf
      */
      
      char * str = (char * )malloc(MAXLIN*sizeof(char));
      
      if(str == NULL)
	fprintf(stderr,MENSA_MEMORIA);
      
      else{
	printf( LIN_CABECERA, "DNI", "P1", "P2", "P3", "FINAL");
	
	while(fgets(str, MAXLIN, file) != NULL){

	  l++; //cada vez que se lee una linea se incrementa 
	  
	  //SSCANF devuelve el numero de argumentos leidos
	argr = sscanf(str, " %s%f%f%f", DNI, &n1, &n2, &n3);
	if(argr == 4){
	  nt = n1 + n2 +n3;
	  m1 += n1;
	  m2 += n2;
	  m3 += n3;
	  mt += nt/3; 
	  lc++;
	  printf(FORM_SALIDA, DNI, n1, n2, n3, nt/3);

 	}else
	  printf("Línea %d con formato erróneo.\n", l);
	}
	
	printf("*MEDIA*  %13.2f %6.2f %6.2f %6.2f\n", m1/lc, m2/lc, m3/lc, mt/lc);
	printf(LIN_RESUMEN, lc);
	
      }
      free(str);
      fclose(file);
    }
  }else
    fprintf(stderr, MENSA_USO, argv[0]);



  
  return 0; 

}
