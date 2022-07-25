#include <stdio.h>

int length(char list[101]) {
    int length = 0;
    
    for(int i = 0; list[i]; i ++) {
        length ++;
    }
    
    return length;
}

void reverse(char list[101], int length, char reverse[101]) {
    
    int i = 0;
    for(; length; length --) {
        
        reverse[i] = list[length - 1];
        
        i ++;
    }
}

int SUM() {
    // 48 ~ 57
    char A[101] = "";
    char B[101] = "";
    char reverse_A[101] = "";
    char reverse_B[101] = "";
    char SUM[102] = "";
    int sum = 0;
    int len = 0;
    char result[102] = "";
    
    scanf("%s %s", A, B);
    
    reverse(A, length(A), reverse_A);
    reverse(B, length(B), reverse_B);
    
    if(length(A) > length(B))
        len = length(A);
    else
        len = length(B);
    
    for(int i = 0; i < len; i ++) {
        int sum_num = (int)SUM[i];
        int a_num = (int)reverse_A[i];
        int b_num = (int)reverse_B[i];
        
        if(SUM[i] == 0)
            sum_num += 48;
        if(reverse_A[i] == 0)
            a_num += 48;
        if(reverse_B[i] == 0)
            b_num += 48;
        
        sum = a_num + b_num + sum_num - 144;
        
        SUM[i] = (sum % 10) + 48;
        SUM[i + 1] = (sum / 10) + 48;
        
    }
    
    if(SUM[len] == 48)
        SUM[len] = 0;
    else
        len ++;
    
    reverse(SUM, len, result);
    
    return result;
}
