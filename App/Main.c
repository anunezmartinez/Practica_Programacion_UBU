#include <stdio.h>

int solicitarOpcionMenu();
void selecionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);



int main(){
    
    FILE *fptr;
    fptr = fopen("./Datos","r");
    if(fptr == NULL){
      printf("Error!");   
      exit(1);             
   }

    int opcion = solicitarOpcionMenu();
    selecionarOpcion(opcion);

    return 0;
}

int solicitarOpcionMenu(){
    int myInt = 0;
    printf("Introduce la opción a elegir : ");
    scanf("%d", &myInt);
    printf("%i", myInt);
    if(myInt < 5 && myInt > -1){
        return myInt;
    } else{
        printf("Error.");
    }

}

void selecionarOpcion(int seleccion){
   
    int bucle = 1;
    while (bucle != 0){
        switch(seleccion){
            case 0:
                bucle = 0;
                break;
            case 1:
                contarCaracteres(fptr);
                break;
            case 2:
                numeroTotalFilas(ftpr);
                break;
            case 3:
                filaMasLarga(ftpr);
                break;
        }
    }
}
int contarCaracteres(FILE *archivo){

return caracterescontados;
}
int numeroTotalFilas(FILE *archivo){

return numeroFilas;
}
int filaMasLarga(FILE *archivo){

return filasLarga;
}
