#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void do_DFS(int*, int, vector<vector<int>>[]);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n);
    int n1, n2;

    for(int i = 0; i < m; ++i) {
        cin >> n1 >> n2;
        graph[n1 - 1].emplace_back(n2);
        graph[n2 - 1].emplace_back(n1);
    }

    for(int i = 0; i < n; ++i) {
        if(graph[i].empty() == 0) {
            sort(graph[i].begin(), graph[i].end());
        }
    }

    // DFS
    int check_DFS[1000] = {0};
    do_DFS(check_DFS, v, &graph);
    cout << '\n';


    // BFS
    int check_BFS[1000] = {0};
    queue<int> q;
    q.push(v);
    check_BFS[v - 1] = 1;

    while(q.empty() == 0) {
        cout << q.front() << ' ';
        for (int i = 0; i < graph[q.front() - 1].size(); ++i) {
            int next = graph[q.front() - 1][i];
            if(check_BFS[next - 1] == 0) {
                q.push(next);
                check_BFS[next - 1] = 1;
            }
        }
        q.pop();
    }

    return 0;
}

void do_DFS(int* check, int n, vector<vector<int>>* graph) {
    cout << n << ' ';
    check[n - 1] = 1;

    int next_idx;

    for(int i = 0; i < (*graph)[n - 1].size(); ++i) {
        next_idx = (*graph)[n - 1][i] - 1;
        if(check[next_idx] == 0)
            do_DFS(check, next_idx + 1, graph);
    }
}