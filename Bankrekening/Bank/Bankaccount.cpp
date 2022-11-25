#include "Bankaccount.h"

#include <ostream>

Bankaccount::Bankaccount(double startingBalance = 0)
{
    balance = startingBalance;
    history.clear();
}

Bankaccount::~Bankaccount()
= default;

Bankaccount::Bankaccount(const Bankaccount& other)
{
    balance = other.balance;
}

Bankaccount& Bankaccount::operator=(const Bankaccount& otherAccount)
= default;

double Bankaccount::GetBalance() const
{
    return balance;
}

Bankaccount Bankaccount::operator+(const Transactions& transaction)
{
    history.push_back(transaction);
    return { balance + transaction.GetAmount() };
}

Bankaccount& Bankaccount::operator+=(const Transactions& transaction)
{
    history.push_back(transaction);
    balance += transaction.GetAmount();
    return *this;
}

string Bankaccount::ShowTransactions() const
{
    string result = "\nTransaction history:\n";
    if (history.empty()) result += "No transactions in account\n";
    else
    {
        for (auto i = history.begin(); i != history.end(); i++)
        {
            result += i->ToString() + "\n";
        }
    }
    result += "Current balance: " + to_string(balance);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Bankaccount& bankaccount)
{
    os << bankaccount.ShowTransactions();

    return os;
}
