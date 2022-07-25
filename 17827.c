#include <stdio.h>

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    int snail[200000] = {0};

    for(int i = 0; i < n; ++i) {
        scanf("%d", snail + i);
    }

    int target;

    for(int i = 0; i < m; ++i) {
        scanf("%d", &target);
        if(target > n) {
            int temp = n - v;
            target = (target - temp) % (n - v + 1) + temp;
        }

        printf("%d\n", snail[target]);
    }

    return 0;
}