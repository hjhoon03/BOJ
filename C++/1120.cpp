#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int len = a.length();
    int dif = b.length() - a.length();
    int min = len;

    for(int i = 0; i <= dif; i ++) {
        int cnt = 0;
        for(int j = 0; j < len; j ++)
            if(a[j] != b[i + j]) cnt ++;
        if(cnt < min) min = cnt;
    }

    cout << min;

    return 0;
}