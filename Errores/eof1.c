//Una vez abierto el archio, un bucle mientras(while) no se el fin del archivo
//(macro EOF) lee caracter a caracter y se escribe en el archivo asociado al puntero FILE
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *salida;
  int c;
  //Definir la direccion de los archivos
  char nm[]="/Users/max/Documents/Code/c_le/archivos/Errores/salida.txt";

  //Abrir el archivo salida en modo de escritura
  salida = fopen(nm, "w");

  //Comporbar que la apertura del archivo haya sido correcta en caso contrario
  //terminar la ejecucion
  if(salida == NULL){
    puts("\nError al abrir el archivo");
    exit(-1);
  }

  //Leer entrada hasta leer el final (o hasta que se detenga manualmente la ejecucion del programa)
  //y guardar entrda en archivo salida
  while((c=getc(stdin))!=EOF){
    fputc(c, salida);
  }

  //Cerrar el archivo
  fclose(salida);
  printf("\n\n\n\n");
  getchar();
  return 0;
}
