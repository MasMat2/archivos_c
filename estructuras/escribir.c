#include <stdio.h>

struct persona
{
  char nombre[30];
  char apellido[30];
  int edad;
};

int main()
{
  FILE *personas;
  char nm[] = "/personas.txt";
  personas = fopen(nm, "w");

  struct persona p1 = {"John", "Doe", 20};
  struct persona p2 = {"Jane", "Smith", 20};

  //
  fwrite(&p1, sizeof(struct persona), 1, personas);
  fwrite(&p2, sizeof(struct persona), 1, personas);

  fclose(personas);

  return 0;
}
