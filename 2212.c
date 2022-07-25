#include <stdio.h>

// 101001101
int main() {
    int n, k, spot;
    char road[2000001] = {0}; // 0 ~ 999999 : -1000000 ~ -1 / 1000000 : 0 / 1000001 ~ 2000000 : 1 ~ 1000000
    int sensor[10000] = {0};
    int index = 0;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d", &spot);
        
        road[spot + 1000000] = 1;
    }
    
    for(int i = 0; i < 2000001; i ++) {
        if(road[i]) {
            sensor[index] = i;
            index ++;
        }
    }
    
    int distance[10000] = {0};
    
    for(int i = 0; i < index; i ++) {
        if(i == 0) distance[0] = 0;
        else {
            distance[i] = sensor[i] - sensor[i - 1];
        }
    }
    
    int max = 0;
    
    for(int j = k - 1; j; j --) {
        for(int i = 1; i < index; i ++) {
            if(distance[max] < distance[i]) max = i;
        }
        distance[max] = 0;
    }
    
    int sum = 0;
    
    for(int i = 0; i < index; i ++) {
        sum += distance[i];
    }
    
    printf("%d", sum);
}
