#include <stdio.h>

int main() {
    int time = 0;
    int left_bridge = 0;
    int right_bridge = 0;
    int minus = 0;
    
    int result = 0;
    
    scanf("%d", &time);
    
    while(time) {
        scanf("%d %d", &left_bridge, &right_bridge);
        
        minus = right_bridge - left_bridge;
        
        while(minus)
        -- time;
    }
    
    return 0;
}
