#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 30

struct alumno
{
  char nombre[SIZE_NAME];
  char apellido[SIZE_NAME];
  int matricula;
  char materia[20];
  int calf[4];
  float promedio;
};

int validar_numero(char numero[]);
void ingresar_datos(FILE *fp);
void calcular_promedios(FILE *fp);
void imprimir_promedios(FILE *fp);

int main()
{
  int op1;
  FILE *alumnos;
  char nm[] = "alumnos.txt";
  alumnos = fopen(nm, "w+");
  do
  {

    do
    {
      system("clear");
      printf("Menu: ");
      printf("\n\t1.- Ingresar datos ");
      printf("\n\t2.- Imprimir promedios");
      printf("\n\t3.- Alumnos sobresalientes");
      printf("\n\t4.- Alumnos sobresalientes");
      printf("\n\t5.- Salir");
      printf("\nOpcion(1-5): ");
      scanf("%d", &op1);
    } while (op1 < 1 || op1 > 5);
    switch (op1)
    {
    case 1:
      ingresar_datos(alumnos);
      break;
    case 2:
      calcular_promedios(alumnos);
      imprimir_promedios(alumnos);
      break;
    case 3:
      break;
    case 4:
      break;
    }
  } while (op1 != 5);
  return 0;
}

int validar_numero(char cadena[])
{
  while (*cadena != '\0')
  {
    if (*cadena < '0' || *cadena > '9')
    {
      return 1;
    }
    cadena++;
  }
  return 1;
}

void ingresar_datos(FILE *fp)
{
  int i, op;
  struct alumno al;
  char temp[20];
  do
  {
    system("clear");
    printf("Llenado de datos\n");
    //Nombre
    printf("\tIngresa el nombre del alumno: ");
    fflush(stdin);
    getchar();
    fgets(al.nombre, SIZE_NAME, stdin);
    //Apellido
    printf("\tIngresa el apellido del alumno: ");
    fflush(stdin);
    getchar();
    fgets(al.apellido, SIZE_NAME, stdin);

    //Matricula
    //Validar que se una entrada valida (numero entero)
    do
    {
      printf("\tIngresa la matricula del alumno: ");
      fflush(stdin);
      getchar();
      fgets(temp, SIZE_NAME, stdin);
    } while (!validar_numero(&temp[0]));
    //Convertir entrada a entero
    al.matricula = atoi(temp);

    //Materia
    printf("\tIngresa la materia del alumno: ");
    fflush(stdin);
    getchar();
    fgets(al.materia, SIZE_NAME, stdin);

    //Obtener y validar calificaciones
    for (i = 0; i < 4; i++)
    {
      do
      {
        printf("\tCalificacion %d: ", i + 1);
        fflush(stdin);
        getchar();
        fgets(temp, SIZE_NAME, stdin);
      } while (!validar_numero(temp));
      al.calf[i] = atoi(temp);
    }
    fwrite(&al, sizeof(struct alumno), 1, fp);
    printf("\nDatos guardados exitosamente");
    do
    {
      printf("\nDesea agregar a otro alumno (1-Si, 2-No): ");
      scanf("%d", &op);
    } while (op != 1 && op != 2);
  } while (!(op - 1));
}

void calcular_promedios(FILE *fp)
{
  int i;
  struct alumno al;
  long int byte_pos;
  rewind(fp);
  byte_pos = ftell(fp);
  while (fread(&al, sizeof(struct alumno), 1, fp))
  {
    byte_pos = ftell(fp);
    al.promedio = 0;
    for (i = 0; i < 4; i++)
    {
      al.promedio += al.calf[i] / 4;
    }
    fseek(fp, byte_pos, SEEK_SET);
    fwrite(&al, sizeof(struct alumno), 1, fp);
  }
}

void imprimir_promedios(FILE *fp)
{
  struct alumno al;
  printf("\nPromedios");
  while (fread(&al, sizeof(struct alumno), 1, fp))
  {
    printf("\n%s %s %s: %.2f", al.materia, al.nombre, al.apellido, al.promedio);
  }
}
