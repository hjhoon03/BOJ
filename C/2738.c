#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** arr = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(sizeof(int) * m);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);

            arr[i][j] += tmp;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; ++i) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}