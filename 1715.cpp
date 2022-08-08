// BOJ 1715
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> cards;

    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        cards.push(-tmp);
    }

    int c1, c2, result, sum = 0;
    for(int i = 0; i < n - 1; ++i) {
        c1 = -cards.top();
        cards.pop();
        c2 = -cards.top();
        cards.pop();
        result = c1 + c2;
        sum += result;
        cards.push(-result);
    }

    cout << sum;

    return 0;
}