#include <stdio.h>

int main() {
    int n;
    int arr[10001] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        int num;
        
        scanf("%d", &num);
        
        arr[num] ++;
    }
    
    for(int i = 0; i < 10001; i ++) {
        for(int j = 0; j < arr[i]; j ++) {
            printf("%d\n", i);
        }
    }
}
