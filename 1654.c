#include <stdio.h>

int main() {
    int k, n;
    int arr[10001] = {0};
    
    scanf("%d %d", &k, &n);
    
    long long int sum = n + 1;
    
    for(int i = 0; i < k; i ++)
        scanf("%d", &arr[i]);
    
    int i;
    
    for(i = 1; sum >= n; i ++) {
        sum = 0;
        for(int j = 0; j < k; j ++) {
            if(!(arr[j] / i))
                arr[j] = 0;
            
            if(arr[j])
                sum += (long long int)(arr[j] / i);
        }
    }
    
    printf("%d", i - 2);
}
