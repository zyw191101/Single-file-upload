/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-09 09:07:55
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-09 10:03:52
 * @FilePath: /undefined/home/zyw/temp/replace.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<string.h> 

//在字符串中删除字符
int sigleReplace(char *dest,const char *src)
{
    printf("单字符替换：未处理的字符串：%s\n",dest);
    int bits[256]={0};//声明位图，开辟空间
    int lenDest=strlen(dest);
    int lenSrc=strlen(src);
    //构建位图
    for (int i = 0; i < lenSrc; i++)
    {
        bits[src[i]]=1;
    }
    int index=0;
    for (int i = 0; i < lenDest; i++)
    {
        if (!bits[dest[i]])
        {
            dest[index++]=dest[i];
        }
        
    }
    dest[index]='\0';
    printf("单字符替换处理后的字符串：%s\n",dest);
    return 0;
}

//字符串删除
int strReplace(char *dest,const char *sub)
{
    int len=strlen(sub);//子字符串的长度
    char *writePtr=dest;
    if(len>0){
    for (char *readPtr=dest;(*readPtr)!='\0';)
    {
        int offset=0;
        //找到子字符串在字符串中的前后指针
        while (*(readPtr+offset)==*(sub+offset))
        {
            offset++;
            //设置偏移量(子字符串的长度),设置读指针的位置
            if(*(sub+offset)=='\0')
            {
                readPtr+=len;
                break;
            }
        }
        if(*(sub+offset)!='\0')
        {
            //读写指针同步移动,赋值
            *(writePtr++)=*(readPtr++);
        }
    }
    }
    //添加字符串终止符
    *writePtr='\0';
    return 0;
}

int main(int argc, char const *argv[])
{
    // char *dest="hqyjjnfvx";
    // char *sigle="jx";
    // char *mul="jn";
    /*上面这种写法不对，全是字符串常量不可修改*/
    //----------------------------------------------------
    char dest[32]="hqyjjnfvx";
    char sigle[32]="vx";
    char mul[32]="jn";
    // sigleReplace(dest,sigle);
    strReplace(dest,mul);
    printf("%s\n",dest);
    return 0;
}
/*
 * @Author: zyw zhangyuanwei1130@163.com
 * @Date: 2024-03-09 09:07:55
 * @LastEditors: zyw zhangyuanwei1130@163.com
 * @LastEditTime: 2024-03-11 20:00:10
 * @FilePath: /undefined/home/zyw/temp/replace.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>

// 在字符串中删除字符
int sigleReplace(char *dest, const char *src)
{
    printf("单字符替换：未处理的字符串：%s\n", dest);
    int bits[256] = {0}; // 声明位图，开辟空间
    int lenDest = strlen(dest);
    int lenSrc = strlen(src);
    // 构建位图
    for (int i = 0; i < lenSrc; i++)
    {
        bits[src[i]] = 1;
    }
    int index = 0;
    for (int i = 0; i < lenDest; i++)
    {
        if (!bits[dest[i]])
        {
            dest[index++] = dest[i];
        }
    }
    dest[index] = '\0';
    printf("单字符替换处理后的字符串：%s\n", dest);
    return 0;
}

// 字符串删除
int strReplace(char *dest, const char *sub)
{
    int len = strlen(sub); // 子字符串的长度
    char *writePtr = dest;
    if (len > 0)
    {
        for (char *readPtr = dest; (*readPtr) != '\0';)
        {
            int offset = 0;
            // 找到子字符串在字符串中的前后指针
            while (*(readPtr + offset) == *(sub + offset))
            {
                offset++;
                // 设置偏移量(子字符串的长度),设置读指针的位置
                if (*(sub + offset) == '\0')
                {
                    readPtr += len;
                    break;
                }
            }
            if (*(sub + offset) != '\0')
            {
                // 读写指针同步移动,赋值
                *(writePtr++) = *(readPtr++);
            }
        }
    }
    // 添加字符串终止符
    *writePtr = '\0';
    return 0;
}

//str+memmove删除删除字符串
int strFuncReplace(char *dest, const char *sub)
{
    while (dest = strstr(dest, sub))
    {
        memmove(dest, dest + strlen(sub), 1 + (dest + strlen(sub)));
    }
}

int main(int argc, char const *argv[])
{
    // char *dest="hqyjjnfvx";
    // char *sigle="jx";
    // char *mul="jn";
    /*上面这种写法不对，全是字符串常量不可修改*/
    //----------------------------------------------------
    char dest[32] = "hqyjjnfvx";
    char sigle[32] = "vx";
    char mul[32] = "jn";
    // sigleReplace(dest,sigle);
    strReplace(dest, mul);
    printf("%s\n", dest);
    return 0;
}
