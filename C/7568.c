#include <stdio.h>

int main() {
    int n;
    int dungchi[50][2] = {{0}};
    int grade[50];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++)
        grade[i] = 1;
    
    for(int i = 0; i < n; i ++)
        scanf("%d %d", &dungchi[i][0], &dungchi[i][1]);
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i == j)
                continue;
            
            if(dungchi[i][0] < dungchi[j][0] && dungchi[i][1] < dungchi[j][1])
                grade[i] ++;
        }
    }
    
    for(int i = 0; i < n; i ++)
        printf("%d ", grade[i]);
}
