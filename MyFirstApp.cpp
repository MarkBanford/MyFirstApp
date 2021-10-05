// MyFirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>

using namespace std;




class Transaction {
private:
    int amount;
    string type;

public:
    Transaction(int amt, string t) {
        amount = amt;
        type = t;

    };

    string Report() {
        string report;
        report = " ";
        report += type;
        report += " ";
        report += to_string(amount);
        return report;


    }

};


class Account {
private:
    int balance;
    vector<Transaction> log;

public:
    Account() {
        balance = 0;
    };

    vector<string> Report() {
        vector<string> report;
        report.push_back("Currenct Balance is " + to_string(balance));
        report.push_back("Transactions: ");
        for (auto t : log) {
            report.push_back(t.Report());
        }
        report.push_back("_________________");
        return report;

    };

    bool Deposit(int amt) {
        if (amt >= 0) {
            balance += amt;
            log.push_back(Transaction(amt, "Deposit"));
            return true;
        }
        else {
            return false;
        }


    }

    bool withdraw(int amt) {

        if (amt >= 0) {
            if (balance >= amt) {
                balance -= amt;
                log.push_back(Transaction(amt, "Withdraw"));
                return true;
            }
            else {
                return false;
            }
        }

    }

};


int main() {

    Account a1;
    a1.Deposit(90);
    cout << "After depositing £90" << endl;
    for (auto s : a1.Report()) {
        cout << s << endl;
    }
}


