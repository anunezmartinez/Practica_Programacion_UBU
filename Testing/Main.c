#include<stdio.h>
#include<stdlib.h>



void main()
{
  FILE *fp = fopen("../Datos.csv","r");
  int ch=0;
  int lines=0;

  lines++;
  while(!feof(fp))
{
  ch = fgetc(fp);
  if(ch == '\n')
  {
    lines++;
  }
}
  fclose(fp);
  printf("El numero de lineas es %i", lines);
         
}


