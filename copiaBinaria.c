/* Arán Iglesias Fernández
** Fichero: copiaBinaria.c
*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
  FILE * fent = NULL;
  FILE * fsal = NULL;
  int caracter[2000];// este será nuestro buffer
  
  if (argc != 3)
    fprintf(stderr, "Se necesitan dos parámetros: origen y destino\n");
  else
    {
      if ((fent = fopen(argv[1], "r")) == NULL)
	fprintf(stderr, "No se puede abrir el fichero origen\n");
      else
	{
	  fsal = fopen(argv[2], "w");
	  if (fsal == NULL)
	    fprintf(stderr, "No se puede abrir el fichero destino\n");
	  else
	    {
	      int write = 0;
	      int num = 0; //nos guarda el numeros de caracteres que lee
	      // Leemos cada carácter del fichero de entrada ...
	      while ((num = fread(caracter, sizeof(char), 2000, fent)) != 0){
		// ... y lo escribimos en el fichero de salida.
		
		if(num <= 2000){
		write += fwrite(caracter, sizeof(char), num, fsal);
		printf("%d\n", write);
		}
	      }
	      fclose(fsal);
	      fclose(fent);
	     
	    }
	  
	}
    }
  return 0;
}
