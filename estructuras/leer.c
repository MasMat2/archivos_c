#include <stdio.h>

struct persona{
  char nombre[30];
  char apellido[30];
  int edad;
};

int main(){
  FILE *personas;
  struct persona input;

  char nm[]="/personas.txt";
  personas = fopen(nm, "r");

  while(fread(&input, sizeof(struct persona), 1, personas)){
    printf("%s %s, %d", input.nombre, input.apellido, input.edad);
  }


  fclose(personas);

  return 0;
}
