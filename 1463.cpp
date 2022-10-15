// BOJ 1463
#include <iostream>

using namespace std;

int arr[1000001] = {0, 1, };

int solve(int n) {
    int find = 0;
    int possible[2];
    int min;

    if(arr[n])
        return arr[n];

    if(arr[n - 1])
        min = arr[n - 1];
    else
        min = solve(n - 1);

    if(!(n % 3)) {
        if(!arr[n / 3])
            possible[find] = arr[n / 3];
        else
            possible[find] = solve(n / 3);

        ++find;
    }

    if(!(n % 2)) {
        if(!arr[n / 2])
            possible[find] = arr[n / 2];
        else
            possible[find] = solve(n / 2);

        ++find;
    }

    for(int i = 0; i < find; ++i) {
        if(possible[i] < min)
            min = possible[i];
    }

    arr[n] = min + 1;
    return min + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << solve(n) - 1;

    return 0;
}