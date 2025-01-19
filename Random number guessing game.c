// Random Number Guessing game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));     //generates any random number

    int randomnumber = ((rand() % 100) + 1);    //prints any number between 1 and 100
    int guessed;
    int attempts = 0;

    printf("Random number: %d\n",randomnumber);
    printf("---------Welcome to the Number Guessing game---------\n");
    
    do{
        printf("Enter you guessed number between 1 and 100: ");
        scanf("%d",&guessed);
        attempts++;
        
        if(guessed<randomnumber){
            printf("Lower number guessed.\n");
        }
        else if( guessed>randomnumber){
            printf("Higher number guessed.\n");
        }
        else{
            printf("Congratulations !!! You guessed the number in %d attempts.\n",attempts);
        }

    } while (guessed!=randomnumber);

    return 0;
}
