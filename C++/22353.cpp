#include <iostream>

using namespace std;

void func(double*, double*, double*, double*, double, double);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, d, k, total = 0, total_a = 0, remain_d = 1;
    int cnt = 0;
    cin >> a >> d >> k;

    d /= 100;
    k /= 100;

    func(&total, &total_a, &remain_d, &d, a, k);

    total += (remain_d * (total_a + a));

    cout << fixed;
    cout.precision(7); // 소수점 자리 고정 https://semaph.tistory.com/7
    cout << total;
    
    return 0;
}

void func(double* total, double* total_a, double* remain_d, double* d, double a, double k) {
    if(*d >= 1)
        return;

    *total_a += a;
    *total += (*total_a * *remain_d * *d);
    *remain_d -= (*remain_d * *d);
    *d += (*d * k);

    func(total, total_a, remain_d, d, a, k);
}