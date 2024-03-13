#include <stdio.h>
#include <string.h>
int sortBubble(char *a, int num);
int sortChose(char *a, int num);

void swap(char *a, char *b);

int temp()
{
    char string[10], str1[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        str1[i] = 'a';

    }
    strcpy(string, str1);
    printf("%s\n", string);
}
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