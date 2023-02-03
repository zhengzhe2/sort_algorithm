#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bubble_sort
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

// selection_sort
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

// insertion_sort
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

// shell_sort
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

// merge_sort
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

void _merge_sort(int* array, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        _merge_sort(array, left, mid);
        _merge_sort(array, mid + 1, right);
        merge(array, left, right, mid);
    }
}

void merge_sort(int* array, int length)
{
    _merge_sort(array, 0, length - 1);
}

// quick_sort
int getPivot(int* array, int left, int right)
{
    int k = *(array + left);
    while (left < right) {   
        while (left < right && *(array + right) >= k) {
            right--;
        }
        
        if (left < right) {
            *(array + left) = *(array + right);
        }
        
        while (left < right && *(array + left) <= k) {
            left++;
        }

        if (left < right) {
            *(array + right) = *(array + left);
        }
    }

    *(array + left) = k;
    return left;
}

void _quick_sort(int* array, int left, int right)
{
    if (left < right) {
        int pivot = getPivot(array, left, right);
        _quick_sort(array, left, pivot - 1);
        _quick_sort(array, pivot + 1, right);
    }
}

void quick_sort(int* array, int length)
{
    _quick_sort(array, 0, length - 1);
}

// heap_sort
void swap(int* array, int i, int j)
{
    int temp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = temp;    
}

void adjust_heap(int* array, int length, int k)
{
    if (k < length) {
        int root = k;
        int l_child = 2 * k + 1;
        int r_child = 2 * k + 2;
        
        if (l_child < length && *(array + root) < *(array + l_child)) {
              root = l_child;
        }

        if (r_child < length && *(array + root) < *(array + r_child)) {
              root = r_child;
        }

        if (root != k) {
            swap(array, root, k);
            adjust_heap(array, length, root);
        }
    }
}

void create_heap(int* array, int length)
{
    int last = length - 1;
    int parent = (last - 1) / 2;
    for (int i = parent; i >= 0; --i) {
        adjust_heap(array, length, i);
    }
}

void heap_sort(int* array, int length)
{
    create_heap(array, length);
    for (int i = length - 1; i >= 0; --i) {
        swap(array, i, 0);
        adjust_heap(array, i, 0);
    }
}