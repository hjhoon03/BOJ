#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h;

    queue<vector<int>> q;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) {
                    vector<int> tmp = {i, j, k};
                    q.push(tmp);
                }
            }
        }
    }

    int cnt = 1, now_cnt;
    vector<int> now;
    while(q.empty() == 0) {
        now = q.front();
        now_cnt = box[now[0]][now[1]][now[2]];

        if(now[2] + 1 < m && box[now[0]][now[1]][now[2] + 1] == 0) {
            box[now[0]][now[1]][now[2] + 1] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0], now[1], now[2] + 1};
            q.push(tmp);
        }

        if(0 <= now[2] - 1 && box[now[0]][now[1]][now[2] - 1] == 0) {
            box[now[0]][now[1]][now[2] - 1] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0], now[1], now[2] - 1};
            q.push(tmp);
        }

        if(now[1] + 1 < n && box[now[0]][now[1] + 1][now[2]] == 0) {
            box[now[0]][now[1] + 1][now[2]] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0], now[1] + 1, now[2]};
            q.push(tmp);
        }

        if(0 <= now[1] - 1 && box[now[0]][now[1] - 1][now[2]] == 0) {
            box[now[0]][now[1] - 1][now[2]] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0], now[1] - 1, now[2]};
            q.push(tmp);
        }

        if(now[0] + 1 < h && box[now[0] + 1][now[1]][now[2]] == 0) {
            box[now[0] + 1][now[1]][now[2]] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0] + 1, now[1], now[2]};
            q.push(tmp);
        }

        if(0 <= now[0] - 1 && box[now[0] - 1][now[1]][now[2]] == 0) {
            box[now[0] - 1][now[1]][now[2]] = now_cnt + 1;

            if(cnt == now_cnt)
                ++cnt;


            vector<int> tmp = {now[0] - 1, now[1], now[2]};
            q.push(tmp);
        }

        q.pop();
    }

    int flag = 1;

    for(int i = 0; i < h && flag; ++i) {
        for(int j = 0; j < n && flag; ++j) {
            for(int k = 0; k < m && flag; ++k) {
                if(box[i][j][k] == 0)
                    flag = 0;
            }
        }
    }

    if(flag == 0)
        cout << -1;
    else
        cout << cnt - 1;

    return 0;
}