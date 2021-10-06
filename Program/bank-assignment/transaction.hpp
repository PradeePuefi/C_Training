#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
#define NOT_A_NUMBER -1

class BankRecord
{
public:
    // user can modify name and interset rate
    string name;
    double interest_rate;

    double user_deposit(void);
    void show (const char *prefix = "BankRecord") const;
    double user_withdraw(void);
    double user_balance (void);
    double user_credit_interest(void);
    double user_name_change (void);
    // object must exist to call it.
    BankRecord* createBankRecord(void);

private:
    string password;
    int account_number;
    double balance;
    string last_name;

    int set_account_number (){
        // dummy account number
        return account_number == 12345;
    }

    string get_last_name (){
        return last_name;
    }

    //implicit inline function
    bool isValid() const
    {
        if ((account_number != 0) || (name.length() != 0) || (password.length() != 0))
            return false;

        return true;
    }

    double show_balance(){
        return balance;
    }

    double withdraw(double amount, string account_password);

    double deposit(int money_to_deposit) {
        balance += money_to_deposit;
        return balance;
    };

    double get_interest (void ){
        return interest_rate;
    }

    double set_interest ( double new_rate){
        interest_rate = new_rate;
        return interest_rate;
    }

     string get_password (){
        return password;
    }

    double set_password (string account_password) {
        password = account_password;
        return 0;
    }

};
