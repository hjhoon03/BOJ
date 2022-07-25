#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> block_tmp;

void find_block(int, int, int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> block(n, vector<int>(n));
    int high = 0, height;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> height;

            if(high < height)
                high = height;

            block[i][j] = height;
        }
    }
    
    int max = 0, cnt = 0;
    
    for(int i = 0; i < high; ++i) {
        block_tmp = block;
        cnt = 0;
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(block_tmp[j][k] > i) {
                    find_block(n, i, j, k);
                    ++cnt;
                }
            }
        }
        if(max < cnt)
            max = cnt;
    }
    
    cout << max;
    
    return 0;
}

void find_block(int n, int h, int y, int x) {
    if(x + 1 < n && block_tmp[y][x + 1] > h) {
        block_tmp[y][x + 1] = 0;
        find_block(n, h, y, x + 1);
    }
    if(x - 1 >= 0 && block_tmp[y][x - 1] > h) {
        block_tmp[y][x - 1] = 0;
        find_block(n, h, y, x - 1);
    }
    if(y + 1 < n && block_tmp[y + 1][x] > h) {
        block_tmp[y + 1][x] = 0;
        find_block(n, h, y + 1, x);
    }
    if(y - 1 >= 0 && block_tmp[y - 1][x] > h) {
        block_tmp[y - 1][x] = 0;
        find_block(n, h, y - 1, x);
    }
}