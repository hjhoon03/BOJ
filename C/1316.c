#include <stdio.h>

int main() {
    int words = 0;
    int groups = 0;
    
    
    scanf("%d", &words);
    
    while(words --) {
        int group = 1;
        int list[26] = {0, };
        char word[101] = "";
        
        scanf("%s", word);
        
        int before = -1;
        int index = -1;
        
        for(int i = 0; word[i]; i ++) {
            index = (int)word[i] - 97;
            if(index != before) {
                switch(list[index]) {
                    case 0:
                        list[index] = 1;
                        break;
                    case 1:
                        group = 0;
                        break;
                }
                before = index;
            }
        }
        if(group)
            groups ++;
    }
    printf("%d", groups);
    
    return 0;
}
