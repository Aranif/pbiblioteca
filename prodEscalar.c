/* Arán Iglesias Fernández
** Ingenieria de las tegnologías de
** las telecomunicaciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "prodEscalar.h"

void iniciaFactoriales( int * venteros, int tam);
void iniciaPotencias( int * venteros, int tam);
int calculaProdEscalar(int *vec1, int *vec2, int tam);
long int calculaProdEscalarLargo( );
void imprimeTabla(int * tab, int tam);

int main(int argc, char *argv[]){
  if(argc != NUM_ARG)
    fprintf(stderr, MENSAJE_USO, argv[0]);
  
  else{
    if(atoi(argv[1]) <= 0)
      fprintf(stderr, MENSAJE_DIMENSION);
    
    else{
      int tam = atoi(argv[1]);
      
      //Como tablas de tam elementos 
      int * ppvector = (int *)malloc(tam * sizeof(int));
      int * psvector = (int *)malloc(tam * sizeof(int));

      if(ppvector == NULL || psvector == NULL)
	fprintf(stderr, MENSAJE_MEMORIA);
      
      else{
	
	iniciaFactoriales(ppvector, tam);
	iniciaPotencias(psvector, tam);

	imprimeTabla(ppvector, tam);
	imprimeTabla(psvector, tam);
	
	int prodesc = calculaProdEscalar(ppvector, psvector, tam);
	long int prodescl = calculaProdEscalarLargo(ppvector, psvector, tam);

	printf(TEXTO_PRODUCTO , prodesc);
	printf(TEXTO_PRODUCTO_LONG , prodescl);


	
	free(ppvector);
	free(psvector);
	
      }
      
				     
    }
  }

  return 0;
}
/*Los factoriales son:
** n *= n
*/
void iniciaFactoriales( int * venteros, int tam){
  
  int n = 1;
  *venteros = 1; //factorial de 0 siempre 1
  
  for(int i = 1; i < tam ; i++){
    n *= i;
    venteros[i] = n; // ¿ Por qué asi no *(venteros + i) ? 
  }
}

void iniciaPotencias( int * venteros, int tam){
  
  *venteros = 1;
  venteros[1] = 2;
  int pot = 2;
  
  for(int i = 2; i < tam; i++)
    {
      pot *= 2;
      venteros[i] = pot; 
    }
}

int calculaProdEscalar( int  *vec1,  int  *vec2, int tam){
  int prod = 0;
  
  for (int i = 0; i < tam; i++){
    prod += *(vec1 + i) * *(vec2 +i);
  }
  return prod;
}

long int calculaProdEscalarLargo(int *vec1, int  *vec2, int tam){
  long int  prodlarg = 0;
  for (int i = 0; i < tam; i++){
    prodlarg += (long int) *(vec1 + i) * (long int)*(vec2 +i);
  }
  return (long int) prodlarg; 
}

void imprimeTabla(int * tab, int tam){
  int i = 0;
  printf("[");
   
  do{
    printf("%03d", tab[i]);
    i++;
    if(i < tam)
      printf(", ");
  }while(i < tam);
  
  printf("]\n");
}
