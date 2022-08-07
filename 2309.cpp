// BOJ 2309
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int height[9];
    int result[9];
    int sum;
    for(int i = 0; i < 9; ++i) {
        cin >> height[i];
    }

    bool find = false;
    for(int i = 0; i < 8 && !find; ++i) {
        for(int j = i + 1; j < 9; ++j) {
            if(i == j)
                continue;

            sum = 0;
            for(int k = 0; k < 9; ++k) {
                if(k == i || k == j)
                    continue;

                sum += height[k];
            }

            if(sum == 100) {
                for(int k = 0; k < 9; ++k) {
                    if(k == i || k == j) {
                        result[k] = 0;
                        continue;
                    }

                    result[k] = height[k];
                }
                find = true;
                break;
            }
        }
    }

    sort(result, result + 9);

    for(int i = 2; i < 9; ++i)
        cout << result[i] << '\n';

    return 0;
}