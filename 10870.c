#include <stdio.h>

int num01 = 0;
int num02 = 1;
int result = 0;

int count = 2;
int input = 0;

void fibonacci() {
    result = num01 + num02;
    num01 = num02;
    num02 = result;
    
    if(count == input)
        printf("%d", result);
    else {
        count += 1;
        fibonacci();
    }
        
}

int main() {
    scanf("%d", &input);
    
    if(input == 0) {
        printf("%d", 0);
        return 0;
    }
    else if(input == 1) {
        printf("%d", 1);
        return 0;
    }
    
    fibonacci();
}
