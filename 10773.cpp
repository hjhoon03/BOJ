#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> s;

    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;

        if(tmp) s.push(tmp);
        else s.pop();
    }

    n = s.size();
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}