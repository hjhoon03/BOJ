#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, string>> v(n);

    for(int i = 0; i < n; i ++) {
        cin >> v[i].second;
        v[i].first = v[i].second.length();
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n - 1; i ++) if(v[i].second == v[i + 1].second) v[i].first = 0;

    for(int i = 0; i < n; i ++) {
        if(v[i].first) cout << v[i].second << '\n';
    }

    return 0;
}