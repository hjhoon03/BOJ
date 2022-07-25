#include <stdio.h>

int main() {
    int n, min = 0, temp;
    int age[100000] = {0};
    char name[100000][101] = {0};
    int index[100000] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d %s", &age[i], name[i]);
    }
    
    for(int i = 0; i < n; ) {
        temp = 250;
        for(int j = 0; j < n; j ++) {
            if(min < age[j] && age[j] < temp)
                temp = age[j];
        }
        min = temp;
        for(int j = 0; j < n; j ++) {
            if(age[j] == min) {
                index[i] = j;
                i ++;
            }
        }
    }
    
    for(int i = 0; i < n; i ++) {
        printf("%d %s\n", age[index[i]], name[index[i]]);
    }
}
