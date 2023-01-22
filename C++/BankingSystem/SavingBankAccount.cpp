#include "BankApplication.h"


// default constructor for no money
SavingBankAccount::SavingBankAccount(){}

SavingBankAccount::SavingBankAccount(double balance){
    Balance = balance;
    AccountID = "FCAI-0"+ to_string(ID++);
}

double SavingBankAccount::withdraw(double amount_taken){
    if (Balance > minimumBalance && ((Balance-amount_taken) >= minimumBalance)){
        Balance -= amount_taken;
        cout<<"Your Balance is :"<<Balance<<endl;
    }
    else {
        cout<<"Your Balance is not enough to take this money "<<endl;
    }
    return Balance;
}

double SavingBankAccount::deposit(double amount_taken){
    if (amount_taken >= 100){
        Balance += amount_taken;
        cout<<"Your Balance is :"<<Balance<<endl;
    }
    else {
        cout<<"You must input 100 or greater"<<endl;
    }
    return Balance;
}