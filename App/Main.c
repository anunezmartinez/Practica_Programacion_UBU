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
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);
int añadirFila(FILE *);
bool validarEntero(int, int, int, int, char);
bool validaReal(float, float, float, int, char);
int menuMarcasMoviles();

// Declaramos constantes para los colores.
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

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

        if (scanf("%d", &myInt) == 1) // Verificamos que el input es un numero.
        {
            if (myInt < 5 && myInt > -1) // Verificamos que el input está en el rango que nos interesa.
            {
                seleccionarOpcion(myInt); // Una vez validado en input, se lo pasamos a seleccionarOpcion().
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
            contarCaracteres(fptr);
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
            numeroTotalFilas(fptr);
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
            filaMasLarga(fptr);
        }

        break;
    case 4:
        fptr = fopen("DatosTelefonosMoviles.csv", "a+"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {
            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            filaMasLarga(fptr);
        }

        break;
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

    printf(ANSI_COLOR_GREEN "\nHay un total de %i caracteres.\n" ANSI_COLOR_GREEN, charCount);

    fclose(archivo); // Cerramos el archivo.

    return 0; // Si la ejecución ha sido correcta devolvemos cero.
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

    while (!feof(archivo))
    {
        ch = fgetc(archivo);
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(archivo);                                                                      // Cerramos el fichero.
    printf(ANSI_COLOR_GREEN "\nEl numero de lineas es %i\n" ANSI_COLOR_GREEN, lines - 1); // Como no nos saltamos la primera linea como tal, le restamos 1 al total.

    return 0; // Si la ejecución ha sido correcta devolvemos cero.
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

    printf(ANSI_COLOR_WHITE "\nLinea(s) mas larga(s) tiene(n)  %i caracteres y son las lína(s):\n" ANSI_COLOR_WHITE, len);

    while (fgets(str2, sizeof(str2), archivo) != NULL) // Recorremos el fichero linea por linea.
    {
        count2++;
        if (len == strlen(str2)) // Ahora que sabemos como de larga (en numero de caracteres) es la linea mas larga, recorremos el fichero en busca de esa linea o lineas.
        {
            strcpy(longest2, str2);

            printf(ANSI_COLOR_GREEN "\nLínea %i con el contenido:\n%s" ANSI_COLOR_GREEN, count2, longest2);
        }
    }

    fclose(archivo); // Cerramos el fichero.
    return 0;        // Si la ejecución ha sido correcta devolvemos cero.
}
/*
– battery_power: Entero;Valor en el rango[0; 5000].
– blue: Booleano.
– clock_speed: Decimal; Valor en el rango[0; 4.0].
– dual_sim: Booleano.
– fc: Entero; Valor en el rango[0; 20].
– four_g: Booleano.
– int_memory: Entero; Valor en el rango [2; 128].
– m_dep: Decimal; Valor en el rango [0.1; 2.0].
– mobile_wt: Entero; Valor en el rango [50; 500].
– n_cores: Entero; Valor en el rango [1; 16].
– pc: Entero; Valor en el rango [0; 40].
– ram: Entero; Valor en el rango [128; 2560].
– sc_h: Entero; Valor en el rango[0; 100].
– sc_w: Entero; Valor en el rango[0; 100].
– brand: Cadena de Caracteres.
*/

int añadirFila(FILE *archivo)
{
    // int numleido
    // validamos numleido
    // volvemos a pedir nuevo numleido
    // and again
    // En la ultima opcion mostrarmos menuMarcasMovil();

    // una vez está validado todo, lo enviamos al fichero para escribirlo

    int op = 0;
    char enter = 0;

    int numLeido = scanf("%i %c", &op, &enter);
    int correcto = validarEntero(op, numLeido, 0, 4, enter);

    return 0;
}

bool validarEntero(int num, int lim_inf, int lim_sup, int leidos, char enter)
{
    if (leidos == 2)
    {
        if (num >= lim_inf && num <= lim_sup)
        {
            printf("Número válido.");
            return true;
        }else{
            printf("El numero está fuera de rango.");
            return false;
        }
    }
    else
    {
        printf("El input no ha leido correctamente.");
        return false;
    }
}

bool validaReal(float num, float lim_inf, float lim_sup, int leidos, char enter)
{
if (leidos == 2)
    {
        if (num >= lim_inf && num <= lim_sup)
        {
            printf("Número válido.");
            return true;
        }else{
            printf("El numero está fuera de rango.");
            return false;
        }
    }
    else
    {
        printf("El input no ha leido correctamente.");
        return false;
    }
}

int menuMarcasMoviles()
{
    int seleccion = 0;

    printf("1 - Apple");
    printf("2 - HTC");
    printf("3 - LG");
    printf("4 - Nokia");
    printf("5 - Samsung");
    printf("6 - Xiaomi");
    printf("7 - ZTE");

    printf("Selecciona una opcion de la lista.");
    int loop = 0;
    do
    {
        if (scanf("%i", &seleccion) == 1)
        {
            if (seleccion < 8 && seleccion > -1)
            {
                switch (seleccion)
                {
                case 1:
                    printf("Has seleccionado Apple");
                    break;
                case 2:
                    printf("Has seleccionado HTC");
                    break;
                case 3:
                    printf("Has seleccionado LG");
                    break;
                case 4:
                    printf("Has seleccionado Nokia");
                    break;
                case 5:
                    printf("Has seleccionado Samsung");
                    break;
                case 6:
                    printf("Has seleccionado Xiaomi");
                    break;
                case 7:
                    printf("Has seleccionado ZTE");
                    break;
                }
                loop = 1;
                return seleccion;
            }
            else
            {
                printf("El numero introducido está fuera de rango.");
            }
        }
        else
        {
            printf("El dato introducido no es un número.");
        }
    } while (loop == 0);
}
