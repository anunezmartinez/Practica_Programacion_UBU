#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp = fopen("../Datos2.txt", "r");
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
  printf("El numero de lineas es %i", lines);

  return 0;
}
