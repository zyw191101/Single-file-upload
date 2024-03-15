/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-15 08:27:19
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-15 09:02:31
 * @FilePath: /Single-file-upload/reverseLinkList.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include<stdio.h>
struct Node
{
    int data;
    struct node *next;
};
struct Node* reverseLinkList(struct Node *head)
{
    struct Node * prev=head;
    struct Node * headp=head;
    struct Node * temp=NULL;
    while (headp!=NULL)
    {
        temp=headp->next;//移动
        headp->next=prev;//后指向前
        prev=headp;//前前进到当前
        headp=temp;//当前移动到后部
    }
           
}

struct Node * stdReverseLinkList(struct Node* head)
{
    struct Node* prev = NULL;  // 用于跟踪当前节点的前一个节点
    struct Node* current = head;  // 当前节点从头节点开始
    struct Node* next = NULL;  // 用于临时存储下一个节点

    while (current != NULL) {  // 遍历链表直至当前节点为空
        next = current->next;  // 提前保存下一个节点
        current->next = prev;  // 将当前节点的next指向前一个节点，实现反转
        prev = current;  // 前一个节点前进到当前节点
        current = next;  // 当前节点前进到下一个节点
    }
    head = prev;  // 最后，prev将是新的头节点

    return head;  // 返回新的头节点
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
