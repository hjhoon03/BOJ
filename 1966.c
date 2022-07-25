#include <stdio.h>

int main() {
    int n;
    int arr[100] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        int many, to, joong;
        int count = 1;
        
        scanf("%d %d", &many, &to);
        for(int j = 0; j < many; j ++) {
            scanf("%d", &arr[i]);
        }
        
        joong = arr[to];
        
        for(int j = 0; j < many; j ++) {
            if(arr[j] > joong) count ++;
            else if(arr[j] == joong && j < to) count ++;
        }
    }
}
