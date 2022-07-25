#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt_2 = 0;
    int cnt_5 = 0;

    for(int i = 1; i <= n; ++i) {
        int tmp = i;
        while(!(tmp % 5)) {
            ++cnt_5;
            tmp /= 5;
        }
        while(!(tmp % 2)) {
            ++cnt_2;
            tmp /= 2;
        }
    }

    if(cnt_2 < cnt_5) cout << cnt_2;
    else cout << cnt_5;

    return 0;
}