#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int t, n, a, b, da, db, u, v;
vector<vector<int>> g;
vector<int> d;
queue<int> bfs;

int max(int A, int B) {
    return A > B ? A : B;
}

int dfs(int node) {
    for (int k : g[node]) {
        if (d[k] == 0) {
            d[k] = d[node] + 1;
            dfs(k);
        }
    }
}

int main() {
    scanf("%d", &t);
    for (; t > 0; --t) {
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        g.clear();
        g = vector<vector<int>>(n+1, vector<int>(0));        
        for (int i = 0; i < n-1; ++i) {
            scanf("%d%d", &u, &v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        bfs = queue<int>();
        bfs.push(1);
        d = vector<int>(n+1, 0);
        d[1] = 1;
        int mx = 1, mxn = 1;

        while (!bfs.empty()) {
            int curr = bfs.front();
            bfs.pop();

            for (int nxt : g[curr]) {
                if (d[nxt] == 0) {
                    d[nxt] = d[curr] + 1;
                    if (d[nxt] > mx) {
                        mx = d[nxt];
                        mxn = nxt;
                    }
                    bfs.push(nxt);
                }
            }
        }

        bfs = queue<int>();
        bfs.push(mxn);
        d = vector<int>(n+1, 0);
        d[mxn] = 1;
        mx = 1;

        while (!bfs.empty()) {
            int curr = bfs.front();
            bfs.pop();

            for (int nxt : g[curr]) {
                if (d[nxt] == 0) {
                    d[nxt] = d[curr] + 1;
                    if (d[nxt] > mx) {
                        mx = d[nxt];
                        mxn = nxt;
                    }
                    bfs.push(nxt);
                }
            }
        }

        d = vector<int>(n+1, 0);
        d[a] = 1;
        dfs(a);
        if (2*da + 1 > db || d[b] - 1 <= da) {
            printf("Alice\n");
        } else {
            if (mx-1 > 2*da) {
                printf("Bob\n");
            } else {
                printf("Alice\n");
            }
        }
    }
}