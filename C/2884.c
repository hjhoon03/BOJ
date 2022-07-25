#include <stdio.h>

int main() {
    int hour = 0, minute = 0;
    
    scanf("%d %d", &hour, &minute);
    
    minute -= 45;
    
    if(minute < 0) {
        minute += 60;
        hour -= 1;
        
        if(hour < 0)
            hour += 24;
    }
    
    printf("%d %d", hour, minute);
    
    return 0;
}
