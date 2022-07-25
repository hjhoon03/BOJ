#include <stdio.h>

int main() {
    int num, result = 0, copy, sum;
    
    scanf("%d", &num);
    
    for(int i = 1; i < num; i ++) {
        copy = i;
        sum = i;
        while(copy) {
            sum += copy % 10;
            copy /= 10;
        }
        if(sum == num) {
            result = i;
            break;
        }
    }
    
    printf("%d", result);
}
