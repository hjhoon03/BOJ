#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        deque<int> d;
        string command;
        cin >> command;

        int tmp_n;
        cin >> tmp_n;

        if (tmp_n) {
            for (int j = 0; j < tmp_n; j ++) {
                char trash;
                cin >> trash;

                int tmp;
                cin >> tmp;
                d.push_back(tmp);
            }

            for (int j = 0; j < 1; j ++) {
                char trash;
                cin >> trash;
            }
        } else {
            for(int j = 0; j < 2; j ++) {
                char trash;
                cin >> trash;
            }
        }

        int length = command.length();
        int flag = 0; // 0이면 앞, 1이면 뒤
        for(int j = 0; j < length; j ++) {
            if(command[j] == 'D') {
                if(d.size() == 0) {
                    flag = 2;
                    break;
                }
                else if(flag) d.pop_back();
                else d.pop_front();
            } else {
                if(flag) flag = 0;
                else flag = 1;
            }
        }

        if(flag == 2) {
            cout << "error" << '\n';
            continue;
        }

        int size = d.size();
        cout << '[';
        if(flag)
            for(int j = size - 1; j >= 0; j --) {
                cout << d[j];
                if(j) cout << ',';
            }
        else
            for (int j = 0; j < size; j++) {
                cout << d[j];
                if (j != size - 1) cout << ',';
            }
        cout << ']' << '\n';
    }

    return 0;
}