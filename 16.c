//TIC TAC TOE GAME

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard();
void printboard();
int checkfreespaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);


void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

void printboard(){
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

int checkfreespaces(){
    int freespaces = 9;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(board[i][j] != ' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playermove(){
    int x;
    int y;

    do{
        printf("Enter row (1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter column (1-3): ");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' '){
            printf("Preocupied space!\n");
        }
        /*else if(x < 0 || x > 3 || y < 0 || y >= 3) {
            printf("Invalid input! Please try again.\n");
        }*/
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');

}

void computermove(){
    
    srand(time(0));       //seeds a random number from 0,1,2

    int x;
    int y;

    
    if( checkfreespaces() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else{
        printwinner(' ');       //there is no winner. It's a draw.
    }

}

char checkwinner(){
    //check rows
    for(int i=0;i<3;i++){
        if( board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
    }

    //check columns
    for(int i=0;i<3;i++){
        if( board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    //check diagonals
    
    if( board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if( board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }
    

    return ' ';
}

void printwinner(char winner){
    if(winner == PLAYER){
        printf("YOU WIN!\n");
    }
    else if(winner == COMPUTER){
        printf("YOU LOSE!\n");
    }
    else{
        printf("DRAW!\n");
    }
}


int main(){
    char winner = ' ';
    char response = ' ';

    do
    {
        resetboard();
        winner = ' ';

        while(winner == ' ' && checkfreespaces() != 0){
            printboard();

            playermove();
            winner = checkwinner();
            if(winner != ' ' || checkfreespaces() == 0){     //checks for winner after player's move.
                break;
            }

            computermove();
            winner = checkwinner();
        }

        printboard();
        printwinner(winner);

        printf("Would you like to play again? (Y/N): ");
           //to avoid buffer     it can also be like this(in second scanf): (" %c",&response).  [space before %c]
        scanf(" %c", &response);
        response = toupper(response);  //converts lowercase to uppercase.

    } while (response == 'Y');
    
    printf("\nThanks for playing!\n");

    return 0;
}