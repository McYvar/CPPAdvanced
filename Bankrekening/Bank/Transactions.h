#pragma once
#include <cstdint>
#include <string>
using namespace std;

class Transactions
{
public:
    Transactions(double amount, uint8_t day, uint8_t month, uint16_t year);
    double GetAmount() const;
    uint8_t GetDay() const;
    uint8_t GetMonth() const;
    uint16_t GetYear() const;
    string ToString() const;
    
private:
    double amount;
    uint8_t day;
    uint8_t month;
    uint16_t year;
};
