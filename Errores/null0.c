#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fuente;
  //Definir la direccion de los archivos
  char nm[]="/Users/max/Documents/Code/c_le/archivos/Errores/fuente.txt";

  //Abrir el archivo fuente en modo de escritura
  fuente = fopen(nm, "r");

  //Comporbar que la apertura del archivo haya sido correcta en caso contrario
  //terminar la ejecucion
  if(fuente == NULL){
    puts("\nError al abrir el archivo");
    exit(-1);
  }
  printf("El archivo se abrio correctamente");
  fclose(fuente);
  printf("\n\n\n\n");
  getchar();
  return 0;
}
