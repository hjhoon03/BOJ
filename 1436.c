#include <stdio.h>

int main() {
    int num = 666;
    int n;
    int count = 0;
    
    scanf("%d", &n);
    
    while(count < n) {
        int copy = num;
        for(; copy > 99; copy /= 10) {
            if(copy % 1000 == 666) {
                count ++;
                break;
            }
        }
        num ++;
    }
    
    printf("%d", num - 1);
}
