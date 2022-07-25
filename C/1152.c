#include <stdio.h>

int main() {
    char word = '-';
    int count = 1;
    int word_count = 0;
    int space_count = 0;
    
    scanf("%c", &word);
    
    while(word != '\n') {
        
        if(word == ' ' && word_count == 0) {
            scanf("%c", &word);
            ++ space_count;
        }
        else if(word == ' ') {
            ++ count;
            scanf("%c", &word);
            if(word == '\n') {
                -- count;
            }
        }
        else {
            scanf("%c", &word);
        }
        
        ++ word_count;
        
    }
    
    if(word_count == 0) {
        count = 0;
    }
    else if(word_count == 1 && space_count == 1) {
        count = 0;
    }
    
    printf("%d\n", count);
    
    return 0;
}
