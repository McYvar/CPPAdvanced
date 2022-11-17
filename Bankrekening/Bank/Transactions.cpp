#include "Transactions.h"

Transactions::Transactions(double amount, uint8_t day, uint8_t month, uint16_t year)
{
    this->amount = amount;
    this->day = day;
    this->month = month;
    this->year = year;
}

double Transactions::GetAmount() const
{
    return amount;
}

uint8_t Transactions::GetDay() const
{
    return day;
}

uint8_t Transactions::GetMonth() const
{
    return month;
}

uint16_t Transactions::GetYear() const
{
    return year;
}

string Transactions::ToString() const
{
    string result = "Transaction on (mm/dd/yyy): ";
    if (month > 9) result += to_string(month) + "/";
    else result += "0" + to_string(month) + "/";

    if (day > 9) result += to_string(day) + "/";
    else result += "0" + to_string(day) + "/";

    result += to_string(year) + "\nAmount: " + to_string(amount) + "\n";
    return result;
}
