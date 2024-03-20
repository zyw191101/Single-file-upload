/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-20 22:16:39
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-21 00:03:49
 * @FilePath: /Single-file-upload/linkList.c
 * @Description: 单链表常用操作
 *
 */
#define DATATYPE int
#include <stdio.h>
#include <stdlib.h>
typedef struct SIGNODE
{
    DATATYPE data;
    struct SIGNODE *next;
} SIGNODE;
// 创建头节点
SIGNODE *createNode(DATATYPE data)
{
    SIGNODE *newNode = (SIGNODE *)malloc(sizeof(SIGNODE));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 在链表头部插入头节点
void insertHead(SIGNODE **head, DATATYPE newData)
{
    SIGNODE *newNode = createNode(newData); // 开辟空间,数据域赋值
    newNode->next = NULL;                   // 指针域置空
    *head = newNode;                        // 头节点移动
}

// 在链表尾部插入头节点
void insertTail(SIGNODE **head, DATATYPE newData)
{
    SIGNODE *newNode = createNode(newData); // 开辟空间,数据域赋值
    if (*head == NULL)
    {
        *head = newNode; // 头节点为空，新节点就是头节点
    }
    SIGNODE *last = *head;
    while (last->next != NULL)
    {
        last = last->next; // 找到尾部
    }
    last->next = newNode; // 插入
}

// 删除节点
void delete_node(SIGNODE **head, DATATYPE key)
{
    SIGNODE *temp = head, *prev = NULL;
    if ((temp != NULL) && (temp->data == key))
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while ((temp != NULL) && (temp->data != key))
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return; // 遍历完数组没有找到对应的值，退出
    }
    prev->next = temp->next;
    free(temp);
}

// 打印链表
void printList(SIGNODE *node)
{
    while (node != NULL) // 如果判断指针域，最后一个节点将不会被打印
    {
        node = node->next;
        // printf("",node->data);
    }
    printf("打印单链表结束\n");
}

// 合并两个递增链表，并按照原本顺序排列（升序）
/* 因为要合并的链表是有序的，合并完后的也是有序的，所以实现起来相对简单 */
int mergeSortedLists(SIGNODE *linkLISTA, SIGNODE *linkLISTB)
{

    SIGNODE dummy;             // 创建一个哑节点作为新链表头部的前驱节点。
    SIGNODE *current = &dummy; // current 指针用于跟踪新链表的最后一个节点。
    SIGNODE *lastCompare=NULL; //相等的情况，不改变排序的前后关系
    while (linkLISTA != NULL && linkLISTB != NULL)
    {
        if ((*linkLISTA) < (*linkLISTB)||((*linkLISTA) == (*linkLISTB)&&lastCompare=linkLISTB))
        {
            current->next = linkLISTA;
            lastCompare=linkLISTA;
            linkLISTA = linkLISTA->next
        }
        else if ((*linkLISTB) < (*linkLISTA))
        {
            current = linkLISTB;
            lastCompare=linkLISTB;
            linkLISTB = linkLISTB->next
        }
        else
        { // 如果相等怎么办
        }
        current = current->next;
    }
    // 剩余节点添加到新链表
    if (linkLISTA!=NULL)
    {
        current->next=linkLISTA;
    }else
    {
        current->next=linkLISTB;
    }
    //返回合并后的链表头节点，及哑节点的next
    return dummy.next;
}
int main(int argc, char const *argv[])
{
    SIGNODE *head = NULL; // 创建一个指针
    insertHead(&head, 1); // 地址传递
    insertHead(&head, 2);
    insertHead(&head, 3);

    // 释放链表
    while (head != NULL)
    {
        SIGNODE *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* readme
合并两个已排序链表的函数的时间复杂度是基于合并过程中元素的比较操作数来计算的。具体来说，这里的时间复杂度是O(n)，因为在最坏情况下，我们需要遍历并比较两个链表的所有元素一次。
假设两个链表的节点总数分别为m和n。在合并过程中，我们从两个列表的头部开始，比较它们当前节点的值，将较小值的节点添加到新链表中，并移动该节点所在链表的指针到下一个节点。随着合并的进行，我们会一次性通过每个节点，直到到达两个链表的末尾。因此，总共的比较次数不会超过两个链表的总节点数。
总结来说：
我们只遍历每个链表一次。
每步操作都只涉及常量时间的比较和节点指针的更新。
因此，合并函数的时间复杂度是两个链表长度之和，即O(m+n)。这里m和n分别表示两个链表的长度。通常情况下，如果两个链表长度相似，我们可以简化成O(n)。

##哑节点
在合并有序链表的上下文中，我们通常是用哑节点来作为头结点的前驱，这样使得链表元素的合并逻辑都是统一的，不需要单独考虑第一个节点的情况。而且在最终返回结果时，我们返回哑节点的下一个节点即可，不需要返回哑节点本身




 */