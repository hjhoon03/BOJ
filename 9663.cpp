#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> board_copy;
    int spot[15][2] = {0, };


    int x = 1, y = 1;

    while(spot[0][0] < n) {
        for(int i = 0; i < n; ++i) {
            spot[i][0] = x;
            spot[i][1] = y;
        }
        
    }

    return 0;
}