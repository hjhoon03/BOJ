// 17952
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int assign_info, a, t;
    stack<pair<int, int>> s;
    int score = 0;

    for(int i = 0; i < n; ++i) {
        cin >> assign_info;

        if(assign_info) {
            cin >> a >> t;

            s.push(make_pair(a, t - 1));
        } else {
            if(!s.empty())
                --s.top().second;
        }

        if(!s.empty() && !s.top().second) {
            score += s.top().first;
            s.pop();
        }
    }

    cout << score;

    return 0;
}