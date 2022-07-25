#include <iostream>
#include <stack>

using namespace std;

stack<char> braces;

int bracecheck(int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int cnt = 0;
        int flag = 1;
        int check = 1;

        while (1) {
            char tmp;
            scanf("%c", &tmp);

            if (tmp == '.') break;
            else if (tmp == '\n') continue;
            else if (tmp == '(') braces.push('(');
            else if (tmp == '{') braces.push('{');
            else if (tmp == '[') braces.push('[');
            else if (tmp == ')') flag = bracecheck(1);
            else if (tmp == '}') flag = bracecheck(2);
            else if (tmp == ']') flag = bracecheck(3);

            cnt ++;

            if(flag == 0) check = 0;
        }

        if(cnt == 0) break;

        if(check && braces.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';

        while(braces.size()) braces.pop();
    }

    return 0;
}

int bracecheck(int br) {
    if(braces.empty()) return 0;

    if(br == 1) {
        if(braces.top() == '(') {
            braces.pop();
            return 1;
        } else return 0;
    } else if(br == 2) {
        if(braces.top() == '{') {
            braces.pop();
            return 1;
        } else return 0;
    } else {
        if(braces.top() == '[') {
            braces.pop();
            return 1;
        } else return 0;
    }
}