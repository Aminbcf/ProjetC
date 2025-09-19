#include <stdio.h>
#include <stdlib.h>




int main(){

    int num1 , num2;
    scanf("%d%d",&num1 , &num2);

    printf("num1 = %d \nnum2 = %d " , num1 , num2);

    num1 = num2 + num1;
    num2 = (num1 - num2);
    num1 = num1 - num2;


    printf("\nnum1 after the swap = %d" , num1);
    printf("\nnum2 after the swap = %d" , num2);




    return 0;
}