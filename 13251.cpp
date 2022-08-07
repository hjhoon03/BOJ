// BOJ 13251
#include <iostream>
#include <vector>

using namespace std;

double comb(double, double);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> v(n);
    double sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    double k;
    cin >> k;

    double suc_case = 0;
    for(int i = 0; i < n; ++i) {
        suc_case += comb(v[i], k);
    }

    cout << fixed;
    cout.precision(10);
    cout << suc_case / comb(sum, k);

    return 0;
}

double comb(double a, double b) {
    double result = 1;
    while(b) {
        result *= a;
        result /= b;

        b -= 1;
        a -= 1;
    }

    return result;
}

