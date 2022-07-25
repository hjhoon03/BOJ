#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int documents, index;
        cin >> documents >> index;

        vector<int> docs;
        vector<pair<int, int>> doc_index;

        for(int j = 0; j < documents; ++j) {
            int tmp;
            cin >> tmp;
            doc_index.push_back(pair(tmp, j));
            docs.push_back(tmp);
        }

        sort(doc_index.begin(), doc_index.end());

        int target = docs[index];
        int cnt = 0;
        int start_index = documents - 1;

        for(int j = documents - 1; target != doc_index[j].first; --j) {
            ++cnt;
            start_index = j;
        }

        for(int j = doc_index[start_index].second + 1; j != index; ++j) {
            if(docs[j] == target) ++ cnt;
            if(j == documents - 1) j = -1;
        }

        cout << ++cnt << '\n';
    }

    return 0;
}