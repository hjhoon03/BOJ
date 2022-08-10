// BOJ 14564
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    cin >> n >> m >> a;

    deque<int> circle;
    for(int i = 0; i < n; ++i) {
        circle.emplace_back(a);

        ++a;
        if(a > n)
            a %= n;
    }

    int std = m / 2 + 1;
    int tofu;
    while(1) {
        cin >> tofu;
        if(tofu == std) {
            cout << 0;
            return 0;
        }

        if(tofu > std) {
            for(int i = 0; i < tofu - std; ++i) {
                circle.emplace_back(circle.front());
                circle.pop_front();
            }
        } else {
            for(int i = 0; i < std - tofu; ++i) {
                circle.emplace_front(circle.back());
                circle.pop_back();
            }
        }

        cout << circle.front() << '\n';
    }
}