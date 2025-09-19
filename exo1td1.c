#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(){

        printf("Player number\n");
        int pln;
        scanf("%d",&pln);
        printf("Number of sticks \n");
        int sln;
        scanf("%d",&sln);

        while(sln > 0){

            for(int i=1 ; i<=pln ; i++){
                
                for(int i=1 ; i<=sln ; i++){
                    printf("|");
                }
                printf("\n");
                
                printf("Player %d chose how much sticks you take , between 1 and %d   \n",i , sln);
                int p ;
                scanf("%d",&p);
                
                if(p>sln || p<0){
                    printf("Error ");
                }else{
                    sln = sln - p;
                    if(sln == 0){
                        printf("player %d have lost" , i);
                        break;
                    }
                }


            }

        }

    return 0;
}