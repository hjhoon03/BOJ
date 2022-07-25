#include <stdio.h>
void push(int index, int *p, int num) {
    *(p + index) = num;
}

void pop(int index, int *p) {
    *(p + index - 1) = 0;
}

int main() {
    int n;
    char arr[200000] = "0";
    int index_arr = 0, index_stack = 0;
    int stack[100000] = {0};
    int num = 1;
    int input;
    
    scanf("%d", &n);
    
    while(num <= n || stack[0]) {
        scanf("%d", &input);
        
        if(input > num)
            for(; num <= input; num ++) {
                push(index_stack, stack, num);
                index_stack ++;
                
                arr[index_arr] = '+';
                index_arr ++;
                
                if(num == input) {
                    pop(index_stack, stack);
                    index_stack --;
                    
                    arr[index_arr] = '-';
                    index_arr ++;
                }
            }
        
        else if(input == num) {
            num ++;
            
            arr[index_arr] = '+';
            index_arr ++;
            arr[index_arr] = '-';
            index_arr ++;
        }
        
        else {
            if(input == stack[index_stack - 1]) {
                pop(index_stack, stack);
                index_stack --;
                
                arr[index_arr] = '-';
                index_arr ++;
            }
            else {
                printf("NO");
                return 0;
            }
        }
    }
    
    for(int i = 0; i < index_arr; i ++) {
        printf("%c\n", arr[i]);
    }
}
