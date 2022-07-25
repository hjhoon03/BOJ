#include <stdio.h>

int main() {
    char dial[10][4] = {{0, }, {0, }, {'A', 'B', 'C', }, {'D', 'E', 'F', }, {'G', 'H', 'I', }, {'J', 'K', 'L', }, {'M', 'N', 'O', }, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V', }, {'W', 'X', 'Y', 'Z'}};
    
    char alphabet;
    int time = 0;
    
    int i, j;
    
    while(1) {
        scanf("%c", &alphabet);
        
        if(alphabet > 'Z' || 'A' > alphabet)
            break;
        
        i = 1; j = 0;
        
        while(i < 11) {
            if(j == 4)
                j = 0;
            while(j < 4) {
                if(dial[i][j] == alphabet) {
                    time += (++ i);
                    i = 11; j = 5;
                }
                
                j ++;
            }
            
            i ++;
        }
    }
    
    printf("%d", time);
    
    return 0;
}
