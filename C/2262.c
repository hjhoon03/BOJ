#include <stdio.h>
#include <stdlib.h>

int rank[257] = {0};

// 1 6 2 5 3

void fail(int index) {

    for(int i = index; rank[i]; i ++) {
        rank[i] = rank[i + 1];
    }
}

int battle(int n) {
    int max_num = 0;
    int max_index = 0;
    int min = n;

    for(int i = 0; rank[i]; i ++) {
        if(max_num < rank[i]) {
            max_num = rank[i];
            max_index = i;
        }
    }

    if(abs(rank[max_index] - rank[max_index + 1]) > abs(rank[max_index] - rank[max_index - 1])) {
        min = abs(rank[max_index] - rank[max_index - 1]);
        if(rank[max_index] < rank[max_index - 1]) max_index --;
    }
    else {
        min = abs(rank[max_index] - rank[max_index + 1]);
        if(rank[max_index] < rank[max_index + 1]) max_index ++;
    }

    fail(max_index);
    return min;
}

int main() {
    int n;
    int result = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        scanf("%d", &rank[i]);
    }

    for(int i = 0; i < n - 1; i ++) {
        result += battle(n);
    }

    printf("%d", result);
}