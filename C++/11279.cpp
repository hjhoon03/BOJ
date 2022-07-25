#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;

        if(tmp) v.push_back(tmp);
        else {
            if(v.empty()) cout << '0' << '\n';
            else if(v.size() == 1) {
                cout << v[0] << '\n';
                v.pop_back();
            } else {
                int max_index = max_element(v.begin(), v.end()) - v.begin(); // vector의 요소 중 최대값의 index를 구한다 https://notepad96.tistory.com/40
                cout << v[max_index] << '\n';
                v.erase(v.begin() + max_index);
            }
        }
    }

    return 0;
}