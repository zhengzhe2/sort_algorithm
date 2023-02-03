# sort_algorithm  
### 运行步骤：  
1.克隆仓库到本地:   
git clone git@github.com:zhengzhe2/sort_algorithm.git   
2.在sort_algorithm目录下创建build目录:    
mkdir build    
3.切换到build目录下:  
cd build      
4.执行cmake:    
cmake .. 
5.执行make:  
make    
6.运行可执行程序:  
./sort  

### 冒泡排序（Bubble Sort）  
冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。     
  
算法描述  
1.比较相邻的元素。如果第一个比第二个大，就交换它们两个；  
2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；  
3.针对所有的元素重复以上的步骤，除了最后一个；  
4.重复步骤1~3，直到排序完成。  
  
```    
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
```  
  
### 选择排序（Selection Sort）  
选择排序(Selection-sort)是一种简单直观的排序算法。它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。   
  
算法描述  
n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。具体算法描述如下：  
  
1.初始状态：无序区为R[1..n]，有序区为空；  
2.第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；  
3.n-1趟结束，数组有序化了。
     
```  
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
```  
   
### 插入排序（Insertion Sort）  
插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。  
   
算法描述  
一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：  
  
1.从第一个元素开始，该元素可以认为已经被排序；  
2.取出下一个元素，在已经排序的元素序列中从后向前扫描；  
3.如果该元素（已排序）大于新元素，将该元素移到下一位置；  
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；  
5.将新元素插入到该位置后；  
6.重复步骤2~5。  
   
```  
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
```  
   
### 希尔排序（Shell Sort）  
1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。  
  
算法描述  
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：  
  
1.选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；  
2.按增量序列个数k，对序列进行k 趟排序；  
3.每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。  
  
```  
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
```   