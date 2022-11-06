// 9012
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    int cnt;
    bool flag;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        cnt = 0;
        flag = true;

        for(int j = 0; j < s.length(); ++j) {
            if(s[j] == '(')
                ++cnt;

            else {
                if(cnt)
                    --cnt;

                else {
                    flag = false;
                    break;
                }
            }
        }

        if(flag && cnt == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}