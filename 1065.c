#include <stdio.h>

int hansoo(int number) {
    int d = 0;
    
    d = ((number / 10) % 10) - (number % 10);
    
    while(100 <= number) {
        number /= 10;
        if(d != ((number / 10) % 10) - (number % 10))
            return 0;
    }
    
    return 1;
}

int main() {
    int number = 0;
    int count = 0;
    
    scanf("%d", &number);
    
    for(; number; number --) {
        if(hansoo(number))
            count ++;
    }
    
    printf("%d", count);
    
    return 0;
}
