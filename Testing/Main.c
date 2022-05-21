#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char *fabricanteDeModa(void);

int main() {
    const char *marca = fabricanteDeModa();

    
    printf("%s\n", marca);
    return 0;
}

const char *fabricanteDeModa(void) {
    int apple = 5;
    int xiaomi = 10;
    int samsung = 7;
    int htc = 12;
    int lg = 15;
    int zte = 10;
    int nokia = 2;

    const char *marcas[7] = { "apple", "xiaomi", "samsung", "htc", "lg", "zte", "nokia" };
    int valores[7] = { apple, xiaomi, samsung, htc, lg, zte, nokia };
    int i;
    int maxVal = valores[0];
    int pos = 0;

    for (i = 1; i < 7; ++i) {
        if (valores[i] > maxVal) {
            maxVal = valores[i];
            // Update the index of the max value
            pos = i;
        }
    }
    printf("Largest element = %d\n", pos);
    printf("La marca de moda es : %s\n", marcas[pos]); //This Works
    return marcas[pos];
}