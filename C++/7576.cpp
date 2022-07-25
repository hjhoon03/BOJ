#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    int box[1000][1000] = {0};
    queue<pair<int, int>> BFS_q;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> box[i][j];

            if(box[i][j] == 1)
                BFS_q.push(make_pair(i, j));
        }
    }

    int day = 1;
    int x, y;

    while(BFS_q.empty() == 0) {
        x = BFS_q.front().first;
        y = BFS_q.front().second;

        if(x + 1 < n && box[x + 1][y] == 0) {
            box[x + 1][y] = box[x][y] + 1;
            BFS_q.push(make_pair(x + 1, y));
            if(day < box[x + 1][y])
                day = box[x + 1][y];
        }

        if(0 <= x - 1 && box[x - 1][y] == 0) {
            box[x - 1][y] = box[x][y] + 1;
            BFS_q.push(make_pair(x - 1, y));
            if(day < box[x - 1][y])
                day = box[x - 1][y];
        }

        if(y + 1 < m && box[x][y + 1] == 0) {
            box[x][y + 1] = box[x][y] + 1;
            BFS_q.push(make_pair(x, y + 1));
            if(day < box[x][y + 1])
                day = box[x][y + 1];
        }

        if(0 <= y - 1 && box[x][y - 1] == 0) {
            box[x][y - 1] = box[x][y] + 1;
            BFS_q.push(make_pair(x, y - 1));
            if(day < box[x][y - 1])
                day = box[x][y - 1];
        }

        BFS_q.pop();
    }

    int flag = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(box[i][j] == 0) {
                flag = 1;
                break;
            }
        }
    }

    if(flag) {
        cout << -1;
    } else {
        cout << day - 1;
    }

    return 0;
}