#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <stddef.h>

int32_t extractKey(char *line);
void readInput(int32_t n, char **lines, int32_t *keys, int32_t *order, int32_t &sum, int32_t &minKey, int32_t &maxKey);
void swapElements(int32_t *keys, char **lines, int32_t *order, size_t i, size_t j);
int32_t partition(int32_t *keys, char **lines, int32_t *order, int32_t low, int32_t high);
void quickSort(int32_t *keys, char **lines, int32_t *order, int32_t low, int32_t high);
void printLines(int32_t n, char **lines);
void printAggregates(int32_t sum, int32_t minKey, int32_t maxKey);

#endif
