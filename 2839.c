#include <stdio.h>

#define big 5
#define small 3

int main() {
    int kg = 0;
    int bong[2] = {0, };
    int complete = 0;
    
    scanf("%d", &kg);
    
    bong[0] = kg / big;
    
    for(; bong[0] * big + bong[1] * small <= kg; bong[0] --) {
        bong[1] = 0;
        for(; bong[0] * big + bong[1] * small <= kg; bong[1] ++) {
            if((bong[0] * big + bong[1] * small) == kg) {
                complete = 1;
                break;
            }
        }
        if((bong[0] * big + bong[1] * small) == kg) {
            complete = 1;
            break;
        }
        
        if(bong[0] == 0)
            break;
    }
    if(complete)
        printf("%d", bong[0] + bong[1]);
    else
        printf("%d", -1);
}
