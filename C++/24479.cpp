#include <iostream>
#include <vector>

using namespace std;

int cnt = 1;
vector<int> graph[100000];
int check[100000];

void DFS(int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    int n1, n2;
    for(int i = 0; i < m; ++i) {
        cin >> n1 >> n2;

        graph[n1 - 1].emplace_back(n2 - 1);
        graph[n2 - 1].emplace_back(n1 - 1);
    }

    for(int i = 0; i < n; ++i) {
        if(graph[i].size() >= 2)
            sort(graph[i].begin(), graph[i].end());
    }

    DFS(r - 1);

    for(int i = 0; i < n; ++i) {
        cout << check[i] << '\n';
    }

    return 0;
}

void DFS(int n) {
    check[n] = cnt;
    ++cnt;

    int next;
    for(int i = 0; i < graph[n].size(); ++i) {
        next = graph[n][i];
        if (check[next] == 0) {
            DFS(next);
        }
    }
}