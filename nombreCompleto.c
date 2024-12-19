/* Arán Iglesias Fernández 
** Fichero : nombreCompleto.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "nombreCompleto.h"

int main(){
  //primera direccion: Nombre, luego: Primer apellido
  char ap1[TAM], ap2[TAM], nom[TAM];
  int tap1, tap2, tnom;
  char * pcaracteres = NULL;
  char * newl = NULL; //puntero para indicar en cada tabla donde esta la nueva linea
  int salir = 0; //para salir del bucle while
  
  while(salir != 1){
     /* Todo esto para guardar el nombre
  ** se puede hacer con scanf("%19[^\n]")
  */
    printf(PIDE_NOM);
    fgets(nom, TAM, stdin);
  
    if((newl = strchr(nom, '\n')) != NULL) // si no esNULL esque lo ha encontrado
      *newl = '\0';
    else
      while(getchar() != '\n'); //Para descartar caracteres no leidos si no hay \n 

    if(strncmp(nom, NOMB_SALIR, NCOMP) != 0){ //Compruebo si tieneque salir
      //Primer apellido
      printf(PIDE_APE1);
      fgets(ap1, TAM, stdin);

      if((newl = strchr(ap1, '\n')) != NULL)
	*newl = '\0';
      else
	while(getchar() != '\n');
      //
      // Pide 2 apellido y lo modifica
      printf(PIDE_APE2);
      fgets(ap2, TAM, stdin);

      if((newl = strchr(ap2, '\n')) != NULL)
	*newl = '\0';
      else
	while(getchar() != '\n');
      //

      //Núnero de caracteres de cada tabla :
      tap1 = strlen(ap1); tap2 = strlen(ap2); tnom = strlen(nom);
      int total = tap1 + tap2 + tnom;

      pcaracteres = (char * ) malloc(total * sizeof(char)); // tabla de nombre completo

      if(pcaracteres == NULL)
	fprintf(stderr,MENSAJE_MEM);
      else{
	strcat(pcaracteres, ap1);
	strcat(pcaracteres, " ");
	strcat(pcaracteres, ap2);
	strcat(pcaracteres, ",");
	strcat(pcaracteres, " ");
	strcat(pcaracteres, nom);
      }
      printf(TEXTO_NOM_COMPLETO, pcaracteres);
    }else
      salir = 1;
  }
  return 0;
}
