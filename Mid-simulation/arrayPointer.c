#include <stdio.h>
#include <stdlib.h>
 
int func1(int n)
{
    printf("func1: %d\n", n);
    return n;
}
 
int func2(int n)
{
    printf("func2: %d\n", n);
    return n;
}
 
int main()
{
    int (*a[2])(int);//定义了保存了两个函数指针的数组
    a[0] = func1;
    a[1] = func2;
    a[0](1);
    a[1](2);
 
    return 0;
}