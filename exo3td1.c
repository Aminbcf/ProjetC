#include <stdio.h>
#include <stdlib.h>


int main(){

    printf("Donner un nombre ");
    int num;
    scanf("%d",&num);
   
    if (num > 0 && (num & (num - 1)) == 0) {
        printf("le Nombre est une puisssance de 2 ");
    
    }else{
        printf("Le nombre n'est pas une puicance");
    }



    return 0;
}