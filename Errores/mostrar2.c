//Una vez abierto el archivo de texto en modo lectura, un bucle mientras no sea
//fin de archivo (macro EOF) lee carácter a carácter y se escribe en pantalla.
//En el caso de leer el carácter de fin de línea se debe saltar a la línea
//siguiente y contabilizar una línea más.
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *salida;
  int c, n=0;
  //Definir la direccion de los archivos
  char nm[]="/salida.txt";

  //Abrir el archivo salida en modo de lectura
  salida = fopen(nm, "r");

  //Comporbar que la apertura del archivo haya sido correcta en caso contrario
  //terminar la ejecucion
  if(salida == NULL){
    puts("\nError al abrir el archivo");
    exit(-1);
  }

  //Leer cada caracter del archivo salida hasta leer el final
  //e imprimir en pantalla
  while((c=getc(salida))!=EOF){
    //Contabilizar los saltos de linea
    if(c=='\n'){
      n++;
      printf("\n");
    }
    else{
      putchar(c);
    }
  }

  printf("\nNumero de lineas del archivo: %d", n);

  //Cerrar el archivo
  fclose(salida);
  printf("\n\n\n\n");
  getchar();
  return 0;
}
