// SUDOKU PUZZLE SOLVER
#include<stdio.h>

int puzzle[9][9] = {
    {5,0,0,0,0,0,0,0,8},
    {0,0,0,4,0,0,0,2,0},
    {0,0,0,0,8,0,0,0,0},
    {0,0,0,0,6,0,0,0,0},
    {0,7,0,0,0,0,0,4,0},
    {0,0,0,0,9,0,0,0,0},
    {0,0,0,0,2,0,0,0,0},
    {0,3,0,0,0,7,0,0,0},
    {9,0,0,0,0,0,0,0,5},

};

void print_puzzle (int puzzle[9][9]);

void print_puzzle (int puzzle[9][9]){
    printf("\n\n+-------+-------+-------+");
    for(int i=0;i<9;i++){
        
        if(i % 3 == 0 && i != 0 ){
            printf("\n|-------|-------|-------|\n");
        }
        else{
            printf("\n");
        }
        for(int j=0;j<9;j++){
           
            if(j % 3 == 0 ){
                printf("| ");
            }
            if(puzzle[i][j] == 0){
                printf("  ");
            }
            else{
                printf("%d ",puzzle[i][j]);
            }
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+"); 
}

int valid_move(int puzzle[9][9],int row,int col,int num){
    for(int i=0;i<9;i++){       //to check row and column for every num 
        if(puzzle[row][i] == num || puzzle[i][col] == num){        //num alreday present in the row or col
            return 0;      //invalid or false condition.   no need of else condition bcz if this condition satisfy no need of else if this cond isfalse then only else cond is req.
        }
    }
    // to check square for every num 
    int start_row = row - (row % 3);    // starts from 0 for every square (0,1,2)
    int start_col = col - (col % 3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(puzzle[start_row + i][start_col + j] == num){
                return 0;     //tells that num can't be fitted here bcz it is already present in the subgrid else.
            }
        }
    }
    return 1;               //move is valid
}

int solution(int puzzle [9][9]){
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (puzzle[i][j] == 0){                                  //checks for empty cell
                for(int num = 1; num <= 9; num++){                   //trys num 1 to 9
                    if(valid_move(puzzle , i , j , num)){            //checks if the move is valid
                        puzzle[i][j] = num;                          //tentatively places the num
                    
                        if (solution(puzzle)){                       //recuesively solve the updatd puzzle
                            return 1;                                // if solved, return success
                        }
                        puzzle[i][j] = 0;                            //undo the move (back tracking). backtracking step, allowing the algorithm to explore other possible numbers.
                    }
                }
                return 0;                               // If no valid number is found, backtrack
            }
        }    
    }
    return 1;                         //if no empty cell found the puzzle is completed
}

int main(){
    printf("-----INITIAL SUDOKU-----\n");
    print_puzzle (puzzle);

    if(solution(puzzle)){
        printf("\n\n-----SOLVED SUDOKU-----");
        print_puzzle(puzzle);
    }
    else{
        printf("\n NO SOLUTION EXIST!");
    }
    return 0;
}



/*
Logical Flow Summary of solution of the puzzle 
Find the First Empty Cell:

The nested loops identify the first empty cell (i, j) in the grid.
Try All Possible Numbers (1 to 9):

For the empty cell, the function tries placing numbers 1 to 9.
Check Validity:

The valid_move function ensures the number follows Sudoku rules.
Recursively Solve the Updated Puzzle:

After placing a valid number, the function recursively calls itself to solve the rest of the puzzle.
Backtrack if Needed:

If a number doesn’t lead to a solution, the function undoes the move (resets the cell to 0) and tries the next number.
Return Success or Failure:

If the puzzle is solved, the function returns 1.
If no valid configuration works, it returns 0.
*/