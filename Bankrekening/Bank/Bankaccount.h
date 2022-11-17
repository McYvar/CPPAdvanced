#pragma once
#include <list>
#include <vector>
#include "Transactions.h"

class Bankaccount
{
public:
    Bankaccount(double startingBalance);
    virtual ~Bankaccount();
    Bankaccount(const Bankaccount& other);
    Bankaccount& operator=(const Bankaccount& otherAccount);
    double GetBalance() const;
    Bankaccount operator+(const Transactions& transaction);
    Bankaccount& operator+=(const Transactions& transaction);
    string ShowTransactions() const;
    

private:
    friend std::ostream& operator<<(std::ostream& os, const Bankaccount& bankaccount);
    vector<Transactions> history;
    double balance;
};
