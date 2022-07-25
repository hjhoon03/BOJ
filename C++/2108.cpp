#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int check[8001] = {0};

    int tmp;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
        ++check[tmp + 4000];
    }

    if(round((double)sum / n) == 0)
        cout << 0 << '\n';
    else
        cout << round((double)sum / n) << '\n';

    int min = 8001, max = -1, mid, cnt = 0;
    pair<int, double> many = make_pair(0, 0);

    int flag = 1;

    for(int i = 0; i < 8001; ++i) {
        if(check[i]) {
            if(i < min)
                min = i;

            if(i > max)
                max = i;

            if(flag && (cnt + check[i]) > (n / 2)) {
                mid = i;
                flag = 0;
            }

            if(many.second < check[i]) {
                many.first = i;
                many.second = check[i];
            } else if(many.second == check[i]) {
                many.first = i;
                many.second = (double)check[i] + 0.5;
            }

            cnt += check[i];
        }
    }

    cout << mid - 4000 << '\n';
    cout << many.first - 4000 << '\n';
    cout << max - min;

    return 0;
}