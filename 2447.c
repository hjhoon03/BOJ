#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char star[2188][2188] = {"***", "* *", "***"};
char copy[2188][2188];

int power_down(int num) {
    int count = 0;
    
    for(; num != 1; num /= 3)
        count ++;
    
    return count;
}

int main () {
    int N;
    int comp;
    
    scanf("%d", &N);
    
    comp = power_down(N) - 1;
    
    for(int i = N; i; i --) {
        
    }
    
    for(int i = 0; i <= N; i ++) {
        printf("%s", star[i]);
    }
}
