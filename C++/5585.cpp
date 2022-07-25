#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pay;
    cin >> pay;

    pay = 1000 - pay;

    int change[6] = {500, 100, 50, 10, 5, 1};
    int result = 0;

    for(int i = 0; i < 6; ++i) {
        result += pay / change[i];
        pay %= change[i];
    }

    cout << result;

    return 0;
}