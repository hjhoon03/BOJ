#include <stdio.h>

int main() {
    int t;
    int h, w;
    int n;
    int num01, num02;
    
    scanf("%d", &t);
    
    for(int i = 0; i < t; i ++) {
        scanf("%d %d %d", &h, &w, &n);
        if(n % h == 0) {
            num01 = h;
            num02 = n / h;
        }
        else {
            num01 = n % h;
            num02 = (n / h) + 1;
        }
        printf("%d%02d\n", num01, num02);
    }
    
    return 0;
}
