#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v_index(n);
    vector<string> v_name(n);

    for(int i = 0; i < n; i ++) {
        v_index[i].second = i;
        cin >> v_index[i].first >> v_name[i];
    }

    sort(v_index.begin(), v_index.end());

    for(int i = 0; i < n; i ++) cout << v_index[i].first << ' ' << v_name[v_index[i].second] << '\n';
}