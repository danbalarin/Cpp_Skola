#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <ctime>
#include <math.h>
void Vypis(int pole[], int velikost)
{
    for(int i=0;i<velikost;++i)
        printf("%d ", pole[i]);
    printf("\n");
}
int neco(int p[], int velikost){
    float prumer = 0;
    for(int i = 0; i<velikost; i++){
        prumer += p[i];
    }
    prumer = prumer/velikost;
    printf("Prumer je: %.2f\n", prumer);
    int temp = 0;
    for(int i = 0; i<velikost; i++){
        if(p[i]>prumer){
            printf("%d ", p[i]);
            p[temp] = p[i];
            temp++;
        }
    }
    p = (int *) realloc(p, sizeof(int)*temp);
    Vypis(p,temp);
    return temp;
}

int main(int argc, char *argv[])
{
srand(time(NULL));
int * p;
int velikost = 0;
p = (int *) malloc(sizeof(int)*velikost);
while(1)
{
    int cislo;
    scanf("%d", &cislo);
    if (cislo==0)
        break;

    velikost+=cislo;
    p = (int *) realloc(p, sizeof(int)*velikost);
    for(int i=velikost-cislo;i<velikost;++i)
        p[i] = rand()%10;
    Vypis(p, velikost);
}
int k;
velikost = neco(p,velikost);
while(scanf("%d",&k)){
    if(k==0) break;
    velikost = neco(p,velikost);
}
}
