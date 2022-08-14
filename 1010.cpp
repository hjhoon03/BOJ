// BOJ 1010
#include <iostream>

using namespace std;

int solve();
int comb(int, int);

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        cout << solve() << '\n';
    }

    return 0;
}

int solve() {
    int n, m;
    cin >> n >> m;

    return comb(m, n);
}

int comb(int m, int n) {
    int result = 1;
    for(int i = 1; i <= n; ++i, --m) {
        result *= m;
        result /= i;
    }

    return result;
}