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
bool validarReal(float, float, float, int, char);
int menuMarcasMoviles();
void fabricanteDeModa(FILE *, char *);
void consumirNuevaLinea();
void calcularMinMaxBateria(FILE *, int *, int *);
float calcularMediaBateria(FILE *);

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
        printf("5 - Fabricante de moda.\n");
        printf("0 - Salir.\n");
        // Le solicitamos al usuario un input y lo validamos.
        printf("\033[0;32m");

        printf(ANSI_COLOR_WHITE "\nIntroduce tu opción : " ANSI_COLOR_WHITE);

        if (scanf("%i", &myInt) == 1) // Verificamos que el input es un numero.
        {
            if (myInt < 6 && myInt > -1) // Verificamos que el input está en el rango que nos interesa.
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

        consumirNuevaLinea();

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

    case 5:
        fptr = fopen("Datos.csv", "r"); // Abrimos el fichero y validamos su apertura.
        if (fptr == NULL)
        {
            printf(ANSI_COLOR_RED "Error, el archivo no ha podido ser abierto. Revisa el nombre del fichero, extension y ruta en seleccionarOpcion()" ANSI_COLOR_RED);
        }
        else
        {
            char marca[10];
            fabricanteDeModa(fptr, marca);
            printf("La marca de moda es : %s\n", marca); // Not working (already tried changing to %c)
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

/*!
 * @function    añadirFila
 * @abstract    Añade una fila al fichero. Este nuevo fichero una copia del original.
 * @discussion  Esta funcion muestra el usuario un listado de opciones a elegir de las carácterísticas
 *              de los telefonos del archivo csv. Valida su entrada.
 * @param       FILE.
 * @return      int
 */

int añadirFila(FILE *archivo)
{
    // Declaramos las variables que vamos a utilizar.

    int fc, int_memory, mobile_wt, n_cores, pc, ram, sc_h, sc_w = 0;
    int battery_power = 0;
    float clock_speed, m_dep = 0;
    char str[128], *lf;
    int leidos = 0;

    // Y le vamos a ir pidiendo al usuario los diferentes datos, validandolo con validarEntero() o validarReal().
    printf("\nIntroduce la cantidad de batería, número entero entre 0 y 5000.\n");

    do
    {
        leidos = scanf("%d", &battery_power);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(battery_power, 0, 5000, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    int bluetooth;
    bool ans;

    do
    {
        printf("\nTiene bluetooth? Introduce 1 para si o 0 para false.\n");

        leidos = scanf("%d", &bluetooth);
        ans = bluetooth;

        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
        if (bluetooth == 1 || bluetooth == 0)
        {
            printf("\nEl dato introducido es correcto. Respuesta : %d\n", ans);
        }
    } while (!(bluetooth == 1 || bluetooth == 0));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;

    do
    {
        printf("\nIntroduce la velocidad de reloj, número float entre 0 y 4.0\n");

        leidos = scanf("%f", &clock_speed);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarReal(clock_speed, 0, 4.0, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    bool ans1;
    int dual_sim;

    do
    {
        printf("\nTiene dual sim? Introduce 1 para si o 0 para false.\n");

        leidos = scanf("%d", &dual_sim);
        ans1 = dual_sim;

        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
        if (dual_sim == 1 || dual_sim == 0)
        {
            printf("\nEl dato introducido es correcto. Respuesta : %d\n", ans1);
        }
    } while (!(dual_sim == 1 || dual_sim == 0));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nCuantos megapixeles tiene la camara frontal? Numero entero entre 0 y 20\n");

        leidos = scanf("%d", &fc);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(fc, 0, 20, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;

    int four_g;
    bool ans2;

    do
    {
        printf("\nTiene 4G? Introduce 1 para si o 0 para false.\n");

        leidos = scanf("%d", &four_g);
        ans2 = four_g;

        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
        if (four_g == 1 || four_g == 0)
        {
            printf("\nEl dato introducido es correcto. Respuesta : %d\n", ans2);
        }
    } while (!(four_g == 1 || four_g == 0));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de memoria, número entero entre 2 y 128.\n");

        leidos = scanf("%d", &int_memory);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(int_memory, 2, 128, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de grosor del movil, número float entre 0.1 y 2.0.\n");

        leidos = scanf("%f", &m_dep);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
        }
        leidos++;
    } while (!(validarReal(m_dep, 0.1, 2.0, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de peso del movil, número entero entre 50 y 500.\n");

        leidos = scanf("%d", &mobile_wt);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(mobile_wt, 50, 500, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de nucleos, número entero entre 1 y 16.\n");

        leidos = scanf("%d", &n_cores);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(n_cores, 1, 16, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de pixeles de la camara principal, número entero entre 0 y 40.\n");

        leidos = scanf("%d", &pc);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(pc, 0, 40, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la cantidad de ram, número entero entre 128 y 2560.\n");

        leidos = scanf("%d", &ram);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(ram, 128, 2560, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;

    do
    {
        printf("\nIntroduce la altura de la pantalla, número entero entre 0 y 100.\n");

        leidos = scanf("%d", &sc_h);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(sc_h, 0, 100, leidos, *lf)));

    // Reseteamos variables.
    leidos = 0;
    lf = 0;
    str[0] = 0;
    do
    {
        printf("\nIntroduce la achura de la pantalla, número entero entre 0 y 100.\n");
        leidos = scanf("%d", &sc_w);
        fgets(str, sizeof(str), stdin);
        if ((lf = strchr(str, '\n')) != NULL)
        {
            *lf = '\n';
            leidos++;
        }
    } while (!(validarEntero(sc_w, 0, 100, leidos, *lf)));

    consumirNuevaLinea();

    // Aqui le pedimos al usuario que eliga entre un numero de marcas de teléfonos, dependiendo de lo
    // que el usuario seleccione, enviaremos el nombre de esa marca a char destino.
    char destino[50];
    int marca = menuMarcasMoviles();
    if (marca == 1)
    {
        char marca[] = "Apple";
        strcpy(destino, marca);
    }
    else if (marca == 2)
    {
        char marca[] = "HTC";
        strcpy(destino, marca);
    }
    else if (marca == 3)
    {
        char marca[] = "LG";
        strcpy(destino, marca);
    }
    else if (marca == 4)
    {
        char marca[] = "Nokia";
        strcpy(destino, marca);
    }
    else if (marca == 5)
    {
        char marca[] = "Samsung";
        strcpy(destino, marca);
    }
    else if (marca == 6)
    {
        char marca[] = "Xiaomi";
        strcpy(destino, marca);
    }
    else if (marca == 7)
    {
        char marca[] = "ZTE";
        strcpy(destino, marca);
    }

    // Ahora que ya tenemos todos los datos correctos y validados, creamos un nuevo archivo usando ¨w¨.

    FILE *fp2 = fopen("Datos2.csv", "w");

    // Leemos caracter por caracter nuestro fichero y lo copiamos a este nuevo.
    char c;

    while ((c = fgetc(archivo)) != EOF)
    {
        fputc(c, fp2);
    }

    // Una vez está creado, añadimos al final de fichero una nueva lina con la variables introducidas anteriormente.
    fprintf(fp2, "%d,%d,%0.1f,%d,%d,%d,%d,%0.1f,%d,%d,%d,%d,%d,%d,%s", battery_power, ans, clock_speed, ans1, fc, ans2, int_memory, m_dep, mobile_wt, n_cores, pc, ram, sc_h, sc_w, destino);

    printf("\n%d,%d,%0.1f,%d,%d,%d,%d,%0.1f,%d,%d,%d,%d,%d,%d,%s", battery_power, ans, clock_speed, ans1, fc, ans2, int_memory, m_dep, mobile_wt, n_cores, pc, ram, sc_h, sc_w, destino);
    printf("\nNueva linea añadida al fichero.\n");

    return 0;
}

/*!
 * @function    validarEntero
 * @abstract    Valida input.
 * @discussion  Esta funcion valida los datos enteros introducidos por el usuario, verificando que se ha pulsado enter, el limite superior e inferior y leidos es = 2.
 * @param       int, int, int, int , int, char.
 * @return      bool
 */
bool validarEntero(int num, int lim_inf, int lim_sup, int leidos, char enter)
{
    if (leidos == 2)
    {
        if (num >= lim_inf && num <= lim_sup)
        {
            printf("\nEl numero leido es valido.\n");

            return true;
        }
        else
        {
            printf("\nEl numero está fuera de rango.\n");
            printf("\nVuelve a introducir el número\n");
            return false;
        }
    }
    else
    {
        printf("\nEl input no se ha leido correctamente.\n");
        printf("\nVuelve a introducir el número\n");
        return false;
    }
}

/*!
 * @function    validarReal
 * @abstract    Valida input.
 * @discussion  Esta funcion valida los datos reales introducidos por el usuario, verificando que se ha pulsado enter, el limite superior e inferior y leidos es = 2.
 * @param       int, int, int, int , int, char.
 * @return      bool
 */
bool validarReal(float num, float lim_inf, float lim_sup, int leidos, char enter)
{
    if (leidos == 2)
    {
        if (num >= lim_inf && num <= lim_sup)
        {
            printf("\nNúmero válido.\n");
            return true;
        }
        else
        {
            printf("\nEl numero está fuera de rango.\n");
            printf("\nVuelve a introducir el número\n");
            return false;
        }
    }
    else
    {
        printf("\nEl input no ha leido correctamente.\n");
        printf("\nVuelve a introducir el número\n");
        return false;
    }
}

/*!
 * @function    menuMarcasMoviles
 * @abstract    Muesta unalLista de opciones para el usuario.
 * @discussion  Esta funcion muestra el usuario un listado de opciones a elegir en un menu de marcas de telefonos,
                además está dentro de un bucle reutilizable. También valida el input del usuario.
 * @param       Sin parámetros.
 * @return      int
*/
int menuMarcasMoviles()
{
    int seleccion = 0;

    printf("\n1 - Apple");
    printf("\n2 - HTC");
    printf("\n3 - LG");
    printf("\n4 - Nokia");
    printf("\n5 - Samsung");
    printf("\n6 - Xiaomi");
    printf("\n7 - ZTE");

    printf("\nSelecciona una opcion de la lista.");
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
                    printf("\nHas seleccionado Apple\n");
                    break;
                case 2:
                    printf("\nHas seleccionado HTC\n");
                    break;
                case 3:
                    printf("\nHas seleccionado LG\n");
                    break;
                case 4:
                    printf("\nHas seleccionado Nokia\n");
                    break;
                case 5:
                    printf("\nHas seleccionado Samsung\n");
                    break;
                case 6:
                    printf("\nHas seleccionado Xiaomi\n");
                    break;
                case 7:
                    printf("\nHas seleccionado ZTE\n");
                    break;
                }

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

    return seleccion;
}
void fabricanteDeModa(FILE *archivo, char *marca)
{

    int xiaomi = 0;
    int samsung = 0;
    int htc = 0;
    int lg = 0;
    int zte = 0;
    int nokia = 0;
    int apple = 0;

    char str[1000];

    while (fgets(str, sizeof(str), archivo) != NULL) // Recorremos el fichero linea por linea.
    {
        if (strstr(str, "Apple"))
        {
            apple++;
        }
        else if (strstr(str, "Xiaomi"))
        {
            xiaomi++;
        }
        else if (strstr(str, "Samsung"))
        {
            samsung++;
        }
        else if (strstr(str, "HTC"))
        {
            htc++;
        }
        else if (strstr(str, "LG"))
        {
            lg++;
        }
        else if (strstr(str, "ZTE"))
        {
            zte++;
        }
        else if (strstr(str, "Nokia"))
        {
            nokia++;
        }
    }
    char marcas[7][10] =
        {"apple",
         "xiaomi",
         "samsung",
         "htc",
         "lg",
         "zte",
         "nokia"};

    int valores[7] = {apple, xiaomi, samsung, htc, lg, zte, nokia};
    int i;
    int maxVal = valores[0];
    int pos = 0;

    for (i = 1; i < 7; ++i)
    {
        if (valores[i] > maxVal)
        {
            maxVal = valores[i];
            pos = i;
        }
    }
    strcpy(marca, marcas[pos]); 
    fclose(archivo);
}

void consumirNuevaLinea()
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}