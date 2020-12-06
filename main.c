#include <stdio.h>
#include "myBank.h"

int main(){
    
    int bool = 1;
    while(bool){

        char type;
        printf("Menu- \n\nO: Open new account \nB: Print balance \nD: Deposite  \nW: Withrawal \nC: Close account \n");
        printf("I: Add interest to all accounts \nP: Print all open accounts and balance \nE: Close all accounts and exit \n");
        scanf(" %c", &type);
        switch(type)
        {
            case 'O':
                printf("Initial deposit? \n");
                double amount = 0;
                scanf(" %lf", &amount);
                if(amount <= 0){
                    printf("please enter a positive real number! \n");
                    scanf(" %lf", &amount);
                }
                openAccount(amount);
            break;

            case 'B':
                printf("‫‪Account‬‬ ‫‪number?:‬‬ \n");
                int account_number = 0;
                scanf(" %d", &account_number);
                if((account_number < 901) || (account_number > 950)){
                    printf("This account doesn't exist! Enter your account number \n");
                    scanf(" %d", &account_number);
                }
                balance(account_number);
            break;

            case 'D':
                printf("‫‪Account‬‬ ‫‪number? \n");
                int account1 = 0;
                scanf(" %d", &account1);
                if((account1 < 901) || (account1 > 950)){
                    printf("This account doesn't exist! Enter your account number \n");
                    scanf(" %d", &account1);
                }
                printf("Amount? \n");
                double amount1 = 0;
                scanf(" %lf", &amount1);
                if(amount1 <= 0){
                    printf("Enter a positive real number! \n");
                    scanf(" %lf", &amount1);
                }
                deposite(account1, amount1);
            break;

            case 'W':
                printf("‫‪Account‬‬ ‫‪number? \n");
                int account2 = 0;
                scanf(" %d", &account2);
                if((account2 < 901) || (account2 > 950)){
                    printf("This account doesn't exist! Enter your account number \n");
                    scanf(" %d", &account2);
                }
                printf("Amount? \n");
                double amount2 = 0;
                scanf(" %lf", &amount2);
                if(amount2 <= 0){
                    printf("Enter a positive real number! \n");
                    scanf(" %lf", &amount2);
                }
                withdrawal(account2, amount2);
            break;

            case 'C':
                printf("‫‪Account‬‬ ‫‪number? \n");
                int account3 = 0;
                scanf(" %d", &account3);
                if((account3 < 901) || (account3 > 950)){
                    printf("This account doesn't exist! Enter your account number \n");
                    scanf(" %d", &account3);
                }
                closeAccount(account3);
            break;

            case 'I':
                printf("‫‪‫‪Interest rate‬‬? \n");
                double inter = 0;
                scanf(" %lf", &inter);
                if(inter <= 0){
                    printf("Enter a positive real number! \n");
                    scanf(" %lf", &inter);
                }
                interest(inter);
            break;

            case 'P':
                printAll();
            break;

            case 'E':
                closeAll();
                bool = 0;
            break;

            default:
            printf("Invalid transaction type");
        }       
    }
    
return 0;
}