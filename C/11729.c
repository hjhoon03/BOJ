#include <stdio.h>

void hanoi(int, int, int, int);

int main() {
    int n;
    scanf("%d", &n);

    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        cnt = 2 * cnt + 1;
    }
    printf("%d\n", cnt);

    hanoi(n, 1, 2, 3);

    return 0;
}

void hanoi(int n, int a, int b, int c) {
    if(n == 1)
        printf("%d %d\n", a, c);

    else {
        hanoi(n - 1, a, c, b);
        printf("%d %d\n", a, c);
        hanoi(n - 1, b, a, c);
    }
}