#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        char gual[51] = {0};
        scanf("%s", gual);
        int left = 0;
        
        for(int j = 0; gual[j]; j ++) {
            if(gual[j] == '(') left ++;
            else left --;
            
            if(left < 0) {
                printf("NO\n");
                break;
            }
        }
        
        if(left == 0) {
            printf("YES\n");
        }
        else if(left > 0) {
            printf("NO\n");
        }
    }
}
