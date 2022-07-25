#include <iostream>

using namespace std;

void run_test_case();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        run_test_case();

    return 0;
}

void run_test_case() {
    int n;
    cin >> n;

    int arr[10000] = {0};
    int check[10000] = {0};

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int now = 1;
    check[0] = 1;
    int cnt = 0;

    while(now != n) {
        now = arr[now - 1];

        if(check[now - 1] == 1) {
            cout << 0 << '\n';
            return;
        }

        check[now - 1] = 1;
        ++cnt;
    }

    cout << cnt << '\n';
}
