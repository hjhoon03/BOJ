#include <stdio.h>

int sosoo(int num) {
    if(num == 1)
        return 0;
    
    for(int i = 2; i < num; i ++) {
        if(num % i == 0)
            return 0;
    }
    
    return 1;
}

int main() {
    int start, end, index = 0, num[10000] = {0}, sum = 0;
    
    scanf("%d %d", &start, &end);
    
    for(int i = start; i <= end; i ++) {
        if(sosoo(i)) {
            num[index] = i;
            index ++;
        }
    }
    
    for(int i = 0; num[i]; i ++)
        sum += num[i];
    
    if(num[0])
        printf("%d\n%d", sum, num[0]);
    else
        printf("%d", -1);
    
    return 0;
}
