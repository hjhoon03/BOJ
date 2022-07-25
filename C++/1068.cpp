#include <iostream>
#include <vector>

using namespace std;

int DFS_leaf_cnt(vector<vector<int>>*, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent(n);

    for(int i = 0; i < n; ++i) {
        cin >> parent[i];
    }

    vector<vector<int>> next(n);
    int root, delete_node;
    cin >> delete_node;

    for(int i = 0; i < n; ++i) {
        if(i == delete_node) {
            if(parent[i] == -1) {
                cout << 0;
                return 0;
            }
            continue;
        }

        if(parent[i] == -1) {
            root = i;
            continue;
        }

        if(parent[i] != delete_node) {
            next[parent[i]].emplace_back(i);
        }
    }

    cout << DFS_leaf_cnt(&next, root);

    return 0;
}

int DFS_leaf_cnt(vector<vector<int>>* ptree, int node_idx) {
    vector<vector<int>> tree = *ptree;

    if(tree[node_idx].empty()) {
        return 1;
    }

    int result = 0;

    for(int i = 0; i < tree[node_idx].size(); ++i) {
        result += DFS_leaf_cnt(ptree, tree[node_idx][i]);
    }

    return result;
}