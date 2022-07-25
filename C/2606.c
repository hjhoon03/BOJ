#include <stdio.h>
#include <stdlib.h>

typedef struct com {
    int infection;
    int link_cnt;
    struct com* link[100];
} COMPUTER;

void link(COMPUTER*, COMPUTER*);
int spread(COMPUTER*);

int main() {
    int n;
    scanf("%d", &n);

    COMPUTER* arr = (COMPUTER*)malloc(sizeof(COMPUTER) * n);

    for(int i = 0; i < n; ++i) {
        arr[i].infection = 0;
        arr[i].link_cnt = 0;
    }

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; ++i) {
        int com1_idx, com2_idx;
        scanf("%d %d", &com1_idx, &com2_idx);
        link(&arr[com1_idx - 1], &arr[com2_idx - 1]);
    }

    arr->infection = 1;
    printf("%d", spread(arr));

    return 0;
}

void link(COMPUTER* com1, COMPUTER* com2) {
    (com1->link)[com1->link_cnt] = com2;
    (com2->link)[com2->link_cnt] = com1;

    ++(com1->link_cnt);
    ++(com2->link_cnt);
}

int spread(COMPUTER* com) {
    int n = com->link_cnt;
    int cnt = 0;

    for(int i = 0; i < n; ++i) {
        COMPUTER* target = (com->link)[i];
        if(target->infection == 0) {
            target->infection = 1;
            cnt += spread(target);
            ++cnt;
        }
    }

    return cnt;
}