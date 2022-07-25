#include <stdio.h>

int main() {
    // 0(1), 1 + 6, 1 + 6 + 6  6n - >  3n^2 - 3n + 1
    int n;
    
    scanf("%d", &n);
    
    if(n == 1) {
        printf("%d", 1);
        return 0;
    }
    
    for(int i = 2; 1; i ++)
        if(3 * (i - 1) * (i - 1) - 3 * i + 1 < n && n <= 3 * i * i - 3 * i + 1) {
            printf("%d", i);
            break;
        }
    
    return 0;
}
