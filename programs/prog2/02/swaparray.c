#include <stdio.h>
 
void swaparray(int n, int *p, int *q);
 
int main(void)
{
    int i;
    int a[5] = { 0, 1, 2, 3, 4 };
    int b[5] = { 5, 6, 7, 8, 9 };
 
    printf("a[] b[]\n");
    for (i = 0; i < 5; i++) {
        printf("%3d %3d\n", a[i], b[i]);
    }
    putchar('\n');
 
    swaparray(5, a, b);
 
    printf("a[] b[]\n");
    for (i = 0; i < 5; i++) {
        printf("%3d %3d\n", a[i], b[i]);
    }
 
    return 0;
}
 
void swaparray(int n, int *p, int *q)
{
  int c;
  int i;
  
  for(i=0; i<5; i++){
    c=*(p+i);
    *(p+i)=*(q+i);
    *(q+i)=c;
  }
}
