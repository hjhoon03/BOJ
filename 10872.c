#include <stdio.h>

int num = 0;
int result = 1;

void factorial() {
    if(num == 0)
        printf("%d", result);
    else {
        result *= num;
        num --;
        factorial();
    }
}

int main() {
    scanf("%d", &num);
    
    factorial();
}
