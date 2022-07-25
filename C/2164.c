#include <stdio.h>

int main() {
    int n;
    int arr[500002] = {0};
    int flag = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        arr[i] = i + 1;
    }
    
    while(arr[1]) {
        int j = flag;
        int tmp = arr[n - 1];
        for(int i = flag; arr[i]; i += 2) {
            arr[i] = 0;
            arr[j] = arr[i + 1];
            arr[i + 1] = 0;
            j ++;
        }
        
        n = 0;
        for(int i = 0; arr[i]; i ++) n ++;
        
        if(tmp == arr[n - 1]) flag = 0;
        else flag = 1;
    }
    
    printf("%d", arr[0]);
}
