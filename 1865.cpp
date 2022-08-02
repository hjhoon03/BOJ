// BOJ 1865
#include <iostream>
#include <vector>

using namespace std;

bool solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; ++i) {
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool solve() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<int> cost(n, 0);
    vector<vector<int>> road(m, vector<int>(3));
    vector<vector<int>> hole(w, vector<int>(3));

    for(int i = 0; i < m; ++i) {
        cin >> road[i][0] >> road[i][1] >> road[i][2];
    }

    for(int i = 0; i < w; ++i) {
        cin >> hole[i][0] >> hole[i][1] >> hole[i][2];
    }

    int now, next, price;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            now = road[j][0] - 1;
            next = road[j][1] - 1;
            price = cost[now] + road[j][2];

            if (cost[next] > price) {
                cost[next] = price;
                if (i == n - 1)
                    return true;
            }


            now = road[j][1] - 1;
            next = road[j][0] - 1;
            price = cost[now] + road[j][2];

            if(cost[next] > price) {
                cost[next] = price;
                if(i == n - 1)
                    return true;
            }
        }

        for(int j = 0; j < w; ++j) {
            now = hole[j][0] - 1;
            next = hole[j][1] - 1;
            price = cost[now] - hole[j][2];

            if(cost[next] > price) {
                cost[next] = price;
                if(i == n - 1)
                    return true;
            }

        }
    }

    return false;
}