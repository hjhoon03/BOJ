#include <stdio.h>
int arr[100000] = {0};

void q_sort(int start, int end) {
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while(1) {
        while((i < end) && (arr[i] < pivot)) i ++;
        while((j > start) && (arr[j] > pivot)) j --;

        if(i >= j) break;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    arr[start] = arr[j];
    arr[j] = pivot;

    if(j + 1 < end) q_sort(j + 1, end);
    if(start < j - 1) q_sort(start, j - 1);
}

int main() {
    int n, m;
    int check;

    scanf("%d", &n);

    // 입력
    for(int i = 0; i < n; i ++) {
        scanf("%d", &arr[i]);
    }
    // 정렬
    q_sort(0, n);

    // 탐색
    scanf("%d", &m);

    for(int i = 0; i < m; i ++) {
        scanf("%d", &check);

        int flag = 1;
        int high = n;
        int low = 0;
        int middle = (high + low) / 2;

        while(check != arr[middle]) {
            if(high == low || high < low) {
                printf("%d\n", 0);
                flag = 0;
                break;
            }
            else if(arr[middle] < check)
                low = middle + 1;
            else if(arr[middle] > check)
                high = middle - 1;

            middle = (high + low) / 2;
        }
        if(flag)
            printf("%d\n", 1);
    }
}
