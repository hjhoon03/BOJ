#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int arr[500000] = {0};
    double sum01 = 0;
    int num_time[8001] = {0};
    int bin[8001] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d", &arr[i]);
        sum01 += (double)arr[i];
        num_time[arr[i] + 4000] ++;
    }
    
    printf("%.0lf\n", fabs(sum01 / (double)n));
    
    for(int i = 0; i < n - 1; i ++) {
        int index = i;
        for(int j = i + 1; j < n; j ++) {
            if(arr[index] > arr[j])
                index = j;
        }
        
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
    printf("%d\n", arr[n / 2]);
    
    int count;
    
    for(int i = 1; i < 4001; i ++) {
        int index = 0;
        count = 1;
        bin[0] = -4000;
        
        for(int i = 1; i < 8001; i ++) {
            if(num_time[index] < num_time[i]) {
                for(int j = 0; j < count; j ++)
                    bin[j] = 0;
                index = i;
                bin[0] = index - 4000;
                count = 1;
            }
            else if(num_time[index] == num_time[i]) {
                bin[count] = i - 4000;
                count ++;
            }
        }
    }
    
    if(count > 1)
        printf("%d\n", bin[1]);
    else
        printf("%d\n", bin[0]);
    
    printf("%d", arr[n - 1] - arr[0]);
}
