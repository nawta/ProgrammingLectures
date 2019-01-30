/* swapary2.c */
#include <stdio.h>

#define MAX 5

void swapary2(int n, int *a, int *b);

main()
{
  int i;
  int a[MAX] = {0,1,2,3,4};
  int b[MAX] = {5,6,7,8,9};
  printf("a[] b[]\n");
  for(i=0;i< MAX;i++){
    printf("%3d %3d\n", a[i], b[i]);
  }
  
  swapary2(MAX, a, b);

  printf("a[] b[]\n");
  for(i=0;i<5;i++){
    printf("%3d %3d\n", a[i], b[i]);
  }
}

void swapary2(int n, int *a, int *b){
  int i, tmp;

  for(i=0;i<n;i++){
    tmp = *(a+i);
    
    *(a+i) = *(b+i);
    
    *(b+i) = tmp;
  }
}
