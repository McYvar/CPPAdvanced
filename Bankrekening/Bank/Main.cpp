#include <iostream>

#include "Bankaccount.h"

int main()
{
    Bankaccount b1 = Bankaccount(10.04);
    
    b1 += Transactions(12.03, 17, 11, 2022);
    b1 += Transactions(20003.55, 3, 9, 2026);

    cout << b1;
    return 0;
}
