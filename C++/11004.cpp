#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < n; ++i) {
        v.emplace_back();
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << v[m - 1];

    return 0;
}