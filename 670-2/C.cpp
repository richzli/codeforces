#include <cstdio>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

int t, n, x, y, c1, c2, m, d1;
vvi tree;
vi size, parent;

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int N) {
    int total = 1;
    for (int child : tree[N]) {
        if (child != parent[N] && child != c2) {
            parent[child] = N;
            total += dfs(child);
        }
    }
    size[N] = total;
    return total;
}

int dfs2(int N) {
    for (int child : tree[N]) {
        if (child != parent[N] && child != c1) {
            parent[child] = N;
            return dfs2(child);
        }
    }
    return N;
}

int main() {
    scanf("%d", &t);
    for (; t>0; --t) {
        scanf("%d", &n);
        ++n;
        tree = vvi(n, vi());
        size = vi(n);
        parent = vi(n);

        for (int i = 1; i < n-1; ++i) {
            scanf("%d%d", &x, &y);
            tree[x].emplace_back(y);
            tree[y].emplace_back(x);
        }

        c1 = -1;
        c2 = -1;
        parent[1] = -1;
        dfs(1);
        
        m = __INT_MAX__; c1 = -1; c2 = -1;
        for (int i = 1; i < n; ++i) {
            int MM = size[1] - size[i];
            for (int child : tree[i]) {
                if (child != parent[i]) {
                    MM = max(MM, size[child]);
                }
            }
            if (MM < m) {
                m = MM;
                c1 = i;
                c2 = -1;
            } else if (MM == m) {
                c2 = i;
            }
        }

        if (c2 != -1) {
            parent = vi(n);
            parent[c1] = c2;
            d1 = dfs2(c1);
            printf("%d %d\n%d %d\n", d1, parent[d1], d1, c2);
        } else {
            c2 = tree[c1][0];
            printf("%d %d\n%d %d\n", c1, c2, c1, c2);
        }
    }
}