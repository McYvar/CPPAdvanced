#include "Inventory.h"

#include <algorithm>
#include <iostream>

Inventory::Inventory()
{
    counter = 0;
    items = std::vector<int>();
}

Inventory::~Inventory()
= default;

Inventory::Inventory(const Inventory& other)
{
    counter = other.counter;
    items = other.items;
}

Inventory& Inventory::operator=(const Inventory& inventory)
{
    this->items = inventory.items;
    this->counter = inventory.counter;
    return *this;
}

void Inventory::Put(int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        mutex.lock();
        counter++;
        items.push_back(counter);
        mutex.unlock();
    }
}

void Inventory::Get(int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        if (items.empty()) continue;
        mutex.lock();
        counter--;
        items.pop_back();
        mutex.unlock();
    }
}

void Inventory::ReportRepeats()
{
    std::sort(items.begin(), items.end());
    
    bool repeated = false;
    for (int i = 0; i < items.size() - 1; i++) {
        repeated |= (items[i] == items[i + 1]);
    }

    // if not tread save, then method should create repeated values
    std::cout << (repeated ? "repeat" : "no repeat") << std::endl;
}
