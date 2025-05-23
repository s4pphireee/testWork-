#include "functions.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

#define BUFFER 256

int32_t extractKey(char *line) {
    char *lastSpace = std::strrchr(line, ' ');
    if (lastSpace != 0) {
        return std::atoi(lastSpace + 1);
    }
    return 0;
}

void readInput(int32_t n, char **lines, int32_t *keys, int32_t *order, int32_t &sum, int32_t &minKey, int32_t &maxKey) {
    char buffer[BUFFER];
    bool first = true;
    for (size_t i = 0; i < n; i++) {
        std::cin.getline(buffer, BUFFER);
        
        size_t len = std::strlen(buffer);
        lines[i] = new char[len + 1];
        std::strcpy(lines[i], buffer);
        
        keys[i] = extractKey(buffer);
        
        order[i] = i;
        
        sum += keys[i];
        
        if (first) {
            minKey = keys[i];
            maxKey = keys[i];
            first = false;
        } 
        else {
            if (keys[i] < minKey)
                minKey = keys[i];

            if (keys[i] > maxKey)
                maxKey = keys[i];
        }
    }
}

void swapElements(int32_t *keys, char **lines, int32_t *order, size_t i, size_t j) {
    int32_t tempKey = keys[i];
    keys[i] = keys[j];
    keys[j] = tempKey;
    
    char *tempLine = lines[i];
    lines[i] = lines[j];
    lines[j] = tempLine;
    
    int32_t tempOrder = order[i];
    order[i] = order[j];
    order[j] = tempOrder;
}

int32_t partition(int32_t *keys, char **lines, int32_t *order, int32_t low, int32_t high) {
    int32_t pivotKey = keys[high];
    int32_t pivotOrder = order[high];
    int32_t i = low - 1;
    for (size_t j = low; j < high; j++) {
        if (keys[j] < pivotKey || (keys[j] == pivotKey && order[j] < pivotOrder)) {
            i++;
            swapElements(keys, lines, order, i, j);
        }
    }

    swapElements(keys, lines, order, i + 1, high);
    return i + 1;
}

void quickSort(int32_t *keys, char **lines, int32_t *order, int32_t low, int32_t high) {
    if (low < high) {
        int32_t pi = partition(keys, lines, order, low, high);

        quickSort(keys, lines, order, low, pi - 1);
        quickSort(keys, lines, order, pi + 1, high);
    }
}

void printLines(int32_t n, char **lines) {
    for (size_t i = 0; i < n; i++) {
        std::cout << lines[i] << std::endl;
    }
}

void printAggregates(int32_t sum, int32_t minKey, int32_t maxKey) {
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Min: " << minKey << std::endl;
    std::cout << "Max: " << maxKey << std::endl;
}