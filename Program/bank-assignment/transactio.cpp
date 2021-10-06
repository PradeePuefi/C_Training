#include <iostream>
#include "transaction.hpp"

using namespace std;

BankRecord* BankRecord::createBankRecord()
{
    string first_name, last_name, account_password;
    double account_balance;

    cout << "please provide first name - ";
    getline (cin, first_name);
    cout << "please provide last name - ";
    getline (cin, last_name);
    cout << "please provide password for account - ";
    getline (cin, account_password);
    cout << "please enter deposit amount - ";
    cin >> account_balance;
    cout << endl;

    if((account_balance > 0)  && (account_password.length() != 0))
    {
        BankRecord::deposit(account_balance);

        first_name.append(last_name);
        name = first_name;

        password = account_password;

        if (isValid()){
            cout << "Thanks for inputs\n";
        } else {
            cout << "Please provide valid inputs" <<endl;
        }
    } else {
        cout << "Please provide valid inputs" <<endl;
    }

    return this;

}

double BankRecord::user_name_change ()
{
    string first_name, last_name;

    cout << "please provide first name" <<endl;
    getline (cin, first_name);
    cout << "please provide last name" <<endl;
    getline (cin, last_name);

    if (!last_name.compare(BankRecord::get_last_name())) {
        first_name.append(last_name);
        name = first_name;
        cout << "name change is successfull"
             << name <<endl;
    } else {
        cout << "please provide valid inputs, only first name can be modified"<<endl;
        return 1;
    }
    return 0;
}


double BankRecord::user_balance()
{
    cout << "Current Balance for user "
         << name
         << "is :"
         << BankRecord::balance <<endl;

    return 0;
}


double BankRecord::user_credit_interest()
{
    double calculated_interest;
    double new_interest_rate;

    cout << "please provide new interest rate:" <<endl;
    cin >> new_interest_rate;

    calculated_interest = BankRecord::get_interest();
    calculated_interest += calculated_interest/10;

    if (new_interest_rate > calculated_interest) {
        cout << "set interest rate "
             << new_interest_rate
             << "is far gretaer than current interest rate"
             << BankRecord::get_interest() <<endl;
        return 0;
    }
    else
        cout << "new interest rate for account is : " << new_interest_rate;

    return new_interest_rate;
}


double BankRecord::withdraw(double amount, string account_password)
{
    // neep to check certain use cases
    if (amount > balance)
        return 0;

    if (!account_password.compare(password))
        balance -= amount;
    else
        return 0;

    return balance;
}


double BankRecord::user_withdraw()
{
    double ret_val = 0;
    double withdraw_amount = 0;
    string account_password;

    cout << "please provide withdraw amount:" <<endl;
    cin >> withdraw_amount;

    cout << "please provide password :" <<endl;
    getline (cin, account_password);
    ret_val = BankRecord::withdraw(withdraw_amount, account_password);

    if (ret_val == 0) 
        cout << "transaction decliend, please check balance or password\n";
    else
        cout << "Successfull: Current balance is : " << ret_val;

    return 0;
}


double BankRecord::user_deposit()
{
    double deposit_money;

    cout << "Please enter amount to deposit:" <<endl;
    cin >> deposit_money;
    cout << "\n";

    // call private function to deposit money
    BankRecord::deposit(deposit_money);

    cout << "your current account balance is :" << balance <<endl;

    return 0;
}

void BankRecord::show(const char *prefix) const
{

    if (isValid())
    {
        cout << prefix 
             << "Name: " << name << "\n"
             << "Account number: " << account_number << "\n"
             << "Balance: " << balance << "\n"
             << "Interest Rate: " << interest_rate << "\n";
    }
    else
    {
        cout << "<invalid BankRecord>" << endl;
    }
}