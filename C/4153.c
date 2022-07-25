#include <stdio.h>
#include <math.h>

int main() {
    int triangle[3] = {0};
    int line[2] = {0};
    
    while(1) {
        scanf("%d %d %d", &triangle[0], &triangle[1], &triangle[2]);
        
        if(triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0)
            return 0;
        
        int max = triangle[0];
        int index = 0;
        
        for(int i = 1; i < 3; i ++) {
            if(max < triangle[i]) {
                max = triangle[i];
                index = i;
            }
        }
        
        int j = 0;
        
        for(int i = 0; i < 2; i ++) {
            if(j == index)
                j ++;
            
            line[i] = j;
            
            j ++;
        }
        
        if(pow(triangle[line[0]], 2) + pow(triangle[line[1]], 2) == pow(triangle[index], 2))
            printf("right\n");
        else
            printf("wrong\n");
        
    }
}
