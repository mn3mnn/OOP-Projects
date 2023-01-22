#include "BankApplication.h"

int BankAccount::ID = 1;

// default constructor for no money
BankAccount::BankAccount(){}

BankAccount::BankAccount(double balance){
    Balance = balance;
    AccountID = "FCAI-0"+ to_string(ID++);
}

void BankAccount::Set_Balance(double Temp_Balance){
    Balance = Temp_Balance;
}

double BankAccount::Get_Balance(){
    return Balance;
}

string BankAccount::Get_ID(){
    return AccountID;
}

// function to make the Client take money
double BankAccount::withdraw(double amount_taken ) {
    if (Balance > amount_taken) {
        Balance -= amount_taken;
        cout<<"Your Balance is :"<<Balance<<endl;
    }
    else {
        cout<<"Your Balance is not enough to take this money "<<endl;
    }
    return Balance;
}

// function to make the Client input money
double BankAccount::deposit(double amount_input) {
    Balance += amount_input;
    cout<<"Your Balance New = "<<Balance<<endl;
    return Balance;
}
