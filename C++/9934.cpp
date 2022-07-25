#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    vector<int> line_check(n);

    int node_num = 1;

    for(int i = 1; i < n; ++i) {
        node_num *= 2;
        ++node_num;
    }

    for(int i = 0; i < node_num; ++i) {
        for(int j = 0; j < n; ++j) {
            if(line_check[j] == 0) {
                tree[j].emplace_back();
                cin >> tree[j][tree[j].size() - 1];
                line_check[j] = 1;
                for(int k = 0; k < j; ++k) {
                    line_check[k] = 0;
                }
                break;
            }
        }
    }

    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < tree[i].size(); ++j) {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}