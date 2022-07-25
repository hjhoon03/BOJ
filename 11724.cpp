#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[1000];
int check[1000];

void DFS(int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int n1, n2;
    for(int i = 0; i < m; ++i) {
        cin >> n1 >> n2;
        arr[n1 - 1].emplace_back(n2 - 1);
        arr[n2 - 1].emplace_back(n1 - 1);
    }


    int cnt = 0;

    for(int i = 0; i < n; ++i) {
        if(check[i])
            continue;

        DFS(i);
        ++cnt;
    }

    cout << cnt;

    return 0;
}

void DFS(int node_idx) {
    if(arr[node_idx].empty() || check[node_idx]) {
        return;
    }

    check[node_idx] = 1;

    for(int i = 0; i < arr[node_idx].size(); ++i) {
        DFS(arr[node_idx][i]);
    }
}