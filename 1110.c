#include <stdio.h>

int main() {
    int input_num = 0;
    int new_num = 0;
    
    int count = 0;
    
    int num01 = 0;
    int num02 = 0;
    
    scanf("%d", &input_num);
    
    num01 = input_num;
    
    if(!input_num) {
        count = 1;
    }
    
    while(input_num != new_num) {
        num02 = (num01 / 10) + (num01 % 10);
        new_num = ((num01 % 10) * 10) + (num02 % 10);
        num01 = new_num;
        ++ count;
    }
    
    printf("%d", count);
    
    return 0;
}
