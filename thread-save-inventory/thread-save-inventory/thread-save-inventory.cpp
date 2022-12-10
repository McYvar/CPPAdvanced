
#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>

#include "Inventory.h"

int main() {
    auto i1 = new Inventory;

    std::thread t1(&Inventory::Put, i1, 20000);
    std::thread t2(&Inventory::Get, i1, 10000);
    std::thread t3(&Inventory::Put, i1, 24664);
    std::thread t4(&Inventory::Get, i1, 4340);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    i1->ReportRepeats();
    delete i1;
    
    return 0;
}