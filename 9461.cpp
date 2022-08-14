// BOJ 9461
#include <iostream>

using namespace std;

long long int result[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };

long long int solve(int);

int main() {
    int t;
    cin >> t;

    int n;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}

long long int solve(int n) {
    if(result[n] != 0)
        return result[n];

    result[n] = solve(n - 1) + solve(n - 5);
    return result[n];
}