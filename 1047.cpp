// BOJ 1047
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> money(n);
    for(int i = 0; i < n; ++i) {
        cin >> money[i];
    }

    int cnt = 0;
    int tmp;
    for(int i = n - 1; i >= 0; --i) {
        tmp = k / money[i];
        k -= tmp * money[i];
        cnt += tmp;

        if(!k)
            break;
    }

    cout << cnt;

    return 0;
}