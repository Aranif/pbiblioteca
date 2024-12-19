/*
** Arán Iglesias Fernández
** Telecomunicaciones ETSi
** Ficheros : encruta2.h
*/

#ifndef ENCRUTA1_H
#define  ENCRUTA1_H

//para usar
#define FIND 1
#define NOFIND 0

/*buscará el camino como:
** 1 - hacia la derecha
** 2 - hacia la izquierda
** 3 - hacia abajo
** 4 - hacia arriba
*/
int encuentraRuta(int ncol, int nfil, char maze[NFIL][NCOL]);

#endif
