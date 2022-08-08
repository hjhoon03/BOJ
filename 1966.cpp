// BOJ 1966
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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

    vector<int> priority(n);
    queue<pair<int, bool>> printer;

    for(int i = 0; i < n; ++i) {
        cin >> priority[i];
        if(i == m)
            printer.push(make_pair(priority[i], true));
        else
            printer.push(make_pair(priority[i], false));
    }

    sort(priority.begin(), priority.end());

    int cnt = 1, now;
    bool flag;
    for(int i = n - 1; i >= 0; --i) {
        now = priority[i];
        flag = true;
        while(flag) {
            if(printer.front().first == now) {
                if(printer.front().second)
                    return cnt;
                else {
                    printer.pop();
                    ++cnt;
                    flag = false;
                }
            } else {
                printer.push(printer.front());
                printer.pop();
            }
        }
    }
}