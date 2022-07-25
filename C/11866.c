#include <stdio.h>

int main() {
    int n, k;
    int arr[1000] = {0};
    int num = 0;
    
    scanf("%d %d", &n, &k);
    
    if(n == 1) {
        printf("<1>");
        
        return 0;
    }
    
    int tmp = k - 1;
    
    for(int i = 1; i <= n; i ++) arr[i] = i;
    
    printf("<");
    
    while(arr[2]) {
        if(num)
            printf("%d, ", num);
        
        num = arr[k];
        arr[k] = 0;
        
        for(int i = k; i < n; i ++) {
            arr[i] = arr[i + 1];
        }
        
        arr[n] = 0;
        n --;
        
        k += tmp;
        if(k > n) {
            k %= n;
            if(k == 0) k = n;
        }
    }
    
    printf("%d, ", num);
    
    printf("%d>", arr[1]);
}
