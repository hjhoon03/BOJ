#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1 || n == 2) {
        cout << 1;
        return 0;
    }

    long long int num1 = 1, num2 = 1;
    long long int result;

    for(int i = 0; i < n - 2; i ++) {
        result = num1 + num2;

        if(i != n - 3) {
            num1 = num2;
            num2 = result;
        }
    }

    cout << result;

    return 0;
}