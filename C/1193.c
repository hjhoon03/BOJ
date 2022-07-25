#include <stdio.h>

int main() {
    int n;
    int arr[2] = {1, 1};
    int index = 0;
    
    scanf("%d", &n);
    
    for(int i = 1; i != n; i ++) {
        if(arr[index] == 1) {
            if(index)
                index = 0;
            else
                index = 1;
            arr[index] ++;
        }
        else {
            if(index) {
                arr[index] --;
                arr[0] ++;
            }
            else {
                arr[index] --;
                arr[1] ++;
            }
        }
    }
    
    printf("%d/%d", arr[0], arr[1]);
}
