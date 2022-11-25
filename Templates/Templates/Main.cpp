#include <valarray>

#include "Queue.h"

// Sorter template function
template <typename T>
std::vector<T> Sorter(std::vector<T> vec)
{
    sort(vec.begin(), vec.end());
    return vec;
}

int main()
{
    // Queue test
    auto q1 = new Queue<float>();
    q1->Put(1.3f);
    q1->Put(2.7f);
    q1->Put(3.2f);
    q1->Put(4.8f);
    q1->Put(5.1f);
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Put(5.38f);
    q1->Print();
    q1->Put(4.1f);
    q1->Print();
    q1->Get();
    q1->Print();
    q1->Put(3.694f);
    q1->Print();
    q1->Put(2.04f);
    q1->Print();
    q1->Put(1.01f);
    q1->Print();

    // Turn queue into vector
    std::vector<float> intvec = q1->ToVector();
    for(auto it = intvec.begin(); it != intvec.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    // Vector template sorter test
    intvec = Sorter<float>(intvec);
    for(auto it = intvec.begin(); it != intvec.end(); ++it)
    {
        std::cout << *it << " ";
    }

    // And now for Strings... (no idea how it sorts but it sorts something...)
    std::vector<std::string> stringvec;
    stringvec.push_back("Hello");
    stringvec.push_back("Sheeesh");
    stringvec.push_back("This is a complete and grammarly correct sentence");
    stringvec.push_back("This not");
    stringvec.push_back("FF");
    for(auto it = stringvec.begin(); it != stringvec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    stringvec = Sorter<std::string>(stringvec);
    for(auto it = stringvec.begin(); it != stringvec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    delete q1;

    return 0;
}