#include <stdio.h>
#include <stdlib.h>
 
#define N 5
 
int descending_cmp(const void *a, const void *b);
int ascending_cmp(const void *a, const void *b);
void print_array(int n, int a[]);
 
int main(void)
{
    int i;
    int A[N] = { 4, -3, 5, 1, 2 };
 
    printf("input array:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(int), descending_cmp);
     
    printf("descending order:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(int), ascending_cmp);
 
    printf("ascending order:\n");
    print_array(N, A);
 
    return 0;
}
 

