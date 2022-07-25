#include <stdio.h>

int main() {
    
    int stick = 64;
    int result = 0;
    
    int made = 0;
    
    int count = 0;
    
    scanf("%d", &result);
    
    while(made != result) {
        
        if(stick > result) {
            stick = stick / 2;
        }
        else if((made + stick) > result) {
            stick = stick / 2;
        }
        else {
            made = made + stick;
            ++ count;
            stick = stick / 2;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
