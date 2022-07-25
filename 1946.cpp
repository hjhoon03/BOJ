#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);

        for(int j = 0; j < n; ++j) {
            cin >> v[j].first >> v[j].second;
        }

        sort(v.begin(), v.end());

        int cnt = n;
        int high = v[0].second;

        for(int j = 1; j < n; ++j) {
            if(high > v[j].second)
                high = v[j].second;
            else
                --cnt;
        }

        cout << cnt << '\n';
    }

    return 0;
}