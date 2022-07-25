#include <stdio.h>

int gongyak(int num01, int num02) {
    int gong;
    int min;
    if(num01 > num02)
        min = num02;
    else
        min = num01;
    
    for(int i = 1; i <= min; i ++) {
        if(num01 % i == 0)
            if(num02 % i == 0)
                gong = i;
    }
    
    return gong;
}

int main() {
    int num01, num02;
    
    scanf("%d %d", &num01, &num02);
    
    int gong = gongyak(num01, num02);
    
    printf("%d\n", gong);
    printf("%d", gong * (num01 / gong) * (num02 / gong));
}
