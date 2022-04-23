/*
	nombre_programa: Main.c
	descripción: Práctica Obligatoria de Programación, uso de ficheros, validación de input y bucles.
	@autor: Adrián Núñez Martínez
	fecha: 31/3/2022
    ubicación: Universidad de Burgos
	@versión: Control de Versiones | www.github.com/anunezmartinez/Practica_Obligatoria/
*/
//Importamos las liberarias que vamos a utilizar.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Prototpios de funciones.
int solicitarOpcionMenu();
void selecionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

//Declaramos una variable tipo fichero de forma global.
FILE *fptr;

int main()
{

    solicitarOpcionMenu();

    return 0;
}

/*Esta funcion abre el fichero con el que vamos y trabajar y valida su apertura, también muestra las opciones al usuario en un bucle retulizable y
valida el input de usuario.*/
int solicitarOpcionMenu()
{
    int myInt = 0;
    char loop = 'y';
    do
    {
        fptr = fopen("../Datos.csv", "r");//Abrimos el fichero con el que vamos a trabajar.
        if (fptr == NULL)//Validamos la apertura del fichero.
        {
            printf("Error, el archivo no ha podido ser abierto.");
        }
        else
        {
            //Menu de eleccion.
            printf("Introduce la opción que desees\n");
            printf("1 - Contar el numero de caracteres del fichero\n");
            printf("2 - El número de lineas del fichero.\n");
            printf("3 - La fila mas larga.\n");
            printf("0 - Salir.\n");
            //Le solicitamos al usuario un input y lo validamos.
            printf("Introduce tu opción : ");

            if (scanf("%d", &myInt) == 1) //Verificamos que el input es un numero.
            {
                if (myInt < 5 && myInt > -1) //Verificamos que el input está en el rango que nos interesa.
                {
                    selecionarOpcion(myInt);//Una vez validado en input, se lo pasamos a seleccionarOpcion().
                }
                else
                {   //En caso de que el numero esté fuera del rango de eleccion, muestra un mensaje de errror.
                    printf("El numero introducido está fuera de rango.");
                }
            }
            else
            {   //En caso de que el valor introducido no sea un numero, muestra un mensaje de error.
                printf("\nEl dato introducido es erroneo.\n");
            }
        }
        fflush(stdin); //Limpiamos el buffer.
        printf("\n Quieres continuar?(y/cualquier otro input)\n");//Le preguntamos al usuario y quiere volver a que le muestre el menú y seleccionar otra opcion.
        scanf(" %c", &loop);
    } while (loop == 'y');

    return myInt;
}

//Esta funcion llama al resto de funciones en base a la eleccion el usuario, tambien tiene un la opción de deter la ejecución.
void selecionarOpcion(int seleccion)
{

    switch (seleccion)
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
/* Esta funcion cuenta los caracteres del fichero que son de tipo alfanumérico exclusivamente, es decir, sin comas ni espacios. 
Tambien discrimina la primera línea que es la cabezera */
int contarCaracteres(FILE *archivo)
{
    int count = 0;
    char c;
    int charCount = 0;
    //Declaramos un bucle que vaya hasta el final de fichero, caracter por caracter.
    for (c = getc(archivo); c != EOF; c = getc(archivo))
    {
        if (c == '\n') //Para saltarnos la primera linea, la funcion empezará a contar carácteres despues de pasar por su primer \n, saltandose así la primera  linea.
        {
            count++;
        }
        else if (count >= 1)
        {
            if (isalnum(c)) //Verificamos que el caracter sea alfanumérico.
            {
                charCount = charCount + 1;
            }
        }
    }

    printf("Hay un total de %i caracteres.\n", charCount);
    fclose(archivo); //Cerramos el archivo.

    return count;
}
/*Esta funcion cuenta el numero total de filas, lo que hace es contar cuantas veces encuentra una \n y lo va acumulando en un acumulador hasta 
llegar al final del fichero.*/
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
    fclose(archivo); //Cerramos el fichero.
    printf("El numero de lineas es %i\n", lines - 1); //Como no nos saltamos la primera linea como tal, le restamos 1 al total.

    return lines;
}
//Esta función lo que hace es mostrar cual es la linea mas larga de todo el programa
int filaMasLarga(FILE *archivo)
{

    char str[1000], longest[1000];
    int len = 0;
    int count = 0;

    while (fgets(str, sizeof(str), archivo) != NULL) //Recorremos el fichero linea por linea.
    {
        count++;
        if (count != 1) /*Hacemos una condicion tipo if, que solo se de una vez el contador superer el valor de 1, de forma que el contador se incrementa en uno a cada linea. 
                        Así nos saltamos la primera línea, que es caso de tenerla en cuenta sería la mas larga*/
        {
            if (len < strlen(str)) //Vamos comparando la longitud de una linea con la siguiente hasta terminar el fichero y quedarnos con la mas larga.
            {
                strcpy(longest, str);
                len = strlen(str);
            }
        }
    }

    printf("La linea mas larga es la línea %i y su contenido es : \n%s", count, longest);
    
    fclose(archivo); //Cerramos el fichero.
    
    int filaLarga = 0;

    return filaLarga;
}
