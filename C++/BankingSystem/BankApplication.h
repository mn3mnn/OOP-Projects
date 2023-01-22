
#ifndef BANKACCOUNT_BANKACCOUNT_H
#define BANKACCOUNT_BANKACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;
class SavingBankAccount ;
class Client ;

class BankAccount {
protected:
    double Balance;
    string AccountID;
    static int ID;
public:

    Client* owner_b = nullptr;
    // default constructor for no money
    BankAccount();

    // constructor to add the balance
    explicit BankAccount(double balance);

    void Set_Balance(double Temp_Balance);
    double Get_Balance();
    string Get_ID();

     // function to make the Clint take money
     virtual double withdraw(double amount_taken);

    virtual double deposit(double amount_input);
};

class Client{
public:

    BankAccount* acc1 = nullptr;
    SavingBankAccount* acc = nullptr;
    string Name, Address ,Phone_Num;
    Client();
    Client(string name,string address,string phone_num);

};

class BankingApplication{
public:
    vector <Client*> clients;
    vector <BankAccount*> BasicAccounts;
    vector <SavingBankAccount*> SavingAccounts;
    void Print();
    double input_Balance{};
    BankingApplication();
    ~BankingApplication();
    void run();
    bool is_valid_client(Client* client);
    static bool validation(const string& name,const string& phone_num);

};

class SavingBankAccount : public BankAccount{
private:
    int const minimumBalance = 1000;

public:
    Client* owner_s = nullptr ;
    SavingBankAccount();
    explicit SavingBankAccount(double balance);

    double withdraw(double amount_taken) override;
    double deposit(double amount_taken) override;
};

#endif //BANKACCOUNT_BANKACCOUNT_H