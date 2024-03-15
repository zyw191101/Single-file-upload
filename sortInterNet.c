/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-13 15:24:11
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-15 19:52:01
 * @FilePath: /Single-file-upload/sortInterNet.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>
int sortBubble(char *a, int num);
int sortChose(char *a, int num);

void swap(char *a, char *b);
int FindSecMax(int Data[], int Count); //找出整数数组中第二小的整数
int main(int argc, char const *argv[])
{
    char a[10] = "145326978"; // 数字的ASCII字符形式是eof
    // sortBubble(a, 9);
    // sortChose(a, 9);
    // temp();
    return 0;
}

// 冒泡排序
int sortBubble(char *a, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
            }
        }
    }
    printf("%s\n", a);
    return 0;
}
// 选择排序
int sortChose(char *a, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < num; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            a[i] ^= a[min];
            a[min] ^= a[i];
            a[i] ^= a[min];
        }
    }
    printf("%s\n", a);
}
//-----------------------------------------------------------------------------
// 快速排序主函数
int sortQuick(char *a, int num)
{
}
// 快速排序划分成两部分

// 数据交换
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
//------------------------------------------------------------------------

int FindSecMax(int Data[], int Count) {
    int max = Data[0]; // 假设第一个元素为最大值
    int secMax = 0; // 初始化第二大值为最小整数

    for (int i = 1; i < Count; i++) {
        if (Data[i] > max) {
            secMax = max; // 将当前的最大值更新为第二大值
            max = Data[i]; // 更新最大值
        } else if (Data[i] > secMax && Data[i] < max) {
            secMax = Data[i]; // 更新第二大值
        }
    }

    return secMax;
}