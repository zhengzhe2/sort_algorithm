# sort_algorithm （C语言版）  
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

### 归并排序（Merge Sort）  
归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。    
  
算法描述  
1.把长度为n的输入序列分成两个长度为n/2的子序列；  
2.对这两个子序列分别采用归并排序；  
3.将两个排序好的子序列合并成一个最终的排序序列。 

``` 
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

``` 

### 快速排序（Quick Sort）     
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。   
     
算法描述     
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：      
    
1.从数列中挑出一个元素，称为 “基准”（pivot）；       
2.重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；      
3.递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。    

``` 
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

``` 

### 堆排序（Heap Sort）  
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。  

算法描述  
1.将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；  
2.将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；  
3.由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。  

``` 
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

``` 