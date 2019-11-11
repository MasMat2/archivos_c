#include <stido.h>

struct persona{
  char nombre[30];
  char apellido[30];
  int edad;
}

int main(){
  FILE *personas
  char nm[]="\personas";
  personas = fopen(nm, "w");

  struct persona p1 = {"John", "Doe", 20};
  struct persona p2 = {"Jane", "Smith", 20};

}
