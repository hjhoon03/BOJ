#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[10] = {0};
    int cnt = 0;

    while(n) {
        arr[cnt] = n % 10;
        n /= 10;
        ++cnt;
    }

    for(int i = 0; i < cnt - 1; ++i) {
        int max_idx = i;
        for(int j = i + 1; j < cnt; ++j) {
            if(arr[max_idx] < arr[j])
                max_idx = j;
        }
        if (max_idx != i) {
            int tmp = arr[max_idx];
            arr[max_idx] = arr[i];
            arr[i] = tmp;
        }
    }

    for(int i = 0; i < cnt; ++i) {
        printf("%d", arr[i]);
    }

    return 0;
}