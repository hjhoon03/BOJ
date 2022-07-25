#include <stdio.h>

int main() {
    int n, copy, pel;
    
    while(1) {
        scanf("%d", &n);
        
        if(n == 0) break;
        
        copy = n;
        pel = 0;
        
        for(; copy; copy /= 10) {
            pel *= 10;
            pel += copy % 10;
        }
        
        if(n == pel) printf("yes\n");
        else printf("no\n");
    }
}
