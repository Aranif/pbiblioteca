/* 
** Arán Iglesias Fernández
** Telecomunicaciones ETSi 
** Fichero : encruta2.c
*/
#include <stdio.h>
#include "encruta2.h"


/*
** la idea esque cada vez
** que este libre una casilla 
** vuelva a inspeccionar 
**  asi hasta que encuentre 
** el final.
** Una casilla esta ocupada con #
*/
int encuentraRuta(int ncol, int nfil, char maze[NFIL][NCOL]){// ** maze == maze[][]
  int find = NOFIND;
  // los bordes seran el limite de la tabal
  if(ncol == 0 || nfil == 0 || ncol == NCOL -1 || nfil == NFIL -1){
    find = FIND;
  }
  else{
    maze[nfil][ncol] = 'o';
    //+1 para que se pase a la derecha 
    if((maze[nfil][ncol + 1]) == '.')
      find = encuentraRuta(ncol+1, nfil, maze);
    
    //-1 para que la columna sea la de la izquierda
    if((maze[nfil][ncol-1]) == '.' && find == NOFIND)
      find = encuentraRuta(ncol-1, nfil, maze);
    
    //ahora se incrementa la fila para que vaya para arriba o para abajo
    if(maze[nfil+1][ncol] == '.' && find == NOFIND)
      find = encuentraRuta(ncol, nfil+1, maze); 

    //nfil - 1 para que vaya para arriba
    if(maze[nfil-1][ncol] == '.' && find == NOFIND)
      find = encuentraRuta(ncol, nfil-1, maze);
    
  }

  if(find == FIND)
    maze[nfil][ncol] = '*';  
  return find; 
}
