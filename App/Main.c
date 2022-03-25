#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solicitarOpcionMenu();
void selecionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

FILE *fptr;

int main()
{

    fptr = fopen("../Datos.csv", "r");
    if (fptr == NULL)
    {
        printf("Error, el archivo no ha podido ser abierto.");
    }

    int opcion = solicitarOpcionMenu();
    // Bug, aunque la validacion no sea correcta, opcion recibe el valor de uno.
    selecionarOpcion(opcion);

    return 0;
}

int solicitarOpcionMenu()
{
    printf("Introduce la opción que desees\n");
    printf("1 - Contar el numero de caracteres del fichero\n");
    printf("2 - El número de lineas del fichero.\n");
    printf("3 - La fila mas larga.\n");
    printf("0 - Salir.\n");

    int myInt = 0;
    printf("Introduce tu opción : ");
    scanf("%d", &myInt);

    // Este código tiene que ser refactorizado que da un poco de cáncer.

    if (myInt < 5 && myInt > -1)
    {
        return myInt;
    }
    else
    {
        printf("Error en la elección.");
    }
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

    for (c = getc(archivo); c != EOF; c = getc(archivo))
    {
        count = count + 1;
    }

    printf("Hay un total de %i caracteres.\n", count);
    return count;
}
int numeroTotalFilas(FILE *archivo)
{
    FILE *fp = fopen("../Datos.csv", "r");
    int ch = 0;
    int lines = 0;

    lines++;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(fp);
    printf("El numero de lineas es %i\n", lines - 1);
    return lines;
}
int filaMasLarga(FILE *archivo)
{
    int filaLarga = 0;

    return filaLarga;
}
