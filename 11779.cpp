// BOJ 11779
#include <iostream>
#include <queue>
#include <vector>
#include <deque>

using namespace std;

typedef int COST;
typedef int CITY_NAME;
typedef deque<CITY_NAME> PATH;

class CITY {
public:
    COST cost = 2000000000;
    vector<pair<CITY_NAME, COST>> linked_city;
    PATH path;
};

CITY graph[1000];
bool check[1000];

struct cmp {
    bool operator()(CITY_NAME a, CITY_NAME b) {
        return graph[a].cost > graph[b].cost;
    }
};

PATH make_path(CITY_NAME, PATH);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    CITY_NAME c1, c2;
    COST c;
    for(int i = 0; i < m; ++i) {
        cin >> c1 >> c2 >> c;
        graph[c1 - 1].linked_city.emplace_back(make_pair(c2 - 1, c));
    }

    CITY_NAME start, end;
    cin >> start >> end;

    --start;
    --end;

    graph[start].cost = 0;
    graph[start].path.emplace_back(start);
    priority_queue<CITY_NAME, vector<CITY_NAME>, cmp> pq;
    check[start] = true;
    pq.push(start);

    for(CITY_NAME now = start; now != end; now = pq.top()) {
        for(int i = 0; i < graph[now].linked_city.size(); ++i) {
            CITY_NAME next = graph[now].linked_city[i].first;
            COST price = graph[now].cost + graph[now].linked_city[i].second;

            if(price < graph[next].cost) {
                graph[next].path = make_path(next, graph[now].path);
                graph[next].cost = price;
                if(!check[next]) {
                    pq.push(next);
                    check[next] = true;
                }
            }
        }

        check[now] = false;
        pq.pop();
    }

    PATH result = graph[pq.top()].path;
    int path_size = int(result.size());
    cout << graph[end].cost << '\n';
    cout << path_size << '\n';
    for(int i = 0; i < path_size; ++i) {
        cout << result.front() + 1 << ' ';
        result.pop_front();
    }

    return 0;
}

PATH make_path(CITY_NAME next, PATH p) {
    p.emplace_back(next);

    return p;
}