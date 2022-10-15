// BOJ 11723
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string cmd;
    int num;
    set<int> s;
    set<int>::iterator iter;
    for(int i = 0; i < n; ++i) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> num;
            s.insert(num);
        } else if(cmd == "remove") {
            cin >> num;
            if((iter = s.find(num)) != s.end())
                s.erase(iter);
        } else if(cmd == "check") {
            cin >> num;
            if(s.end() == s.find(num))
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        } else if(cmd == "toggle") {
            cin >> num;
            if((iter = s.find(num)) == s.end())
                s.insert(num);
            else
                s.erase(iter);
        } else if(cmd == "all") {
            for(int j = 1; j <= 20; ++j) {
                s.insert(j);
            }
        } else if(cmd == "empty") {
            s.erase(s.begin(), s.end());
        }
    }

    return 0;
}