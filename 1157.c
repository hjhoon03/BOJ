#include <stdio.h>

int main() {
    char word[1000000] = "0";
    int alphabet[26] = {0};
    int temp = 1, max = 0;
    
    scanf("%s", word);
    
    for(int i = 0; word[i]; i ++) {
        if('a' <= word[i] && word[i] <= 'z')
            word[i] += 'A' - 'a';
        alphabet[(int)(word[i] - 'A')] ++;
    }
    
    for(int i = 1; i < 26; i ++) {
        if(alphabet[max] < alphabet[i]) {
            temp = 1;
            max = i;
        }
        else if(alphabet[max] == alphabet[i])
            temp = 0;
    }
    
    if(temp)
        printf("%c", max + 'A');
    else
        printf("?");
}
