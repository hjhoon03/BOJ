#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> spot;

struct node {
    int value;
    spot s;
};

struct cmp {
    bool operator()(node n1, node n2) {
        return n1.value > n2.value;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    char maze[100][101] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    priority_queue<node, vector<node>, cmp> pq;
    int check[100][100] = {0};

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            check[i][j] = -1;
        }
    }

    check[0][0] = 0;
    node next;
    next.value = 0;
    next.s.first = 0;
    next.s.second = 0;
    pq.push(next);

    int check_value, sum;
    spot s;
    while(1) {
        check_value = pq.top().value;
        s = pq.top().s;

        if(s.first ==  n - 1 && s.second == m - 1) {
            cout << check_value;
            return 0;
        }

        if(s.first + 1 < n) {
            if(maze[s.first + 1][s.second] == '1')
                sum = check_value + 1;
            else
                sum = check_value;

            if(check[s.first + 1][s.second] == -1 || check[s.first + 1][s.second] > sum) {
                check[s.first + 1][s.second] = sum;
                next.value = sum;
                next.s.first = s.first + 1;
                next.s.second = s.second;
                pq.push(next);
            }
        }

        if(0 <= s.first - 1) {
            if (maze[s.first - 1][s.second] == '1')
                sum = check_value + 1;
            else
                sum = check_value;

            if (check[s.first - 1][s.second] == -1 || check[s.first - 1][s.second] > sum) {
                check[s.first - 1][s.second] = sum;
                next.value = sum;
                next.s.first = s.first - 1;
                next.s.second = s.second;
                pq.push(next);
            }
        }

        if(s.second + 1 < m) {
            if(maze[s.first][s.second + 1] == '1')
                sum = check_value + 1;
            else
                sum = check_value;

            if(check[s.first][s.second + 1] == -1 || check[s.first][s.second + 1] > sum) {
                check[s.first][s.second + 1] = sum;
                next.value = sum;
                next.s.first = s.first;
                next.s.second = s.second + 1;
                pq.push(next);
            }
        }

        if(0 <= s.second - 1) {
            if(maze[s.first][s.second - 1] == '1')
                sum = check_value + 1;
            else
                sum = check_value;

            if(check[s.first][s.second - 1] == -1 || check[s.first][s.second - 1] > sum) {
                check[s.first][s.second - 1] = sum;
                next.value = sum;
                next.s.first = s.first;
                next.s.second = s.second - 1;
                pq.push(next);
            }
        }

        pq.pop();
    }
}