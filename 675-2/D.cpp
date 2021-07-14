#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>

int n, m, sx, sy, fx, fy, x, y;
vi dist;
vvi points;
vvii graph;

auto cmp = [](ii a, ii b) { return (a.second > b.second); };
priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &fx, &fy);
    
    graph = vvii(m+2);
    dist = vi(m+2, -1);
    
    vi p;
    for (int i = 2; i < m + 2; ++i) {
        scanf("%d%d", &x, &y);
        p = {i, x, y};
        points.emplace_back(p);
    }

    sort(points.begin(), points.end(), [](vi a, vi b) { return a[1] < b[1]; });
    for (int i = 0; i < m-1; ++i) {
        vi &a = points[i];
        vi &b = points[i+1];
        
        graph[a[0]].emplace_back(ii(b[0], b[1]-a[1]));
        graph[b[0]].emplace_back(ii(a[0], b[1]-a[1]));
    }

    sort(points.begin(), points.end(), [](vi a, vi b) { return a[2] < b[2]; });
    for (int i = 0; i < m-1; ++i) {
        vi &a = points[i];
        vi &b = points[i+1];

        graph[a[0]].emplace_back(ii(b[0], b[2]-a[2]));
        graph[b[0]].emplace_back(ii(a[0], b[2]-a[2]));
    }

    for (int i = 0; i < m; ++i) {
        vi &a = points[i];

        graph[a[0]].emplace_back(ii(1, abs(a[1]-fx) + abs(a[2]-fy)));
        graph[0].emplace_back(ii(a[0], min(abs(a[1]-sx), abs(a[2]-sy))));
    }
    graph[0].emplace_back(ii(1, abs(fx-sx) + abs(fy-sy)));

    pq.push(ii(0, 0));
    while (dist[1] == -1 && pq.size() > 0) {
        ii next = pq.top(); pq.pop();
        //printf("%d %d\n", next.first, next.second);
        if (dist[next.first] == -1) {
            dist[next.first] = next.second;
            for (ii nei : graph[next.first]) {
                if (dist[nei.first] == -1) {
                    //printf(":%d %d\n", nei.first, next.second + nei.second);
                    pq.push(ii(nei.first, next.second + nei.second));
                }
            }
        }
    }

    printf("%d", dist[1]);
}