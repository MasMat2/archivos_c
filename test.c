#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char nm[] = "numbers.txt";
    int e, t;
    char c;
    fp = fopen(nm, "w+");
    while ((c = getchar()) != '\n')
    {
        e = atoi(&c);
        fwrite(&e, sizeof(int), 1, fp);
    }
    printf("\n\nReport\n");
    rewind(fp);
    // fseek(fp, -sizeof(int), SEEK_CUR);
    // while (ftell(fp))
    while ((t = fread(&e, sizeof(int), 1, fp)))
    {
        // fseek(fp, -2 * sizeof(int), SEEK_CUR);
        printf("%d\n", t);
    }
}
