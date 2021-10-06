#include <iostream>
#include "transaction.hpp"
using namespace std;

void bank_live(BankRecord *account_record, const char * prefix="bank_live BankRecord")
{
    int option;

    while(1){
        //clrscr();
        cout <<endl <<endl <<endl <<endl <<endl;
        cout << "pradeep singh banking system " << endl
             << "press 0 to create bank account" <<endl
             << "press 1 to show records" <<endl
             << "press 2 to show balance" <<endl
             << "press 3 to deposit " <<endl
             << "press 4 to withdraw" <<endl
             << "press 5 to change interest rate" <<endl
             << "press 6 to change name "<<endl;

        cin >> option;

        if (option == 0){
            account_record->createBankRecord();
        }
        if (option == 1){
            account_record->show();
        } else if (option == 2) {
            account_record->user_balance();
        } else if (option ==3) {
            account_record->user_deposit();
        } else if (option == 4) {
            account_record->user_withdraw();
        } else if (option == 5) {
            account_record->user_credit_interest();
        } else if (option == 6) {
            account_record->user_name_change();
        }
    }
}


int main(int argc, char const *argv[])
{

    BankRecord account_record;

    bank_live(&account_record,"account_record");

    return 0; //NORMAL SHUTDOWN WITHOUT ANY ERROR (0 ERROR)
}
