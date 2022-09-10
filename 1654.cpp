//BOJ 1654
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int cal(int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    long long int sum = 0;
    for(int i = 0; i < k; ++i) {
        v.emplace_back();
        cin >> v[i];
        sum += v[i];
    }

    long long int i = 1;
    long long int j = sum / n;
    int check;
    while(i <= j) {
        if((check = cal((i + j) / 2)) >= n) {
            i = (i + j) / 2 + 1;
        }
        else {
            j = (i + j) / 2 - 1;
        }
    }

    cout << (i + j) / 2;

    return 0;
}

int cal(int n) {
    int result = 0;

    for(int i = 0; i < v.size(); ++i) {
        result += (v[i] / n);
    }

    return result;
}