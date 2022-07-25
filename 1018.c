#include <stdio.h>

int main() {
    char WB[8][9] = {{"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}};
    
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    char arr[51][51] = {0};
    
    /*
        
    char **arr;
            
    arr = (char **)malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i ++) {
        arr[i] = (char *)malloc(sizeof(char) * m + 1);
    }
     */
    
    for(int i = 0; i < n; i ++) {
        scanf("%s", arr[i]);
    }
    
    /*
    for(int i = 0; i < 8; i ++) {
        if(i % 2) {
            for(int j = 0; j < 8; j += 2) {
                WB[i][j] = 'B';
                WB[i][j + 1] = 'W';
            }
        }
        else {
            for(int j = 0; j < 8; j += 2) {
                WB[i][j] = 'W';
                WB[i][j + 1] = 'B';
            }
        }
    }
     */
    
    int BW_count, WB_count, min = 65;
    
    for(int i = 0; i < n - 7; i ++ /* 세로 */) {
        for(int j = 0; j < m - 7; j ++ /* 가로 */) {
            BW_count = 0;
            WB_count = 0;
            for(int k = 0; k < 8; k ++) {
                for(int l = 0; l < 8; l ++) {
                    if(WB[k][l] == arr[i + k][j + l])
                        BW_count ++;
                    else if(arr[i + k][j + l] == 'W')
                        WB_count ++;
                    else if(arr[i + k][j + l] == 'B')
                        WB_count ++;
                    else {
                        WB_count ++;
                        BW_count ++;
                    }
                }
            }
            if(min > BW_count)
                min = BW_count;
            if(min > WB_count)
                min = WB_count;
        }
    }
    
    printf("%d", min);
    
    return 0;
}
