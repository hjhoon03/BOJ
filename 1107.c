#include <stdio.h>
int broken[10] = {0};
int now[7] = {-1, 0, };

int make_plus(int num) {
    if(num < 0) return -1 * num;

    return num;
}


void avoid(int index, int min_num) {
    if(index > 6) now[0] = -1;
    else if(now[index] >= 10) {
        now[index] = min_num;
        index ++;
        now[index] ++;
        avoid(index, min_num);
    }
    else if(broken[now[index]]) {
        now[index] ++;
        avoid(index, min_num);
    }
}

int main() {
    int num, button, count = 0, min_num = -1;

    scanf("%d", &num);
    scanf("%d", &button);

    for(int i = 0; i < button; i ++) {
        int temp;
        scanf("%d", &temp);
        broken[temp] = 1;
    }

    // ?
    for(int i = 0; i < 10; i ++) {
        if(broken[i] == 0) {
            min_num = i;
            break;
        }
    }

    if(min_num == -1) {
        printf("%d", make_plus(100 - num));
        return 0;
    }

    int min = 1000000;
    int temp = -10;
    int copy;


    while(1) {
        now[0] ++;
        avoid(0, min_num);

        copy = temp;
        temp = 0;
        for(int j = 6; j >= 0; j --) {
            temp *= 10;
            temp += now[j];
        }

        int dif = make_plus(num - temp);

        count = 0;
        for(; temp; temp /= 10) count ++;
        if(count == 0) count ++;

        dif += count;

        if(now[0] == -1) break;
        else if(dif < min) min = dif;
    }

    if(make_plus(100 - num) < min) min = make_plus(100 - num);

    printf("%d", min);
}
