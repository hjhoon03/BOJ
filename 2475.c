#include <stdio.h>
#include <math.h>

int main() {
    int num = 1, sum = 0;
    
    for(int i = 0; i < 5; i ++) {
        scanf("%d", &num);
        sum += (int)pow(num % 10, 2);
    }
    
    printf("%d", sum % 10);
}
