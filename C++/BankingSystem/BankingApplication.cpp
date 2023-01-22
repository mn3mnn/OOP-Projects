#include "BankApplication.h"

// empty constructor
BankingApplication::BankingApplication()= default;

// destructor that deletes all dynamically allocated memory
BankingApplication::~BankingApplication() {
    // delete the allocated memory for the objects
    for (auto & client : clients) {
        delete client;
    }
    for (auto & account : BasicAccounts) {
        delete account;
    }
    for (auto & account : SavingAccounts) {
        delete account;
    }
}

void BankingApplication::run() {

    while (true) {
        cout << "Welcome to FCAI Banking Application \n"
                "1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money\n"
                "Please Enter Choice =========>";

        // take valid choice
        string choice ;
        cin >> choice;
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
            cin.ignore();
            cout << "please select valid choice (1 to 4): ";
            cin >> choice;
        }

        if (choice == "1") {
            // ptr to a new client object
            auto* client = new Client();
            cout << "Please Enter Client Name =========>";
            cin.ignore();
            getline(cin, client->Name, '\n');

            cout << "Please Enter Client Address =======>";
            getline(cin, client->Address, '\n');

            cout << "Please Enter Client Phone =======>";
            getline(cin, client->Phone_Num, '\n');

            cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
            int choice2;
            cin >> choice2;
            if (choice2 == 1) {
                cout << "Please Enter the Starting Balance =========>";
                cin >> input_Balance;

                if (is_valid_client(client)) {
                    // ptr to a new account object
                    auto* account = new BankAccount(input_Balance);
                    // make account points to his owner_b
                    account->owner_b = client;
                    // make client points to his account
                    client->acc1 = account;
                    // add the ptr to the created objects to the list
                    BasicAccounts.push_back(account);
                    clients.push_back(client);

                    system("cls");
                    cout << "registration successful\n\n";
                }
                else {
                    cerr << "registration unsuccessful\n\n";
                }
            }
            else if (choice2 == 2){
                cout << "Please Enter the Starting Balance Knowing that the Minimum Balance is 1000 =========>";
                cin >> input_Balance;
                if (input_Balance < 1000){
                    cout<<"your money is not enough to make this account"<<endl;
                }
                else {
                    if (is_valid_client(client)) {
                        // ptr to a new account object
                        auto* account = new SavingBankAccount(input_Balance);
                        // make account points to his owner_b
                        account->owner_s = client;
                        // make client points to his account
                        client->acc = account;
                        // add the ptr to the created objects to the list
                        SavingAccounts.push_back(account);
                        clients.push_back(client);

                        system("cls");
                        cout << "registration successful\n\n";
                    }
                    else {
                        system("cls");
                        cerr << "registration unsuccessful\n\n";
                    }
                }
            }
        }
        else if (choice == "2") {
            system("cls");
            if (clients.empty()) {
                cout << "No clients";
            }
            Print();
            cout<<endl;
        }
        else if (choice == "3") {
            cout<<"Please Enter Account ID (e.g., FCAI-015) =========>";
            string AccId;
            cin.ignore();
            cin >> AccId;

            for(auto account : BasicAccounts) {
                if (AccId == account->Get_ID()) {
                    cout << "Account ID:" << account->Get_ID() << endl;
                    //we want the acc type
                    cout << "Balance:" << account->Get_Balance() << endl;

                    double WithDraw_In;
                    cout << "Please Enter The Amount to Withdraw =========> ";
                    cin >> WithDraw_In;

                    account->withdraw(WithDraw_In);

                    break;
                }
            }
            for (auto savingaccounts :SavingAccounts) {
                if (AccId == savingaccounts->Get_ID()){
                    cout << "Account ID:" << savingaccounts->Get_ID()<<endl;
                    //we want the acc type
                    cout << "Balance:" << savingaccounts->Get_Balance()<<endl;

                    double WithDraw_In;
                    cout << "Please Enter The Amount to Withdraw =========> ";
                    cin >> WithDraw_In;

                    savingaccounts->withdraw(WithDraw_In);

                    break;
                }
            }
        }
        else if (choice == "4") {
            cout<<"Please Enter Account ID (e.g., FCAI-015) =========>";
            string AccId;
            cin.ignore();
            cin >> AccId;

            for(auto account : BasicAccounts) {
                if (AccId == account->Get_ID()) {
                    cout << "Account ID:" << account->Get_ID() << endl;
                    //we want the acc type
                    cout << "Balance:" << account->Get_Balance() << endl;

                    double WithDraw_In;
                    cout << "Please Enter The Amount to deposit =========> ";
                    cin >> WithDraw_In;

                    account->deposit(WithDraw_In);

                    break;
                }
            }
            for (auto savingaccounts :SavingAccounts) {
                if (AccId == savingaccounts->Get_ID()){
                    cout << "Account ID:" << savingaccounts->Get_ID()<<endl;
                    //we want the acc type
                    cout << "Balance:" << savingaccounts->Get_Balance()<<endl;

                    double WithDraw_In;
                    cout << "Please Enter The Amount to deposit =========> ";
                    cin >> WithDraw_In;

                    savingaccounts->deposit(WithDraw_In);

                    break;
                }
            }
        }
    }
}

// check for the name and phone number from any wrong input
bool BankingApplication::validation(const string& name,const string& phone_num) {
    regex ValidInputPhone("[0-9]{11}");
    regex ValidInputName("^([a-zA-Z]+ ?)+$");
    if (regex_match(name,ValidInputName) && regex_match(phone_num,ValidInputPhone)){
        return true;
    }
    return false;
}

bool BankingApplication::is_valid_client(Client* client) {

    if (!validation(client->Name, client->Phone_Num)) {
        return false;
    }
    for (auto & c : clients) {
        if (client->Name == c->Name && client->Address == c->Address && client->Phone_Num == c->Phone_Num) {
            return false;
        }
    }
    return true;
}

void BankingApplication::Print(){

    for(auto client : clients){
        cout<<"-------------------------- "<<client->Name<<" ---------"<<endl;
        cout<<"Address: "<<client->Address<<endl;
        cout<<"Phone: "<<client->Phone_Num<<endl;
        if (client->acc1){
            cout<<"Account ID: "<< client->acc1->Get_ID() << endl;
            cout<<"Account Type: Basic "<<endl;
            cout<<"Balance: " << client->acc1->Get_Balance() << endl;
        }
        else {
            cout<<"Account ID: "<< client->acc->Get_ID() << endl;
            cout<<"Account Type: Saving "<<endl;
            cout<<"Balance: " << client->acc->Get_Balance() << endl;
        }
    }
}
