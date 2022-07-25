#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int m;
    scanf("%d", &m);

    int cnt = 0;

    for(int i = 0; i < n; ++i)
        if(arr[i] == m) ++cnt;

    printf("%d", cnt);

    free(arr);

    return 0;
}