#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int>> card;

int search(int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        card.push_back(make_pair(tmp, 1));
    }

    sort(card.begin(), card.end());

    card.push_back(make_pair(100000000, 1));

    int cnt = 0, i = 0;
    while(i + cnt < n) {
        if(card[i].first == card[i + (cnt + 1)].first) {
            cnt ++;
        } else {
            for(int j = 0; j <= cnt; j ++) card[i + j].second += cnt;
            i += (cnt + 1);
            cnt = 0;
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i ++) {
        int tmp;
        cin >> tmp;

        int index = search(tmp, n);

        if(index < 0) cout << 0 << ' ';
        else cout << card[index].second << ' ';
    }
    return 0;
}

int search(int hs, int end) {
    int i = 0, j = end;
    while(i <= j) {
        int middle = (i + j) / 2;
        int kwayeon = card[middle].first;
        if(kwayeon < hs) i = middle + 1;
        else if(kwayeon > hs) j = middle - 1;
        else return middle;
    }
    return -1;
}