#ifndef CALCULAFINAL_H
#define CALCULAFINAL_H

/* Valor que debe tener argc */
#define NUM_ARG 2

/* Longitudes máximas */
#define MAXLIN 1024
#define MAXDNI   20

/* Mensajes de error que se enviarán a la salida de errores */
#define MENSA_USO            "Uso: %s fichero\n"
#define MENSA_APERTURA       "No pudo abrirse %s.\n"
#define MENSA_MEMORIA        "Error de memoria.\n"

/* Mensajes usados para imprimir los resultados */
#define LIN_CABECERA         "%-15s %6s %6s %6s %6s\n"
#define FORM_SALIDA          "%-15s %6.2f %6.2f %6.2f %6.2f\n"
#define LIN_RESUMEN          "\nLíneas correctas: %d\n"
#endif
