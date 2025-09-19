#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

printf("Donner un nombre ");
int nb;
scanf("%d",&nb);
printf("0b");

if(nb){
    if(nb & 1){
     nb <<= 1;
        }
    }

return 0;
}