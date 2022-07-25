#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 800
#define INF 2000000000

typedef pair<int, int> pii;

vector<pii> graph[MAX];

int dijkstra(int, int);

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int e;
    cin >> n >> e;

    int n1, n2, c;
    for(int i = 0; i < e; ++i) {
        cin >> n1 >> n2 >> c;

        graph[n1 - 1].emplace_back(make_pair(n2 - 1, c));
        graph[n2 - 1].emplace_back(make_pair(n1 - 1, c));
    }

    int e1, e2;
    cin >> e1 >> e2;
    --e1;
    --e2;

    int e1_c = dijkstra(0, e1);
    int e2_c = dijkstra(0, e2);
    int btw_e = dijkstra(e1, e2);

    if(e1_c != -1) {
        int tmp = dijkstra(e2, n - 1);

        if(tmp != -1)
            e1_c += tmp;
        else
            e1_c = -1;
    }

    if(e2_c != -1) {
        int tmp = dijkstra(e1, n - 1);

        if(tmp != -1)
            e2_c += tmp;
        else
            e2_c = -1;
    }

    if(e1_c == -1 && e2_c == -1)
        cout << -1;
    else if(e1_c == -1)
        cout << btw_e + e2_c;
    else if(e2_c == -1)
        cout << btw_e + e1_c;
    else if(e1_c < e2_c)
        cout << btw_e + e1_c;
    else
        cout << btw_e + e2_c;

    return 0;
}

int dijkstra(int s, int f) {
    priority_queue<pii> pq;
    vector<int> cost(n, INF);

    cost[s] = 0;
    pq.push(make_pair(0, s));

    // 우선순위 큐는 내림차순 정렬 되기 때문에 cost를 음수화 시켜 절댓값 오름차순 되게 만들었다. https://yabmoons.tistory.com/386

    int now, next, c, ced;
    while(pq.empty() == 0) {
        now = pq.top().second;
        ced = -pq.top().first;

        if(now == f)
            return ced;

        for(int i = 0; i < graph[now].size(); ++i) {
            next = graph[now][i].first;
            c = graph[now][i].second + ced;

            if(cost[next] > c) {
                cost[next] = c;
                pq.push(make_pair(-c, next));
            }
        }

        pq.pop();
    }

    return -1;
}