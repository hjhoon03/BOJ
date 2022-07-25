#include <iostream>
#include <stack>

using namespace std;

stack<string> num;
stack<string> op;

void put();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string eq_tmp;
    cin >> eq_tmp;

    int eq_len = eq_tmp.length();

    char eq[100][2] = {0};
    for(int i = 0; i < eq_len; ++i) {
        eq[i][0] = eq_tmp[i];
    }

    for(int i = 0; i < eq_len; ++i) {
        if('A' <= eq[i][0] && eq[i][0] <= 'Z') {
            num.push(eq[i]);
            continue;
        }

        if(op.empty() || eq[i][0] == '(') {
            op.push(eq[i]);
            continue;
        }

        if(eq[i][0] == '*' || eq[i][0] == '/') {
            if(op.top()[0] == '*' || op.top()[0] == '/')
                put();

            op.push(eq[i]);
            continue;
        }

        if((eq[i][0] == '+' || eq[i][0] == '-')) {
            while(op.empty() == 0) {
                if(op.top()[0] == '(')
                    break;

                put();
            }

            op.push(eq[i]);
            continue;
        }

        if(eq[i][0] == ')') {
            while(op.top()[0] != '(')
                put();

            op.pop();
            continue;
        }
    }

    while(op.empty() == 0) {
        put();
    }

    cout << num.top();
    num.pop();

    return 0;
}

void put() {
    stack<string> num_tmp;
    num_tmp.push(op.top());
    op.pop();
    num_tmp.push(num.top());
    num.pop();
    num_tmp.push(num.top());
    num.pop();

    string tmp = num_tmp.top();
    num_tmp.pop();
    tmp += num_tmp.top();
    num_tmp.pop();
    tmp += num_tmp.top();
    num_tmp.pop();

    num.push(tmp);
}