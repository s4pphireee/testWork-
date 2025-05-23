#include <iostream>
#include "functions.h"
#include "functions.cpp"
#include <cstring>
#include <cstdlib>
#include <exception> 

int main() {
    try {
        int32_t n{};
        std::cout << "Enter the number of strings: ";
        std::cin >> n;
        std::cin.ignore();

        char **lines = new char*[n];
        int32_t *keys = new int32_t[n];
        int32_t *order = new int32_t[n];

        int32_t sum{};
        int32_t minKey{};
        int32_t maxKey{};
        

        readInput(n, lines, keys, order, sum, minKey, maxKey);
        quickSort(keys, lines, order, 0, n - 1);  
        std::cout << "\nSorted strings:" << std::endl;
        printLines(n, lines);
        printAggregates(sum, minKey, maxKey);
        
        for (size_t i = 0; i < n; i++) {
            delete[] lines[i];
        }
        delete[] lines;
        delete[] keys;
        delete[] order;
        
        return 0;
    }

    catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
        return 1;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown exception caught." << std::endl;
        return 1;
    }
}
