#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef pair<int, int> integer;

struct cmp {
    bool operator()(integer a, integer b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }

        return a.first > b.first;
    }
}; // priority queue의 우선순위를 정해주기 위한 구조체

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<integer, vector<integer>, cmp> q; // priority queue 선언

    integer num;
    for(int i = 0; i < n; ++i) {
        cin >> num.first;

        if(num.first == 0) {
            if(q.empty())
                cout << 0 << '\n';
            else {
                num = q.top();
                q.pop();

                if(num.second == 0) {
                    cout << -num.first << '\n';
                } else {
                    cout << num.first << '\n';
                }
            }
        } else {
            if (num.first < 0)
                num.second = 0;
            else
                num.second = 1;

            num.first = abs(num.first);

            q.push(num);
        }
    }

    return 0;
}