#include <stdio.h>

int main() {
    int n, index = 0;
    double score[1000] = {0};
    double sum = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%lf", &score[i]);
        if(score[index] < score[i])
            index = i;
    }
    
    for(int i = 0; i < n; i ++) {
        sum += (score[i] / score[index]) * 100;
    }
    
    printf("%lf", (double)sum / n);
}
