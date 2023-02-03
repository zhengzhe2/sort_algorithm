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

void test_shell_sort()
{
    printf("test shell sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("shell_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    shell_sort(array, ARRAY_LENGTH);
    printf("shell_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test shell sort end ...\n");    
}

void test_merge_sort()
{
    printf("test merge sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("merge_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    merge_sort(array, ARRAY_LENGTH);
    printf("merge_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test merge sort end ...\n");    
}

void test_quick_sort()
{
    printf("test quick sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("quick_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    quick_sort(array, ARRAY_LENGTH);
    printf("quick_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test quick sort end ...\n");    
}

void test_heap_sort()
{
    printf("test heap sort start ...\n");
    int array[ARRAY_LENGTH] = { 5, 3, 0, 7, 9, 8, 2, 4, 6, 1};
    printf("heap_sort before array: ");
    print_array(array, ARRAY_LENGTH);
    heap_sort(array, ARRAY_LENGTH);
    printf("heap_sort after array: ");
    print_array(array, ARRAY_LENGTH);
    printf("test heap sort end ...\n");    
}

int main()
{   
    printf("#################################################\n");
    test_bubble_sort();
    printf("#################################################\n");
    test_selection_sort();
    printf("#################################################\n");
    test_insertion_sort();
    printf("#################################################\n");
    test_shell_sort();
    printf("#################################################\n");
    test_merge_sort();
    printf("#################################################\n");
    test_quick_sort();
    printf("#################################################\n");
    test_heap_sort();
    printf("#################################################\n");
    return 0;
}