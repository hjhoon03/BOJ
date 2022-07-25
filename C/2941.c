#include <stdio.h>

int main() {
    char character[101] = "";
    int count = 0;
    
    int i = 0;
    
    scanf("%s", &character);
    
    while(character[i]) {
        if(character[i] == 'c') {
            if(character[i + 1] == '=')
                i ++;
            else if( character[i + 1] == '-')
                i ++;
        }
        else if(character[i] == 'd') {
            if(character[i + 1] == '-')
                i ++;
            else if(character[i + 1] == 'z') {
                if(character[i + 2] == '=')
                    i += 2;
            }
        }
        else if(character[i] == 'l') {
            if(character[i + 1] == 'j')
                i ++;
        }
        else if(character[i] == 'n') {
            if(character[i + 1] == 'j')
                i ++;
        }
        else if(character[i] == 's') {
            if(character[i + 1] == '=')
                i ++;
        }
        else if(character[i] == 'z') {
            if(character[i + 1] == '=')
                i ++;
        }
        
        i ++;
        count ++;
    }
    
    printf("%d", count);
    
    return 0;
}
