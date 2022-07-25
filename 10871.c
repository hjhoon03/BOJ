#include <stdio.h>

int main() {
    int N = 0;
    int X = 0;
    int num;
    
    scanf("%d %d", &N, &X);
    
    while (N--) {
        scanf("%d", &num);
        
        if (num < X)
            printf("%d ", num);
        
    }
}
