#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

int *mkarray1(int a, int b, int c) {
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    int *p = arr;
    return p;
}

int *mkarray2(int a, int b, int c) {
    int *arr = malloc(sizeof(int) * 3);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    return arr;
}

void other_function() {
    int x = -1;
    int y = -5;
    int z = -8;
    printf("Other function: %d %d %d\n", x, y, z);
}

int main() {

    int *ptr = mkarray1(10, 20, 30);
    other_function();
    printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
}