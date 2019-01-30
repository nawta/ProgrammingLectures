#include <stdio.h>
 
void add(int x, int y, int *z); /* 3 つ目の引数にポインタ */
 
int main(void)
{
    int a = 15, b = 25, c;
 
    add(a, b, &c);
 
    printf("add(%d, %d) in main() = %d\n", a, b, c);
 
    return 0;
}
 
void add(int x, int y, int *z)  /* 3 つ目の引数にポインタ */
{
    *z = x + y;
    printf("add(%d, %d) in add()  = %d\n", x, y, *z);
}
