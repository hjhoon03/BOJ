#include <stdio.h>

int main() {
    char word[100] = "0";
    int alphabet[26] = {0};
    int index;
    
    for(int i = 0; i < 26; i ++)
        alphabet[i] = -1;
    
    scanf("%s", word);
    
    for(int i = 0; word[i]; i ++) {
        index = word[i] - 'a';
        if(alphabet[index] == -1)
            alphabet[index] = i;
    }
    
    for(int i = 0; i < 26; i ++) {
        printf("%d", alphabet[i]);
        if(i != 26)
            printf(" ");
    }
    
    return 0;
}
