#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> spot(n);

    for(int i = 0; i < n; i ++) {
        cin >> spot[i].first >> spot[i].second;
    }

    sort(spot.begin(), spot.end());

    for(int i = 0; i < n; i ++) {
        cout << spot[i].first << ' ' << spot[i].second << '\n';
    }

    return 0;
}