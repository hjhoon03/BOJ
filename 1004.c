#include <stdio.h>
#include <math.h>

typedef struct {
    int spot[2];
    int radius;
} PLENET;

int in(PLENET, int*);
int cross(int, int);

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int prince[2] = {0};
        int rose[2] = {0};
        scanf("%d %d %d %d", prince, prince + 1, rose, rose + 1);

        int n;
        scanf("%d", &n);

        PLENET tmp;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", tmp.spot, tmp.spot + 1, &(tmp.radius));
            if(cross(in(tmp, prince), in(tmp, rose)))
                ++cnt;
        }

        printf("%d\n", cnt);
    }

    return 0;
}

int in(PLENET pl, int* obj) {
    int sqr_distance = pow(pl.spot[0] - obj[0], 2) + pow(pl.spot[1] - obj[1], 2);

    if(sqr_distance > pow(pl.radius, 2))
        return 0;
    else
        return 1;
}

int cross(int bool1, int bool2) {
    if(bool1 || bool2) {
        if(bool1 && bool2)
            return 0;
        return 1;
    }

    return 0;
}