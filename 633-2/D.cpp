#include <cstdio>
#include <set>
#include <vector>
using namespace std;

#define MAXN 100000 + 5

int n, a, b, ot = -1;
bool sl = false;
vector<bool> visited;
vector<set<int>> tree;

void dfs1(int node, int depth) {
    bool f = true;

    visited.at(node) = true;
    for (int nxt : tree.at(node)) {
        if (!visited.at(nxt)) {
            f = false;
            dfs1(nxt, depth + 1);
        }
    }

    if (f) {
        if (ot == -1) {
            ot = depth % 2;
        } else if (ot != depth % 2) {
            ot = 3;
        }
    }
}

int dfs2(int node, int bdepth, int parent) {
    bool f = true;
    bool k = false;
    int t = 0;

    if (bdepth == n-1) {
        sl = true;
    }

    visited.at(node) = true;
    for (int nxt : tree.at(node)) {
        if (!visited.at(nxt)) {
            f = false;
            int bd = 0;
            if (node == 1) {
                bd = 1;
            } else if (tree.at(node).size() > 2) {
                bd = 1;
            } else {
                bd = bdepth + 1;
            }
            int m = dfs2(nxt, bd, node);
            if (m == 1 && !k) {
                k = true;
                t += 1;
            } else if (m != 1) {
                t += m;
            }
        }
    }

    //printf("+%d %d %d\n", node, f, t);

    if (parent == 1) {
        if (bdepth == 1) {
            if (tree.at(1).size() == 1 && k) {
                return t;
            }
        }
    }

    if (f) {
        return 1;
    } else {
        return t + 1;
    }
}

int main() {
    scanf("%d", &n);

    visited = vector<bool>(n+1);
    tree = vector<set<int>>(n+1);

    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);

        tree.at(a).insert(b);
        tree.at(b).insert(a);
    }

    dfs1(1, 0);
    visited = vector<bool>(n+1);
    int ans = dfs2(1, 0, -1) - 1;

    if (ot == 3 || (ot == 1 && sl)) {
        printf("3 ");
    } else {
        printf("1 ");
    }

    printf("%d\n", ans);
}