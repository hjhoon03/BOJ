#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    char maze[100][101] = {0};

    for(int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    int check[100][100] = {0};

    queue<pair<int, int>> q;
    check[0][0] = 1;
    pair<int, int> now = make_pair(0, 0);

    q.push(now);
    while(1) {

        if(0 <= now.first + 1 && now.first + 1 < n && 0 <= now.second && now.second < m && maze[now.first + 1][now.second] == '1' && check[now.first + 1][now.second] == 0) {
            check[now.first + 1][now.second] = check[now.first][now.second] + 1;

            if(now.first + 2 == n && now.second + 1 == m)
                break;

            q.push(make_pair(now.first + 1, now.second));
        }

        if(0 <= now.first - 1 && now.first - 1 < n && 0 <= now.second && now.second < m && maze[now.first - 1][now.second] == '1' && check[now.first - 1][now.second] == 0) {
            check[now.first - 1][now.second] = check[now.first][now.second] + 1;

            if(now.first == n && now.second + 1 == m)
                break;

            q.push(make_pair(now.first - 1, now.second));
        }

        if(0 <= now.first && now.first < n && 0 <= now.second + 1 && now.second + 1 < m && maze[now.first][now.second + 1] == '1' && check[now.first][now.second + 1] == 0) {
            check[now.first][now.second + 1] = check[now.first][now.second] + 1;

            if(now.first + 1 == n && now.second + 2 == m)
                break;

            q.push(make_pair(now.first, now.second + 1));
        }

        if(0 <= now.first && now.first < n && 0 <= now.second - 1 && now.second - 1 < m && maze[now.first][now.second - 1] == '1' && check[now.first][now.second - 1] == 0) {
            check[now.first][now.second - 1] = check[now.first][now.second] + 1;

            if(now.first + 1 == n && now.second == m)
                break;

            q.push(make_pair(now.first, now.second - 1));
        }

        q.pop();

        now = q.front();
    }

    cout << check[n - 1][m - 1];

    return 0;
}