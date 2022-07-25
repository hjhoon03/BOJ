#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<double> ca_tmp;

double calcul(char);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string eq;
    cin >> eq;

    vector<double> num;

    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        num.emplace_back(tmp);
    }

    int length = eq.length();

    for(int i = 0; i < length; ++i) {
        if('A' <= eq[i] && eq[i] <= 'Z') ca_tmp.push(num[eq[i] - 'A']);
        else ca_tmp.push(calcul(eq[i]));
    }

    cout << fixed;
    cout.precision(2);
    cout << ca_tmp.top();

    return 0;

}

double calcul(char sign) {
    double num2 = ca_tmp.top();
    ca_tmp.pop();
    double num1 = ca_tmp.top();
    ca_tmp.pop();

    if(sign == '+') return num1 + num2;
    else if(sign == '-') return num1 - num2;
    else if(sign == '*') return num1 * num2;
    else return num1 / num2;
}

