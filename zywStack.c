/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-21 00:11:07
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-21 00:39:37
 * @FilePath: /Single-file-upload/zywStack.c
 * @Description: 创建栈，出栈代码，判断第二个序列是否为可能得出栈序列代码
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义一个栈结构
typedef struct
{
    int *data;//存储栈元素的数组，动态分配，提高复用性
    int top;//栈顶指针，-1表示空栈
    int max_size;//栈的最大容量
}Stack;

//创建栈
Stack *createStack(int max_size)
{
    Stack *s=(Stack *)malloc(sizeof(Stack));//分配栈结构内存
    s->data=(int *)malloc(max_size *sizeof(int));
    s->top=-1;
    s->max_size=max_size;
    return s;
}

// 判断栈是否为空
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
bool isFull(Stack *s) {
    return s->top == s->max_size - 1;
}

//入栈
void push(Stack *s,int item)
{
    if (isFull(s))
    {
        return;
    }
    s->data[++s->top]=item;
    
}

//出栈
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->data[s->top--];
}

//释放栈
void freeStack(Stack *s)
{
    free(s->data);//先释放数据数组内存
    free(s);//释放栈结构内存
}

//检验是否是弹出序列
bool isPopOrder(const int *pushV,const int *popV,int len )
{
    int i=0,j=0;
    bool possible=false;
    //创建栈
    Stack *s=createStack(len);
    while (j<len)
    {
        while (isEmpty(s)||s->data[s->top]!=popV[j])
        {
            if (i==len)//所有元素已入栈，退出循环
            {
                break;
            }
            push(s,pushV[i++]);
        }
        //如果栈顶元素不等于popV当前的元素值，则该顺序不可能
        if (s->data[s->top]!=popV[j])
        {
            break;//跳出本层循环
        }
        pop(s);
        j++;
    }
    
    if (isEmpty(s)&&j==len)
    {
        possible=true;
    }
    freeStack(s);
    return possible;
}