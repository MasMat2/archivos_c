#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fuente, *copia;
  int lim =20;
  char cad[lim];
  //Definir la direccion de los archivos
  char nm[]="/Users/max/Documents/Code/c_le/archivos/Copiar/fuente.txt";
  char nm2[]="/Users/max/Documents/Code/c_le/archivos/Copiar/copia_fuente.txt";

  //Abrir el archivo fuente en modo de lectura
  fuente = fopen(nm, "r");
  //Abrir el archivo copia_fuente en modo de escritura
  copia = fopen(nm2, "w");

  //Comporbar que la operacion haya sido correcta en caso contrario
  //terminar la ejecucion
  if(fuente == NULL || copia == NULL){
    puts("\nError al abrir el archivo");
    exit(-1);
  }

  //Leer cada linea de pf una por una y escribirla en pf2
  while(fgets(cad, lim, fuente)!=NULL){
    fputs(cad, copia);
  }

  //Cerrar archivos
  fclose(fuente);
  fclose(copia);
  printf("\n\n\n\n");
  getchar();
  return 0;
}
