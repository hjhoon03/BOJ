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
    int n, num, count = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d", &num);
        if(sosoo(num))
            count ++;
    }
    
    printf("%d", count);
    
    return 0;
}
