#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, num, index;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);

    scanf("%d", &num);

    for(int i = 0; i < n; i ++)
        if(arr[i] > num) {
            index = i;
            break;
        }

    printf("%d", (num - arr[index - 1]) * (arr[index] - num) - 1);
}