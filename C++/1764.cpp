#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v1;
vector<string> v2;

bool binary_search(string);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }

    for(int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }

    sort(v2.begin(), v2.end());

    vector<string> result;

    for(int i = 0; i < n; ++i) if(binary_search(v1[i])) result.push_back(v1[i]);

    sort(result.begin(), result. end());

    n = result.size();

    cout << n << '\n';

    for(int i = 0; i < n; ++i) cout << result[i] << '\n';

    return 0;
}

bool binary_search(string tmp) {
    int start = 0;
    int end = v2.size() - 1;

    while(start <= end) {
        int middle = (start + end) / 2;
        if(tmp == v2[middle]) return true;
        else if(tmp < v2[middle]) end = middle - 1;
        else if(tmp > v2[middle]) start = middle + 1;
    }

    return false;
}