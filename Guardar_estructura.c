//Imprimir calificaciones
//fwrite
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

void capturar(struct alumno *al, int n);

int main()
{
    FILE *fp;
    struct alumno al;
    char nm[] = "alumnos.txt";
    //e (exit) valor bandera para indicar si se agregara otro alumno
    //n (numero de alumnos que han sido introducidos)
    int e, n=0;

    //Abrir archivo alumnos en modo lectura
    fp = fopen(nm, "w");

    do{
        n++;
        capturar(&al, n);
        fwrite(&al, sizeof(struct alumno), 1, fp);
        printf("Desea agregar otro alumno (0-No, 1-Si): ");
        scanf("%d", &e);
    }while(e);
    fclose(fp);
}

void capturar(struct alumno *al, int n){
    int op, i;
    do{
    system("clear");
    printf("Captura de datos");
    printf("\nAlumno %d\n", n+1);
    //Nombre
    getchar();
    printf("\tIngresa el nombre del alumno: ");
    fflush(stdin);
    gets(al->nombre);
    //Apellido
    printf("\tIngresa el apellido del alumno: ");
    fflush(stdin);
    getchar();
    gets(al->apellido);
    //Materia
    printf("\tIngresa la materia del alumno: ");
    fflush(stdin);
    gets(al->materia);
    //Numero de lista
    printf("\tIngresa el numero de lista del alumno: ");
    scanf("%d", &al->no_lista);
    //Calificaciones y promedio
    al->promedio = 0;
    for(i=0;i<4;i++){
        printf("\tCalificacion %d: ", i+1);
        scanf("%d", &al->calf[i]);
        al->promedio = (float)al->calf[i]/4;
    }
    //Validacion del usuario
    printf("La informacion fue introducida correctamente? (0-No, 1-Si): ");
    scanf("%d", &op);
    }while(op);
}