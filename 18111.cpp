// BOJ 18111
#include <iostream>
#include <vector>

using namespace std;

#define INF 9223372036854775807

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    long long int time, min = INF, h, blocks, now_h;
    bool flag;
    for(int i = 0; i <= 256; ++i) {
        time = 0;
        blocks = b;
        flag = true;
        for(int j = 0; j < n && flag; ++j) {
            for(int k = 0; k < m && flag; ++k) {
                now_h = v[j][k];
                if(now_h < i) {
                    time += (i - now_h);
                    blocks -= (i - now_h);
                } else if(now_h > i) {
                    time += (2 * (now_h - i));
                    blocks += (now_h - i);
                }

                if(time > min) {
                    flag = false;
                }
            }
        }

        if(blocks < 0)
            flag = false;

        if(flag) {
            min = time;
            h = i;
        }
    }

    cout << min << ' ' << h;

    return 0;
}