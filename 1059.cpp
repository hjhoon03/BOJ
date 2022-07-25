#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num, index = -1;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i ++) cin >> v[i];

    cin >> num;

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i ++) {
        if(v[i] == num) {
            cout << 0;
            return 0;
        } else if(v[i] > num) {
            index = i;
            break;
        }
    }

    if(v[index] - v[index - 1] == 2) cout << 0;
    else cout << (num - v[index - 1]) * (v[index] - num) - 1;

    return 0;
}