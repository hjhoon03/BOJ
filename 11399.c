#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int tmp = 0;
    int result = 0;

    for(int i = 0; i < n; ++i) {
        tmp += arr[i];
        result += tmp;
    }

    printf("%d", result);

    return 0;
}

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 < num2) return -1;
    else if(num1 > num2) return 1;
    else return 0;
}