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

// Prototpios de funciones.
int solicitarOpcionMenu();
void seleccionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

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

        printf("\033[0;37m");//Añadimos colores al los outputs, esta linea se repite mucho porque no se pueden usar variables globales.
        printf("\nIntroduce la opción que desees\n");
        printf("\033[0;37m");

        printf("\033[0;32m");
        printf("\n1 - Contar el numero de caracteres del fichero\n");
        printf("2 - El número de lineas del fichero.\n");
        printf("3 - La fila mas larga.\n");
        printf("0 - Salir.\n");
        // Le solicitamos al usuario un input y lo validamos.
        printf("\033[0;37m");
        printf("\nIntroduce tu opción : ");
        printf("\033[0;37m");
        printf("\033[0;32m");

        if (scanf("%d", &myInt) == 1) // Verificamos que el input es un numero.
        {
            if (myInt < 5 && myInt > -1) // Verificamos que el input está en el rango que nos interesa.
            {
                seleccionarOpcion(myInt); // Una vez validado en input, se lo pasamos a seleccionarOpcion().
            }
            else
            { // En caso de que el numero esté fuera del rango de eleccion, muestra un mensaje de errror.
                printf("\033[0;31m");
                printf("El numero introducido está fuera de rango.");
                printf("\033[0;31m");
            }
        }
        else
        { // En caso de que el valor introducido no sea un numero, muestra un mensaje de error.
            printf("\033[0;31m");
            printf("\nEl dato introducido es erroneo.\n");
            printf("\033[0;31m");
        }

        fflush(stdin); // Limpiamos el buffer.
        printf("\033[0;37m");
        printf("\nQuieres continuar?(y / Cualquier otro input para salir)\n"); // Le preguntamos al usuario y quiere volver a que le muestre el menú y seleccionar otra opcion.
        printf("\033[0;37m");
        scanf(" %c", &loop);
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
    FILE *fptr = fopen("../Datos.csv", "r");//Abrimos el fichero y validamos su apertura.
    if (fptr == NULL)
    {
        printf("\033[0;31m");
        printf("Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()");
        printf("\033[0;31m");
    }
    else
    {
        switch (seleccion)//En base a la opcion seleccionada por el usuario, llamamos a su correspondiente funcion.
        {
        case 0:
            break;
        case 1:
            contarCaracteres(fptr);
            break;
        case 2:
            numeroTotalFilas(fptr);
            break;
        case 3:
            filaMasLarga(fptr);
            break;
        }
    }
}

/*!
 * @function    contarCaracteres
 * @abstract    Muestra el numereo de carácteres.
 * @discussion  Esta funcion cuenta el total de caracteres el fichero que son estrictamente alfanumericos y saltándose la cabezera del mismo.
 * @param       FILE
 * @return      int
 */
int contarCaracteres(FILE *archivo)
{
    int count = 0;
    char c;
    int charCount = 0;
    // Declaramos un bucle que vaya hasta el final de fichero, caracter por caracter.
    for (c = getc(archivo); c != EOF; c = getc(archivo))
    {
        if (c == '\n') // Para saltarnos la primera linea, la funcion empezará a contar carácteres despues de pasar por su primer \n, saltandose así la primera  linea.
        {
            count++;
        }
        else if (count >= 1)
        {
            if (isalnum(c)) // Verificamos que el caracter sea alfanumérico.
            {
                charCount = charCount + 1;
            }
        }
    }

    printf("\nHay un total de %i caracteres.\n", charCount);

    fclose(archivo); // Cerramos el archivo.

    return 0;//Si la ejecución ha sido correcta devolvemos cero.
}

/*!
 * @function    numeroTotalFilas
 * @abstract    Cuenta el numero total de filas.
 * @discussion  Esta funcion cuenta el total de filas del fichero saltándose la cabezera del mismo.
 * @param       FILE
 * @return      int
 */
int numeroTotalFilas(FILE *archivo)
{
    int ch = 0;
    int lines = 0;

    lines++;
    while (!feof(archivo))
    {
        ch = fgetc(archivo);
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(archivo);                                    // Cerramos el fichero.
    printf("\nEl numero de lineas es %i\n", lines - 1); // Como no nos saltamos la primera linea como tal, le restamos 1 al total.

    return 0;//Si la ejecución ha sido correcta devolvemos cero.
}

/*!
 * @function    filaMasLarga
 * @abstract    Muestra la linea(s) mas larga(s) del fichero.
 * @discussion  Esta funcion muestra la linea mas larga del fichero saltándose la cabezera del mismo.
 * @param       FILE
 * @return      int
 */
int filaMasLarga(FILE *archivo)
{

    char str[1000], longest[1000];
    int len = 0;
    int count = 0;
    char str2[1000], longest2[1000];
    int count2 = 0;

    while (fgets(str, sizeof(str), archivo) != NULL) // Recorremos el fichero linea por linea.
    {
        count++;
        if (count != 1) /*Hacemos una condicion tipo if, que solo se de una vez el contador superer el valor de 1, de forma que el contador se incrementa en uno a cada linea.
                        Así nos saltamos la primera línea, que es caso de tenerla en cuenta sería la mas larga*/
        {
            if (len < strlen(str)) /*Vamos comparando la longitud de una linea con la siguiente hasta terminar el fichero y quedarnos
                                    con el numero de caracteres de la linea larga.*/
            {
                strcpy(longest, str);
                len = strlen(str);
            }
        }
    }
    fseek(archivo, 0, SEEK_SET); // Reseteamos el puntero de vuelta al principio de fichero para volver a leerlo.

    while (fgets(str2, sizeof(str2), archivo) != NULL) // Recorremos el fichero linea por linea.
    {
        count2++;
        if (len == strlen(str2)) // Ahora que sabemos como de larga (en numero de caracteres) es la linea mas larga, recorremos el fichero en busca de esa linea o lineas.
        {
            strcpy(longest2, str2);

            printf("\nLinea %i con el contenido:  \n%s", count2, longest2);
        }
    }

    fclose(archivo); // Cerramos el fichero.
    return 0;//Si la ejecución ha sido correcta devolvemos cero.
}
