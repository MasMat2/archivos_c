//Imprimir calificaciones
//fread
#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 30

struct alumno
{
  char nombre[SIZE_NAME];
  char apellido[SIZE_NAME];
  int no_lista;
  char materia[20];
  int calf[4];
  float promedio;
};


int main()
{
    FILE *fp;
    char nm[] = "alumnos.txt";
    struct alumno al;
    int e;
    fp = fopen(nm, "r");
    //Leer hasta que fread alcanze el final del archivo
    while(fread(&al, sizeof(struct alumno), 1, fp)){
        printf("\n\t%s %s %d\n%s", al.nombre, al.apellido, al.no_lista, al.materia);
        //Imprimir las cuatro calificaciones
        for(e=0;e<4;e++){
            printf("\t%d", al.calf[e]);
        }
        printf("\nPromedio: %.2f", al.promedio);
    }
    printf("\n");
    fclose(fp);
}
