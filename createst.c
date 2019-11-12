#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cliente
{
    char nombre[20];
    char apellido[20];
    int no_cliente;
    int pswd;
    float balance;
    int no_transfer;
    int no_list;
};

int main()
{
    srand(time(NULL));
    int i;
    int counter=12345;
    int no_list=1;
    struct cliente cl;
    FILE *fp, *nm;
    fp = fopen("db.txt", "w+b");
    nm = fopen("names.txt", "r");
    for (i = 0; i < 10; i++)
    {
        fscanf(nm, "%s %s", cl.nombre, cl.apellido);
        cl.no_cliente = 1000 + (rand() % 1000);
        cl.pswd = 1111;
        cl.balance = (float) (rand() % 10000);
        do
        {
            cl.no_transfer = rand() % 10000;
        } while (cl.no_transfer < 1000);
        cl.no_list = no_list;
        no_list++;
        counter++;
        fwrite(&cl, sizeof(struct cliente), 1, fp);
    }
    rewind(fp);
    // fseek(fp, sizeof(struct cliente), SEEK_SET);
    // printf("%ld", ftell(fp));
    for(i=0;i<10;i++){
        fread(&cl, sizeof(struct cliente), 1, fp);
        printf("%ld", ftell(fp));
        printf("%s %s\nCliente: %d Contrasena: %d\nBalance: %.2f No_transfer: %d No_list: %d\n\n", cl.nombre, cl.apellido, cl.no_cliente, cl.pswd, cl.balance, cl.no_transfer, cl.no_list);
    }
    return 0;
}