#include <stdio.h>

int main() {
    int count = 0;
    int num = 0;
    int max, min;
    
    scanf("%d", &count);
    scanf("%d", &max);
    min = max;
    
    while(-- count) {
        scanf("%d", &num);
        
        if(num > max)
            max = num;
        else if(min > num)
            min = num;
    }
    
    printf("%d %d", min, max);
    
    return 0;
}
