#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

int main() {
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    {
        // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
        std::vector<std::string> coloursSort(colours);
        std::sort(coloursSort.begin(), coloursSort.end());

        std::vector<std::string> coloursSortAToP;
        std::vector<std::string> coloursSortPToZInclusive;
        bool flip = true;
        for (auto it = coloursSort.begin(); it != coloursSort.end(); ++it)
        {
            if ((*it).rfind('p', 0) == 0 || !flip)
            {
                coloursSortPToZInclusive.push_back(*it);
                flip = false;
                continue;
            }
            coloursSortAToP.push_back(*it);
        }
        for (auto it = coloursSortAToP.begin(); it != coloursSortAToP.end(); ++it)
        {
            std::cout << "A till P: " << *it << std::endl;
        }
        for (auto it = coloursSortPToZInclusive.begin(); it != coloursSortPToZInclusive.end(); ++it)
        {
            std::cout << "P till Z inclusive: " << *it << std::endl;
        }
    }
    
    {
        // 2) alle elementen UPPERCASE te maken.
        std::vector<std::string> coloursToUpperCase(colours);
        for (auto it = coloursToUpperCase.begin(); it != coloursToUpperCase.end(); ++it)
        {
            std::transform((*it).begin(), (*it).end(), (*it).begin(), [](char const &c)
            {
                return std::toupper(c);
            });
            std::cout << "To upper: " << *it << std::endl;
        }
    }
    {
        // 3) alle dubbele te verwijderen
        std::vector<std::string> coloursUnique(colours);
        std::sort(coloursUnique.begin(), coloursUnique.end());
        coloursUnique.erase(std::unique(coloursUnique.begin(), coloursUnique.end()), coloursUnique.end());
        for (auto it = coloursUnique.begin(); it != coloursUnique.end(); ++it)
        {
            std::cout << "Unique: " << *it << std::endl;
        }
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    std::vector<double>::iterator pend;
    {
        // 1) alle negatieve elementen te verwijderen
        std::vector<double> numbersAbove0(numbers);
        pend = std::remove_if(
            numbersAbove0.begin(), numbersAbove0.end(),
            [](double d) { return d < 0; });
        for (auto it = numbersAbove0.begin(); it != pend; ++it)
        {
            std::cout << "Real numbers > 0: " << *it << std::endl;
        }
    }

    {
        // 2) voor alle elementen te bepalen of ze even of oneven zijn
        std::vector<double> oddNumbers(numbers);
        std::sort(oddNumbers.begin(), oddNumbers.end());
        pend = std::remove_if(
            oddNumbers.begin(), oddNumbers.end(),
            [](double d) { return static_cast<int>(std::abs(d)) % 2 == 0; });
        for (auto it = oddNumbers.begin(); it != pend; ++it)
        {
            std::cout << "Odd numbers: " << *it << std::endl;
        }
        
        std::vector<double> evenNumbers(numbers);
        std::sort(evenNumbers.begin(), evenNumbers.end());
        pend = std::remove_if(
            evenNumbers.begin(), evenNumbers.end(),
            [](double d) { return static_cast<int>(std::abs(d)) % 2 == 1; });
        for (auto it = evenNumbers.begin(); it != pend; ++it)
        {
            std::cout << "Even numbers: " << *it << std::endl;
        }
        // Neemt de komma getallen wél mee...
    }

    {
        std::vector<double> numbersCopy(numbers);
        double sum = 0.0;
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
        std::for_each(numbersCopy.begin(), numbersCopy.end(),
            [&sum](double d) { sum += d; });
        std::cout << "Sum: " << sum << std::endl;

        double mean = 0.0;
        std::for_each(numbersCopy.begin(), numbersCopy.end(),
            [&mean, numbersCopy] (double d) { mean += d / size(numbersCopy); } );
        std::cout << "Mean: " << mean << std::endl;

        double prod = 1.0;
        std::for_each(numbersCopy.begin(), numbersCopy.end(),
            [&prod](double d) { prod *= d; } );
        std::cout << "Product: " << prod << std::endl;
    }

    return 0;
}