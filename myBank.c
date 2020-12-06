#include <stdio.h>
#include "myBank.h"

#define LENGTH 50
#define OPEN 1
#define CLOSE 0

double accounts [LENGTH][2] = {0};

// Opening an account and saving the initial deposit amount.
// Prints the new account number.
// Opening an account is only possible if there are less than 50 open accounts.
void openAccount(double a){
	if (a > 0)
	{
		int i;
		for(i = 0; i < LENGTH; i++){
			if(accounts[i][0] == CLOSE){
				accounts[i][0] = OPEN;
				accounts[i][1] = a;
				printf("Your account number is: %d \n",i + 901);
				break;
			}
    	}
	}
	else
	{
		return;
	}		
}

// Balance check, receives the account number and prints the balance.
// This is only allowed if the account is open.
void balance(int account){
	if(accounts[account-901][0] == OPEN){
	    double balance = accounts[account-901][1];
		printf("Yours balance is: %0.2lf \n", balance);
	}
	else{
		printf("You can't see the balance. The account number doesn't exist! \n");
	}
}

// Deposit, receives the account number and prints the the new balance.
// This is only allowed if the account is open.
void deposite(int account, double d){
	if((accounts[account-901][0] == OPEN) && (d > 0)){
		accounts[account-901][1] += d;
		printf("Yours new balance is: %0.2lf \n",accounts[account-901][1]);
	}
	else{
		printf("You don't have an account, or you didn't deposite positive number \n");
	}
}

// Withdrawal, get the account number and print the the new balance.
// This is only allowed if the account is open and there are enough cash to withdraw.
void withdrawal(int account, double w){
	if((accounts[account-901][0] == OPEN) && (accounts[account-901][1] >= w) && (w > 0)){
		accounts[account-901][1] -= w;
		printf("Yours new balance is: %0.2lf \n",accounts[account-901][1]);
	}
	else{
		printf("You don't have an account, or you want to withdraw more than the balance \n");
	}
}

// Account closing.
// Only allowed if the account is open.
void closeAccount(int account){
	if(accounts[account-901][0] == OPEN){
		accounts[account-901][0] = CLOSE;
		accounts[account-901][1] = 0;
		printf("Yours account is closed!\n");
	}
	else{
		printf("You don't have an account \n");
	}
}

//Adding interest at a given percentage rate to all open accounts.
void interest(double in){
	int i;
	for(i = 0; i < LENGTH; i++){
		if(accounts[i][0] == OPEN){
			accounts[i][1] += ((accounts[i][1])*(in/100));
		}
	}
    printf("The interest has been added to all accounts \n");
}

//Print all open accounts and the balance in them.
void printAll(){
	int i;
	for(i = 0; i < LENGTH; i++){
		if(accounts[i][0] == OPEN){
			printf("Account number: %d , balance: %0.2lf \n",i+901, accounts[i][1]);
		}
	}
}

//Closing all accounts and exiting the program.
void closeAll(){
	int i;
	for(i = 0; i < LENGTH; i++){
		if(accounts[i][0] == OPEN){
			accounts[i][0] = CLOSE;
			accounts[i][1] = 0;
	    }
     }
    printf("All the accounts are closed!\n");
}