#include "sort.h"


void bubble_sort(int* array, int length)
{
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - 1 - i; ++j) {
            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j + 1);
                *(array + j + 1) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
}

void selection_sort(int* array, int length)
{
    int minIndex = 0;
    for (int i = 0; i < length - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (*(array + j) < *(array + minIndex)) {
                minIndex = j;
            }
        }
        int temp = *(array + i);
        *(array + i) = *(array + minIndex);
        *(array + minIndex) = temp;    
    }
}