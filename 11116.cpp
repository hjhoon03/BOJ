#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int left_01;
    int left_02;
    int right_01;
    int right_02;
} car;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        int cnt = 0;
        int m;
        cin >> m;

        vector<car> v(m);

        for(int j = 0; j < (m / 2); j ++) {
            cin >> v[j].left_01 >> v[j].left_02;
        }
        for(int j = 0; j < (m / 2); j ++) {
            cin >> v[j].right_01 >> v[j].right_02;

        }

        for(int j = 0; j < (m / 2); j ++) {
            if(v[j].left_01 < v[j].right_01 && v[j].left_02 < v[j].right_02) cnt ++;
        }

        cout << cnt << '\n';
    }

    return 0;
}