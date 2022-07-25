#include <stdio.h>

long long sum(int *a, int n) {
    int sum = 0;
    
    for(; n; n --) {
        sum += *a;
        a ++;
    }
    
    return sum;
}
