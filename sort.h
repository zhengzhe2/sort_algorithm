#ifndef SORT_H
#define SORT_H

// 冒泡排序（Bubble Sort）
// 冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 

// 算法描述
// 1.比较相邻的元素。如果第一个比第二个大，就交换它们两个；
// 2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
// 3.针对所有的元素重复以上的步骤，除了最后一个；
// 4.重复步骤1~3，直到排序完成。

void bubble_sort(int* array, int length);


// 选择排序（Selection Sort）
// 选择排序(Selection-sort)是一种简单直观的排序算法。它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 

// 算法描述
// n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。具体算法描述如下：

// 1.初始状态：无序区为R[1..n]，有序区为空；
// 2.第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
// 3.n-1趟结束，数组有序化了。

void selection_sort(int* array, int length); 

#endif