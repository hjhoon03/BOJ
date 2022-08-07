// BOJ 1747
#include <iostream>

using namespace std;

long long int is_pal(long long int);
bool is_prime(long long int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;
    --n;

    while(++n) {
        if((n == is_pal(n)) && is_prime(n)) {
            cout << n;
            return 0;
        }
    }
}

long long int is_pal(long long int n) {
    long long int result = 0;

    while(n) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }

    return result;
}

bool is_prime(long long int n) {
    if(n == 1)
        return false;

    for(long long int i = 2; i < n; ++i) {
        if(n % i == 0)
            return false;
    }

    return true;
}