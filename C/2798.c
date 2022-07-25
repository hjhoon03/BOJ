#include <stdio.h>
int num[100] = {0, };

void size(void) {
    int index, temp;
    for(int i = 0; num[i]; i ++) {
        index = i;
        for(int j = i; num[j]; j ++) {
            if(num[j] < num[index])
                index = j;
        }
        temp = num[i];
        num[i] = num[index];
        num[index] = temp;
    }
}

int main() {
    int n, m;
    int temp = 1;
    int result = 0, sum;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d", &num[i]);
    }
    
    size();
    
    for(int i = 0; i < n - 2 && temp; i ++) {
        for(int j = i + 1; j < n - 1 && temp; j ++) {
            for(int k = j + 1; k < n && temp; k ++) {
                sum = num[i] + num[j] + num[k];
                if(m == sum) {
                    temp = 0;
                    result = sum;
                }
                else if(m < sum)
                    break;
                else {
                    if(m - sum < m - result)
                        result = sum;
                }
            }
        }
    }
    
    printf("%d", result);
}
