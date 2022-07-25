#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> spot;

    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        spot.push_back(make_pair(b, a));
    }

    sort(spot.begin(), spot.end());

    for(int i = 0; i < n; i ++) cout << spot[i].second << ' ' << spot[i].first << '\n';

    return 0;
}