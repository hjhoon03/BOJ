// BOJ 11279
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unsigned int num;
    priority_queue<unsigned int> pq;
    for(int i = 0; i < n; ++i) {
        cin >> num;

        if(num) {
            pq.push(num);
        } else {
            if(pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}