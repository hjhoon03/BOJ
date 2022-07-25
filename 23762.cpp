#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int left_num = n % 4;

    vector<pair<int, int>> player;

    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        player.emplace_back(tmp, i);
    }

    sort(player.begin(), player.end());

    vector<int> dif;
    vector<int> idx_remain;

    for(int i = 0; i < n - 1; ++i)
        dif.emplace_back(player[i + 1].first - player[i].first);

}

bool compare(int a, int b) {
    return a < b;
}