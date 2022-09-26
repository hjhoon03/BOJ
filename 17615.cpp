// BOJ 17615
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    char ball;
    bool flag = false;
    int cnt = 0;

    int R_ball = 0, B_ball = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == 'R')
            ++R_ball;
        else
            ++B_ball;
    }

    int min;
    if(R_ball < B_ball)
        min = R_ball;
    else
        min = B_ball;

    ball = s[0];
    for(int i = 1; i < n; ++i) {
        if(!flag && ball != s[i])
            flag = true;

        if(!flag)
            continue;

        if(ball == s[i])
            ++cnt;
    }

    if(min > cnt)
        min = cnt;
    cnt = 0;
    flag = false;

    ball = s[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        if(!flag && ball != s[i])
            flag = true;

        if(!flag)
            continue;

        if(ball == s[i])
            ++cnt;
    }

    if(min > cnt)
        min = cnt;

    cout << min;

    return 0;
}