#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp, *sf;
    fp = fopen("db.txt", "r");
    sf = fopen("claves.txt", "w");
    int j, k, i=0;
    char c;
    int arr[20][2], aux[2];
    do{
        fscanf(fp, "%d %d", &arr[i][0], &arr[i][1]);
        while((c=fgetc(fp))!='\n' && c!=EOF);
        i++;
    }while(c!=EOF);

    for(j=0;j<i;j++){
        for(k=j+1;k<i;k++){
            if(arr[j][1]>arr[k][1]){
                aux[0] = arr[j][0]; 
                aux[1] = arr[j][1];
                arr[j][0] = arr[k][0];
                arr[j][1] = arr[k][1];
                arr[k][0] = aux[0];
                arr[k][1] = aux[1];
            }
        }
    }
    fprintf(sf, "%d\n", i);
    for(j=0;j<i;j++){
        fprintf(sf, "%d %d\n", arr[j][1], arr[j][0]);
    }
    return 0;
}