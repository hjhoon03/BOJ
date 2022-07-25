#include <stdio.h>

int main() {
    int n, k, result = 1;
    
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < k; i ++) {
        result *= n;
        n --;
    }
    
    for(; k; k --)
        result /= k;
    
    printf("%d", result);
}
