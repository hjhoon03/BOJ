#include <stdio.h>

int main() {
    int t, k, n;
    
    scanf("%d", &t);
    
    for(int i = 0; i < t; i ++) {
        int arr[15][14] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 0};
        scanf("%d", &k);
        scanf("%d", &n);
        for(int j = 1; j <= k; j ++) {
            if(j == k) {
                for(int l = 0; l < n; l ++) {
                    arr[j][n - 1] += arr[j - 1][l];
                }
            }
            else {
                for(int l = 0; l < n; l ++) {
                    for(int m = 0; m <= l; m ++)
                        arr[j][l] += arr[j - 1][m];
                }
            }
        }
        
        printf("%d\n", arr[k][n - 1]);
    }
}
