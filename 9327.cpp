// BOJ 9327
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, m, t1, t2;
    for(int i = 0; i < t; ++i) {
        cin >> n >> m;
        cout << n - 1 << '\n';

        for(int j = 0; j < m; ++j) {
            cin >> t1 >> t2;
        }
    }

    return 0;
}