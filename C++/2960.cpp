#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int i = 2; i <= n; ++i) {
        v.emplace_back(1);
    }

    int now = 2;
    int multi = 2;

    for(int i = 0; i < m; ++i) {
        if(now <= n) {
            if (v[now - 2]) {
                v[now - 2] = 0;
            } else {
                --i;
            }
        } else {
            int go = 0;
            while(v[go] == 0)
                ++go;

            now = go + 2;
            v[now - 2] = 0;
            multi = now;
        }

        now += multi;
    }

    cout << now - multi;

    return 0;
}