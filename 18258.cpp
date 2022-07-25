#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;

    for(int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;

        if(tmp[0] == 'p') {
            if(tmp[1] == 'u'){
                int numtmp;
                cin >> numtmp;

                q.push(numtmp);
            }
            else if(tmp[1] == 'o') {
                if(q.empty()) cout << -1 << '\n';
                else {
                    cout << q.front() << '\n';
                    q.pop();
                }
            }
        }

        else if(tmp[0] == 's') cout << q.size() << '\n';
        else if(tmp[0] == 'e') cout << q.empty() << '\n';
        else if(tmp[0] == 'f') {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(tmp[0] == 'b') {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}