#pragma once
#include <mutex>
#include <vector>

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();
    Inventory(const Inventory &other);
    Inventory& operator=(const Inventory& inventory);

    void Put(int iterations);
    void Get(int iterations);
    void ReportRepeats();

private:
    int counter = 0;
    std::vector<int> items;
    std::mutex mutex;
};
