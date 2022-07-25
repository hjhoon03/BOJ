#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        string tmp;
        cin >> tmp;

        reverse(tmp.begin(), tmp.end()); // 문자열을 뒤집는 함수. 두 파라미터 사이 글자를 모두 바꿈 (https://blockdmask.tistory.com/363)

        cout << tmp << '\n';
    }

    return 0;
}