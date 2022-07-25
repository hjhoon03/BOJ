#include <iostream>
#include <vector>

using namespace std;

int on = 1;
int off = 0;

typedef struct {
    int time_on;
    int time_off;
    int remain_time;
    int* status = &on;
} robot;

int next(robot*, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;
    vector<robot> section(n);

    for(int i = 0; i < n; i ++) {
        cin >> section[i].time_off >> section[i].time_on;
        section[i].remain_time = section[i].time_on;
    }

    for(int i = 0; i < n; i ++) {
        int cycle = section[i].time_off + section[i].time_on;
        cnt += next(&section[i], (cnt % cycle)) + 1;
    }

    cout << cnt;

    return 0;
}

int next(robot* pr, int time) {
    (*pr).remain_time -= time;
    if((*pr).remain_time <= 0) return 0;
    else return (*pr).remain_time;
}