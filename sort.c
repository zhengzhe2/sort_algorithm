#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insertion_sort(int* array, int length)
{
    int preIndex = 0;
    int current = 0;
    for (int i = 1; i < length; ++i) {
        preIndex = i - 1;
        current = *(array + i);
        while (preIndex >= 0 && *(array + preIndex) > current) {
            *(array + preIndex + 1) = *(array + preIndex);
            preIndex--;    
        }
        *(array + preIndex + 1) = current;
    }
}

void shell_sort(int* array, int length)
{
    int gap = 0;
    for (gap = length / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < length; ++i) {
            int j = i;
            int current = *(array + i);
            while (j - gap >= 0 && *(array + j - gap) > current) {
                 *(array + j) = *(array + j - gap);
                 j = j - gap;
            }
            *(array + j) = current;
        }
    }    
}

void merge(int* array, int left, int right, int mid)
{
    int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
    if (temp == NULL) {
        return;
    }
    memset(temp, 0, sizeof(int) * (right - left + 1));
    
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= right) {
        if (*(array + i) <= *(array + j)) {
            *(temp + k++) = *(array + i++);
        } else {
            *(temp + k++) = *(array + j++);
        }
    }

    while (i <= mid) {
        *(temp + k++) = *(array + i++);
    }

    while (j <= right) {
        *(temp + k++) = *(array + j++);
    }

    for (i = 0; i < k; i++) {
		*(array + left + i) = *(temp + i);
	}

	free(temp);
    temp = NULL;
}

void merge_sort(int* array, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, right, mid);
    }
}