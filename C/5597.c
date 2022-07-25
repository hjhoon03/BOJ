#include <stdio.h>

int main() {
    int arr[30] = {0};

    for(int i = 0; i < 28; ++i) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp - 1] = 1;
    }

    for(int i = 0; i < 30; ++i) {
        if(!arr[i]) printf("%d\n", i + 1);
    }

    return 0;
}