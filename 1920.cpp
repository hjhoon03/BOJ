#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i ++) cin >> v[i];

    sort(v.begin(), v.end());

    cin >> m;

    for(int i = 0; i < m; i ++) {
        int tmp, low = 0, high = n - 1, flag = 0;
        cin >> tmp;

        while(low <= high && flag == 0) {
            int index = (low + high) / 2;

            if(v[index] < tmp) low = index + 1;
            else if(v[index] > tmp) high = index - 1;
            else flag = 1;
        }

        cout << flag << '\n';
    }

    return 0;
}