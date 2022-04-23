#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int solicitarOpcionMenu();
void selecionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

FILE *fptr;

int main()
{

    solicitarOpcionMenu();

    return 0;
}

int solicitarOpcionMenu()
{
    int myInt = 0;
    char loop = 'y';
    do
    {
        fptr = fopen("../Datos.csv", "r");
        if (fptr == NULL)
        {
            printf("Error, el archivo no ha podido ser abierto.");
        }
        else
        {

            printf("Introduce la opción que desees\n");
            printf("1 - Contar el numero de caracteres del fichero\n");
            printf("2 - El número de lineas del fichero.\n");
            printf("3 - La fila mas larga.\n");
            printf("0 - Salir.\n");

            printf("Introduce tu opción : ");

            if (scanf("%d", &myInt) == 1)
            {
                if (myInt < 5 && myInt > -1)
                {
                    selecionarOpcion(myInt);
                }
                else
                {
                    printf("El numero introducido está fuera de rango.");
                }
            }
            else
            {
                printf("\nEl dato introducido es erroneo.\n");
            }
        }
        fflush(stdin);
        printf("\n Quieres continuar?(y/n)\n");
        scanf(" %c", &loop);
    } while (loop == 'y');

    return myInt;
}

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

int contarCaracteres(FILE *archivo)
{
    int count = 0;
    char c;
    int charCount = 0;

    for (c = getc(archivo); c != EOF; c = getc(archivo))
    {
        if (c == '\n')
        {
            count++;
        }
        else if (count >= 1)
        {
            if (isalnum(c))
            {
                charCount = charCount + 1;
            }
        }
    }

    printf("Hay un total de %i caracteres.\n", charCount);
    fclose(archivo);

    return count;
}
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
    fclose(archivo);
    printf("El numero de lineas es %i\n", lines - 1);

    return lines;
}
int filaMasLarga(FILE *archivo)
{

    char str[1000], longest[1000];
    int len = 0;
    int count = 0;

    while (fgets(str, sizeof(str), archivo) != NULL)
    {
        count++;
        if (count != 1)
        {
            if (len < strlen(str))
            {
                strcpy(longest, str);
                len = strlen(str);
            }
        }
    }

    printf("Longest Line is %s", longest);

    int filaLarga = 0;

    return filaLarga;
}
