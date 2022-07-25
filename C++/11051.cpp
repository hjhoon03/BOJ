#include <iostream>

using namespace std;

int fibo_list[1000][1000];

int fibo(int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << fibo(n, k);

    return 0;
}

int fibo(int n, int k) {
    if(fibo_list[n][k])
        return fibo_list[n][k];

    if(k == 0 || n == k) {
        fibo_list[n][k] = 1;
        return 1;
    }

    fibo_list[n][k] = (fibo(n - 1, k) + fibo(n - 1, k - 1)) % 10007;
    return fibo_list[n][k];
}