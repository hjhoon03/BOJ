#include <stdio.h>
#include <math.h>

int main() {
    int arr[1000001] = {0};
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    for(int i = m; i <= n; i ++)
        arr[i] = 1;
    
    for(int i = 2; (double)
        i <= sqrt(n) && i <= 1000; i ++)
        for(int j = 2; i * j <= n; j ++)
            arr[i * j] = 0;
    
    for(int i = 2; i <= n; i ++)
        if(arr[i])
            printf("%d\n", i);
}
