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
    selecionarOpcion(opcion);

    return 0;
}

int solicitarOpcionMenu()
{
    int myInt = 0;
    printf("Introduce la opción a elegir : ");
    scanf("%d", &myInt);

    if (myInt < 5 && myInt > -1)
    {
        return myInt;
    }
    else
    {
        printf("Error.");
    }
}

void selecionarOpcion(int seleccion)
{

    int bucle = 1;
    while (bucle != 0)
    {
        switch (seleccion)
        {
        case 0:
            bucle = 0;
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
int contarCaracteres(FILE *archivo)
{

    int count = 0;
    char c;

    for (c = getc(archivo); c != EOF; c = getc(archivo))
    {
        count = count + 1;
    }

    return printf("Hay un total de %i caracteres.", count);
}
int numeroTotalFilas(FILE *archivo)
{
    char line[200];
    int count = 0;
    while (fgets(line, sizeof(line), archivo)){
        
        char *token;

        token = strtok(line, ",");
        count++;
        while(token != NULL){

            token = strtok(NULL, ",");
        }

        printf("\nNumero de Lineas %i\n", count);

        
    }
    fclose(archivo);
    
}
int filaMasLarga(FILE *archivo)
{

    // return filasLarga;
}
