#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> raw_name;
vector<pair<string, int>> sort_name;

int search(string, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        raw_name.emplace_back(tmp);
        sort_name.emplace_back(make_pair(tmp, i + 1));
    }

    sort(sort_name.begin(), sort_name.end());

    for(int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        if('0' <= tmp[0] && tmp[0] <= '9') {
            int tmp_num = 0;
            for(int j = 0; tmp[j]; ++j) {
                tmp_num *= 10;
                tmp_num += (tmp[j] - '0');
            }

            cout << raw_name[tmp_num - 1] << '\n';
        } else {
            cout << search(tmp, n) << '\n';
        }
    }

    return 0;
}

int search(string tmp, int end) {
    int start = 0;

    while(start <= end) {
        int middle = (start + end) / 2;
        if(sort_name[middle].first < tmp) start = middle + 1;
        else if(sort_name[middle].first > tmp) end = middle - 1;
        else return sort_name[middle].second;
    }

    return -1;
}