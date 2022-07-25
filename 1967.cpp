#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int check[100000];

pii dfs_sum_distance(vector<vector<pii>>*, int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pii>> tree(n);

    int node_idx, link, distance;
    for(int i = 0; i < n; ++i) {
        cin >> node_idx;
        cin >> link;
        while(link != -1) {
            cin >> distance;
            tree[node_idx - 1].emplace_back(make_pair(link - 1, distance));

            cin >> link;
        }
    }

    int mun_node = dfs_sum_distance(&tree, 0, 0).first;

    for(int i = 0; i < n; ++i) {
        check[i] = 0;
    }

    cout << dfs_sum_distance(&tree, mun_node, 0).second;

    return 0;
}

pii dfs_sum_distance(vector<vector<pii>>* ptree, int node_idx, int sum_distance) {
    check[node_idx] = 1;

    int max = sum_distance, return_node = node_idx;
    pii tmp = make_pair(node_idx, 0);
    for(int i = 0; i < (*ptree)[node_idx].size(); ++i) {
        pii node = (*ptree)[node_idx][i];
        if(check[node.first] == 0) {
            tmp = dfs_sum_distance(ptree, node.first, sum_distance + node.second);
        }

        if(max < tmp.second) {
            max = tmp.second;
            return_node = tmp.first;
        }
    }

    return make_pair(return_node, max);
}