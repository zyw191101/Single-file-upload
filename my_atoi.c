/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-04-03 09:20:11
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-04-03 09:28:22
 * @FilePath: /undefined/home/zyw/temp/my_atoi.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
int my_atoi(const char *str)
{
    int sign=1;//符号位
    int index=0;//索引
    int res=0;//最后的结果
    //跳过空格
    while(str[index]==' ')
    {
        index++;
    }
    //检查符号位
    if(str[index]=='-'||str[index]=='+')
    {
        sign=(str[index]=='-')?-1:1;
        index++;
    }
    //遍历处理过的字符串，转换
    while(str[index]>='0'&& str[index]<='9')
    {
        res=res*10+str[index]-'0';
        index++;
    }
    return res*sign;
}

typedef struct SLIST {
    // ... (可能包含其他成员变量)
    struct SLIST *next;
} SLIST_S;

int list_revert(SLIST_S *listA,SLIST_S **listB)
{
    
    SLIST_S *prev=NULL;
    SLIST_S *current=listA;
    SLIST_S *next=NULL;
    while (current!=NULL)
    {
        next=current->next;//保存下一个节点
        current->next=prev;//翻转
        prev=current;//上一个节点向前移动
        current=next;//移动到下一个节点
    }
    *listB=prev;
    return 0;

}



