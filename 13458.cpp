#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> room(n);

    for(int i = 0; i < n; ++i) {
        cin >> room[i];
    }

    int b, c;
    cin >> b >> c;

    long long int cnt = n;
    for(int i = 0; i < n; ++i) {
        room[i] -= b;
        if(room[i] > 0) {
            if(room[i] % c != 0)
                ++cnt;

            cnt += room[i] / c;
        }
    }

    cout << cnt;

    return 0;
}