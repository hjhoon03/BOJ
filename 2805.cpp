//BOJ 2805
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    int max = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        if(max < v[i])
            max = v[i];
    }

    int i = 1;
    int j = max;
    int h;
    long long int res;
    while(i <= j) {
        h = (i + j) / 2;
        res = 0;
        for(int k = 0; k < n; ++k) {
            if(v[k] - h < 0)
                continue;

            res += (v[k] - h);
        }
        if(res >= m)
            i = (i + j) / 2 + 1;
        else
            j = (i + j) / 2 - 1;
    }

    cout << (i + j) / 2;

    return 0;
}