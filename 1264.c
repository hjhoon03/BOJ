#include <stdio.h>

int main() {
    char i = '-';
    int count = 0;
    
    while(1) {
        
        scanf("%c", &i);

        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            ++ count;
        }
        else if(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
            ++ count;
        }
        else if(i == '\n') {
            printf("%d\n", count);
            count = 0;
        }
        else if(i == '#') {
            break;
        }
    }
    
    return 0;
}
