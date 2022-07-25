#include <stdio.h>
#include <math.h>

double made_plus(double number) {
    if(number < 0)
        number *= -1;
    
    return number;
}

int main() {
    int count;
    int big;
    
    scanf("%d", &count);
    
    while(count --) {
        int spot[2][3];
        
        for(int i = 0; i < 2; i ++) {
            for(int j = 0; j < 3; j ++) {
                scanf("%d", &spot[i][j]);
            }
        }
        
        if((spot[0][2] == spot[1][2]) && (spot[0][0] == spot[1][0]) && (spot[0][1] == spot[1][1])) {
            printf("%d\n", -1);
            continue;
        }
        else if(spot[0][2] > spot[1][2]) {
            big = 0;
        }
        else {
            big = 1;
        }
        
        double distance = (spot[0][0] - spot[1][0]) * (spot[0][0] - spot[1][0]) + (spot[0][1] - spot[1][1]) * (spot[0][1] - spot[1][1]);
        
        distance = sqrt(distance);
        
        if(spot[big][2] == distance)
            printf("%d\n", 2);
        else if(spot[big][2] > distance) {
            if((double)made_plus(spot[0][2] - spot[1][2]) > distance)
                printf("%d\n", 0);
            else if((double)made_plus(spot[0][2] - spot[1][2]) < distance)
                printf("%d\n", 2);
            else
                printf("%d\n", 1);
        }
        else {
            if((double)(spot[0][2] + spot[1][2]) > distance)
                printf("%d\n", 2);
            else if((double)(spot[0][2] + spot[1][2]) < distance)
                printf("%d\n", 0);
            else
                printf("%d\n", 1);
        }
    }
    
    return 0;
}
