# Banking-System OOP

The banking application allows the user, i.e., the bank employee to create a bank account for a specific client. It allows him to list all the available 
bank accounts. For each account, it allows him to display the account details, withdraw money and 
deposit money.

There are two types of bank accounts. The first type is the basic BankAccount. It holds the 
following data:

•        account ID

•        balance

The second type of accounts extends the basic Bank Account and may have some extra data fields 
and operations. It is called SavingsBankAccount. This account requires the user to keep a 
minimum amount of money in the account, which is called the minimum balance, as long as the 
account is open. It also requires him to make deposits that are not less than 100 a time. So, it has 
the following additional data field:

•        minimumBalance 
This minimum balance takes a default value of 1000 L.E. 

There is also a Client class which holds the basic information of a client like his name, address 
and phone number. It holds a pointer to his bank account. An account also points to its owner. 

The main class that runs the application is BankingApplication. This class displays the main 
menu and accepts the user's choice. It maintains a list of accounts and clients. It allows the user to 
perform operations on a bank account.


### test case:
```
Welcome to FCAI Banking Application 
1. Create a New Account 
2. List Clients and Accounts 
3. Withdraw Money 
4. Deposit Money 
Please Enter Choice =========> 1
Please Enter Client Name =========> Ahmed Ali Salem 
Please Enter Client Address =======> 5 Batn Elzeer St., Giza 
Please Enter Client Phone =======> 0120130140 
What Type of Account Do You Like? (1) Basic (2) Saving –    Type 1 or 2 =========> 1 
Please Enter the Starting Balance =========> 1500 
An account was created with ID FCAI-001 and Starting Balance 1500 L.E. 
-------------------------------------------------------------------
Welcome to FCAI Banking Application 
1. Create a New Account 
2. List Clients and Accounts 
3. Withdraw Money 
4. Deposit Money 
Please Enter Choice =========> 3
Please Enter Account ID (e.g., FCAI-015) =========> FCAI-001 
Account ID: FCAI-001 
Acocunt Type: Basic 
Balance: 1500 
Please Enter The Amount to Withdraw =========> 1550 
Sorry. This is more than what you can withdraw. 
Please Enter The Amount to Withdraw =========> 40 
Thank you. 
Account ID: FCAI-001 
New Balance: 1460 
```
