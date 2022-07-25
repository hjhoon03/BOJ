#include <stdio.h>

int main() {
    int n;
    int arr[100000][2] = {0};
    int index[100000] = {0};
    int index2 = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        index[i] = -1;
        for(int j = 0; j < 2; j ++) {
            arr[i][j] = -111111;
        }
    }
    
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    
    for(int k = 0; k < n; k ++) {
        int min = 111111;
        int tmp;
        for(int i = 0; i < n; i ++) {
            if(arr[i][0] == -111111) continue;
            else if(min > arr[i][0]) {
                min = arr[i][0];
                tmp = 1;
                for(int j = 0; index[j] > -1; j ++) {
                    index[j] = -1;
                }
                index[0] = i;
            }
            else if(min == arr[i][0]) {
                index[tmp] = i;
                tmp ++;
            }
        }
        
        if(tmp == 1) {
            printf("%d %d\n", arr[index[0]][0], arr[index[0]][1]);
            arr[index[0]][0] = -111111;
            arr[index[0]][1] = -111111;
        }
        else {
            min = arr[index[0]][1];
            for(int i = 1; i < tmp; i ++) {
                if(min > arr[index[i]][1]) {
                    min = arr[index[i]][1];
                    index2 = i;
                }
            }
            
            printf("%d %d\n", arr[index[index2]][0], min);
            arr[index[index2]][0] = -111111;
            arr[index[index2]][1] = -111111;
        }
    }
}
