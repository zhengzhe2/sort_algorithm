#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define ARRAY_LENGTH 10


void print_array(int* array, int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void test_bubble_sort()
{
    printf("test bubble sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("bubble_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    bubble_sort(array, ARRAY_LENGTH);
    printf("bubble_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test bubble sort end ...\n");
}

void test_selection_sort()
{
    printf("test selection sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("selection_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    selection_sort(array, ARRAY_LENGTH);
    printf("selection_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test selection sort end ...\n");    
}

void test_insertion_sort()
{
    printf("test insertion sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("insertion_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    insertion_sort(array, ARRAY_LENGTH);
    printf("insertion_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test insertion sort end ...\n");    
}

int main()
{   
    test_bubble_sort();
    test_selection_sort();
    test_insertion_sort();
    return 0;
}