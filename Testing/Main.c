/*
    nombre_programa: Main.c
    descripción: Práctica Obligatoria de Programación, uso de ficheros, validación de input y bucles.
    @autor: Adrián Núñez Martínez
    fecha: 31/3/2022
    ubicación: Universidad de Burgos
    @versión: Control de Versiones | www.github.com/anunezmartinez/Practica_Obligatoria/
*/
// Importamos las liberarias que vamos a utilizar.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Prototpios de funciones.
int solicitarOpcionMenu();
void seleccionarOpcion(int);
int añadirFila(FILE *);


// Declaramos constantes para los colores.
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

#define SIZE (1024 * 1024)

int main()
{
    solicitarOpcionMenu();

    return 0;
}

/*!
 * @function    solicitarOpcionMenu
 * @abstract    Lista de opciones para el usuario.
 * @discussion  Esta funcion muestra el usuario un listado de opciones a elegir en un menu,
                además está dentro de un bucle reutilizable. También valida el input del usuario.
 * @param       Sin parámetros.
 * @return      int
*/
int solicitarOpcionMenu()
{
    int myInt = 0;
    char loop = 'y';
    do
    {

        // Menu de eleccion.

        printf(ANSI_COLOR_WHITE "\nIntroduce la opción que desees\n" ANSI_COLOR_WHITE);

        printf("\033[0;32m");
        printf("\n1 - Contar el numero de caracteres del fichero\n");
        printf("2 - El número de lineas del fichero.\n");
        printf("3 - La fila mas larga.\n");
        printf("4 - Añadir nueva fila.\n");
        printf("0 - Salir.\n");
        // Le solicitamos al usuario un input y lo validamos.
        printf("\033[0;32m");

        printf(ANSI_COLOR_WHITE "\nIntroduce tu opción : " ANSI_COLOR_WHITE);

        if (scanf("%i", &myInt) == 1) // Verificamos que el input es un numero.
        {
            if (myInt < 5 && myInt > -1) // Verificamos que el input está en el rango que nos interesa.
            {
                seleccionarOpcion(myInt); // Una vez validado en input, se lo pasamos a seleccionarOpcion().
                printf("%i", myInt);
            }
            else
            { // En caso de que el numero esté fuera del rango de eleccion, muestra un mensaje de errror.

                printf(ANSI_COLOR_RED "El numero introducido está fuera de rango." ANSI_COLOR_RED);
            }
        }
        else
        { // En caso de que el valor introducido no sea un numero, muestra un mensaje de error.

            printf(ANSI_COLOR_RED "\nEl dato introducido es erroneo.\n" ANSI_COLOR_RED);
        }

        fflush(stdin); // Limpiamos el buffer.

        printf(ANSI_COLOR_WHITE "\nQuieres continuar?(y / Cualquier otro input para salir)\n" ANSI_COLOR_WHITE); // Le preguntamos al usuario y quiere volver a que le muestre el menú y seleccionar otra opcion.

        scanf("%c", &loop);
    } while (loop == 'y');

    return myInt;
}

/*!
 * @function    seleccionarOpcion
 * @abstract    Abre el fichero y llamada a las funciones.
 * @discussion  Esta funcion envía a las funciones el valor elegido por el usuario en la funcion solicitarOpcionMenu(), abre el fichero con el que vamos
                a trabajar y valida su correcta apertura.
 * @param       int
 * @return      void
*/
void seleccionarOpcion(int seleccion)
{
    FILE *fptr;

    switch (seleccion) // En base a la opcion seleccionada por el usuario, llamamos a su correspondiente funcion.
    {
    case 0:
        exit(0);
        break;
    case 1:
        fptr = fopen("DatosTelefonosMoviles.csv", "r"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {

            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            //contarCaracteres(fptr);
        }

        break;
    case 2:
        fptr = fopen("DatosTelefonosMoviles.csv", "r"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {
            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            //numeroTotalFilas(fptr);
        }

        break;
    case 3:
        fptr = fopen("DatosTelefonosMoviles.csv", "r"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {
            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            //filaMasLarga(fptr);
        }

        break;
    case 4:
        fptr = fopen("Datos.csv", "r"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {
            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            añadirFila(fptr);
        }

        break;
    }
}

int añadirFila(FILE *archivo)
{

  FILE *fp2 = fopen("Datos2.csv", "w");

  char c;

  while ((c = fgetc(archivo)) != EOF)
  {
    fputc(c, fp2);
  }
  fprintf(fp2, "%d,%d,%0.1f,%d,%d,%d,%d,%0.1f,%d,%d,%d,%d,%d,%s", 10, 10, 10.0, 10, 10, 10, 10, 10.0, 10, 10, 101, 10, 101, "HOla");

  return 0;
}