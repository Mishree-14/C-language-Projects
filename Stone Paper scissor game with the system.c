// Stone Paper Scissor game
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(0));

    int player,computer = ((rand() % 3) + 0);      //prints random number from 0, 1, 2 
    
    printf("Enter 0-->stone, 1-->paper, 2-->scissor.\n");
    scanf("%d",&player);

    printf("%d\n",computer);
    
    if (player==0 && computer==0 || player==1 && computer==1 || player==2 && computer==2){
        printf("DRAW!\n");
    }
    else if(player==0 && computer==1 || player==1 && computer==2 || player==2 && computer==0){
        printf("Computer wins!");
    }
    else{
        printf("Player wins!");
    }
    return 0;
}
