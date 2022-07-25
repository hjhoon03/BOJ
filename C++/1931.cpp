#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int prev = v[0].second;

    for(int i = 1; i < n; ++i) {
        if(prev <= v[i].first) {
            prev = v[i].second;
            ++cnt;
        } else if(prev > v[i].second) {
            prev = v[i].second;
        }
    }

    cout << cnt;

    return 0;
}