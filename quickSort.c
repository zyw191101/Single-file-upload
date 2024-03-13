/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-13 15:06:58
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-13 15:22:49
 * @FilePath: /temp/quickSort.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

// 不使用回调函数版本的快排(占空间使用少，递归深度浅)
void swapiterative(int *a, int *b);
void iterativeQuickSort(int arr[], int low, int high);
int partitionIterative(int arr[], int low, int high);

int main()
{
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(data) / sizeof(data[0]);

    printf("原始数组: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", data[i]);
    printf("\n");

    quickSort(data, 0, n - 1);

    printf("排序后的数组: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", data[i]);
    printf("\n");

    // 不使用回调函数版本
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int num = sizeof(arr) / sizeof(*arr);
    iterativeQuickSort(arr, 0, num - 1);
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* 不使用递归函数版本 */
// Utility function to swap two elements
void swapiterative(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partitionIterative(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapiterative(&arr[i], &arr[j]);
        }
    }
    swapiterative(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* A iterative implementation of quicksort */
void iterativeQuickSort(int arr[], int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position in sorted array
        int pivot = partitionIterative(arr, low, high);

        // If there are elements on left side of pivot, then push left side to stack
        if (pivot - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        // If there are elements on right side of pivot, then push right side to stack
        if (pivot + 1 < high)
        {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}