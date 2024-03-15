#include <stdio.h>
int flowers();

// #define MOD(x, y) x % y
// int temp()
// {
//     int a[5] = {1, 2.3, 4, 5};
//     int *ptr1 = (int *)(&a + 1);
//     int *ptr2 = (int *)((int)a + 1);
//     printf("%x,%x", ptr1[-1], *ptr2);
// }
struct
{
short a; char b; float c;
}cs;
#include <stdio.h>


int main(int argc, char const *argv[])
{
    // flowers();
    // temp();
    // int a = 1;
    // int b = 2;
    // int x = 0;
    // if (!(--a))
    //     x--;
    // if (!b)
    //     x = 7;
    // else
    //     ++x;
    printf("%d\n", sizeof(cs));
    return 0;
}

// int flowers()
// {
//     for (int i = 0; i < 1000; i++)
//     {
//         int h = i / 100;
//         int t = i / 10 % 10;
//         int o = i % 10;
//         if (i == ((h * h * h) + (t * t * t) + (o * o * o)))
//         {
//             printf("%d\n", i);
//         }
//     }
// }