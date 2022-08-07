// BOJ 11722
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n, make_pair(0, 0));

    for(int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }

    int max, std;
    for(int i = n - 1; i >= 0; --i) {
        std = v[i].first;
        max = 0;

        for(int j = i + 1; j < n; ++j) {
            if(std > v[j].first) {
                if(max < v[j].second) {
                    max = v[j].second;
                }
            }
        }

        v[i].second = max + 1;
    }

    max = 0;
    for(int i = 0; i < n; ++i) {
        if(max < v[i].second)
            max = v[i].second;
    }

    cout << max;

    return 0;
}