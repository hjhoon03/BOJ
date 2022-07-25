#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    short check[100001] = {0};

    check[n] = 1;

    int num;
    while(1) {
        num = q.front() + 1;
        if (0 <= num && num <= 100000 && check[num] == 0) {
            q.push(num);
            check[num] = check[q.front()] + 1;
            if (q.front() == m)
                break;
        }

        num = q.front() - 1;
        if (0 <= num && num <= 100000 && check[num] == 0) {
            q.push(num);
            check[num] = check[q.front()] + 1;
            if (q.front() == m)
                break;
        }

        num = q.front() * 2;
        if (0 <= num && num <= 100000 && check[num] == 0) {
            q.push(q.front() * 2);
            check[num] = check[q.front()] + 1;
            if (q.front() == m)
                break;
        }

        q.pop();
    }

    cout << check[m] - 1;

    return 0;
}