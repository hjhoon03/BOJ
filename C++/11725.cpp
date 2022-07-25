#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100000];
int parents[100000];

void DFS(int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int n1, n2;
    for(int i = 0; i < n - 1; ++i) {
        cin >> n1 >> n2;
        arr[n1 - 1].emplace_back(n2 - 1);
        arr[n2 - 1].emplace_back(n1 - 1);
    }


    DFS(0, 0);

    for(int i = 1; i < n; ++i) {
        cout << parents[i] << '\n';
    }

    return 0;
}

void DFS(int parent, int node_idx) {
    if(arr[node_idx].empty() || parents[node_idx]) {
        return;
    }

    parents[node_idx] = parent + 1;

    for(int i = 0; i < arr[node_idx].size(); ++i) {
        DFS(node_idx, arr[node_idx][i]);
    }
}