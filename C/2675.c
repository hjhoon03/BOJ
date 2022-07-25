#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, r;
    char s[20];
    
    scanf("%d", &t);
    
    for(; t; t --) {
        scanf("%d", &r);
        scanf("%s", s);
        for(int i = 0; s[i]; i ++) {
            for(int j = r; j; j --)
                printf("%c", s[i]);
        }
        printf("\n");
    }
}
