#include <stdio.h>

int main() {
    int num01, num02;
    scanf("%d %d", &num01, &num02);
    
    int sangsu_num01 = 0, sangsu_num02 = 0;
    
    while(num01) {
        sangsu_num01 *= 10;
        sangsu_num01 += (num01 % 10);
        num01 /= 10;
    }
    
    while(num02) {
        sangsu_num02 *= 10;
        sangsu_num02 += (num02 % 10);
        num02 /= 10;
    }
    
    if(sangsu_num01 > sangsu_num02)
        printf("%d", sangsu_num01);
    else
        printf("%d", sangsu_num02);
}
