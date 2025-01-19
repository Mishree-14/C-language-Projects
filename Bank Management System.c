// BANK MANAGEMENT SYSTEM

#include <stdio.h>

typedef struct 
{
    char name[50];
    int account_number;
    float balance;
}account;

account bank_account;   //global variable to store account details 

void create_acc();
void deposit_money();
void withdraw_money();
void check_balance();

void create_acc () {
    int acc_no;
    printf("\nEnter your name: ");
    scanf("%s",bank_account.name);
    printf("\nEnter your account number: ");
    scanf("%d",&bank_account.account_number);
    bank_account.balance = 00;       //initialise balance to 0.
    printf("\nAccount created successfully!");
}
void deposit_money() {
    int acc_no;
    float amount;
    do{
        printf("\nEnter your account number: ");
        scanf("%d",&acc_no);
    
        if(acc_no == bank_account.account_number){
            printf("\nEnter amount you want to deposit: ");
            scanf("%f",&amount);
            if (amount > 0){
                bank_account.balance += amount;
                printf("\nMoney deposited successully!\n ");
                printf("\nCurrent balance Rs %.2f\n",bank_account.balance);
            }
            else{
                printf("Invalid amount!\n");
            }
        }    
        else{
            printf("Invalid account number!  ");
            printf("Please try again!\n");
        }  
    } while(acc_no != bank_account.account_number );   
}
void withdraw_money() {
    int acc_no;
    float withdraw;
    do{
        printf("\nEnter your account number: ");
        scanf("%d",&acc_no);
        if(acc_no == bank_account.account_number){
            printf("\nEnter amount to withdraw: ");
            scanf("%f",&withdraw);
            if(withdraw <= bank_account.balance){
                bank_account.balance -= withdraw;
                printf("\nWithdrawal successful!");
                printf("\nRemaining balance Rs %.2f",bank_account.balance);
            }
            else if(withdraw > bank_account.balance){
                printf("\nInsufficient balance!");
                printf("\n Your current balance Rs %.2f\n",bank_account.balance);
            }
            else {
                printf("Invalid amount!");
            }
            break;
        }    
        else{
            printf("\nInvalid acount number!  ");
            printf("Please try again!\n");
        }    
    } while (acc_no != bank_account.account_number);   
}
void check_balance() {
    int acc_no;
    printf("\nEnter your account number: ");
    scanf("%d",&acc_no);
    if(acc_no == bank_account.account_number){
        printf("\nYour current balance Rs %.2f",bank_account.balance);
    }
    else{
        printf("\nInvalid acount number!  ");
        printf("Please try again!\n");
    }    
}

int main(){
    int choice;
    while(1){
        printf("\n\n*** BANK MANAGEMENT SYSTEM ***");
        printf("\n1. Create account");
        printf("\n2. Deposit money");
        printf("\n3. Withdraw money");
        printf("\n4. Check balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                create_acc();
                break;
            }
            case 2: {
              deposit_money();
              break;
            }
            case 3: {
              withdraw_money();
              break;
            }
            case 4: {
              check_balance();
              break;
            }
            case 5: { 
                printf("\nExiting...Thanks for your visit!");
                return 0;
            }
            default: {
                printf("\nInvalid choice!\nPlease try again!");
            }
        }

    }
    return 0;
}
