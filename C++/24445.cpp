#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100000];
int check[100000];
queue<int> tmp;
int cnt;

void do_bfs();

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
        if (graph[i].size() >= 2) {
            sort(graph[i].rbegin(), graph[i].rend());
        }
    }

    tmp.push(r - 1);

    do_bfs();

    for(int i = 0; i < n; ++i) {
        cout << check[i] << '\n';
    }

    return 0;
}

void do_bfs() {
    if(tmp.empty())
        return;

    int n = tmp.front();
    tmp.pop();

    if(check[n] != 0) {
        do_bfs();
        return;
    }

    ++cnt;
    check[n] = cnt;

    int next;
    for(int i = 0; i < graph[n].size(); ++i) {
        next = graph[n][i];
        if(check[next] == 0) {
            tmp.push(next);
        }
    }
    
    do_bfs();
}