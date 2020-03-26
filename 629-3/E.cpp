#include <cstdio>
#include <set>
#include <vector>
using namespace std;

#define MAXN 200001

vector<set<int>> adj(MAXN, set<int>());
vector<int> tree(MAXN, -1);
vector<int> depth(MAXN);

void dfs(int curr, int prev, int d) {
    depth.at(curr) = d;
    for (int next : adj.at(curr)) {
        if (next != prev) {
            tree.at(next) = curr;
            dfs(next, curr, d + 1);
        }
    }
}

bool search(int curr, set<int> &query, vector<int> &ds) {
    if (curr == -1) {
        return false;
    }

    if (depth.at(curr) < ((int) (ds.size())-2)) {
        return false;
    }

    int e = query.erase(curr);
    if (e == 1) {
        --ds.at(depth.at(curr));
    }
    
    for (int next : adj.at(curr)) {
        e = query.erase(next);
        if (e == 1) {
            --ds.at(depth.at(next));
        }
    }

    while (!ds.empty() && ds.at(ds.size()-1) == 0) {
        ds.pop_back();
    }

    if (query.empty()) {
        return true;
    } else {
        return search(tree.at(curr), query, ds);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (; n > 1; --n) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj.at(u).insert(v);
        adj.at(v).insert(u);
    }

    dfs(1, -1, 0);
    
    
    for (; m > 0; --m) {
        int md = -1;
        int mdi = -1;
        set<int> query;
        int k;
        vector<int> ds(MAXN, 0);
        scanf("%d", &k);

        for (; k > 0; --k) {
            int q;
            scanf("%d", &q);

            if (depth.at(q) > md) {
                md = depth.at(q);
                mdi = q;
            }

            query.insert(q);
            ++ds.at(depth.at(q));
        }

        while (ds.at(ds.size()-1) == 0) {
            ds.pop_back();
        }

        printf(search(mdi, query, ds) ? "YES\n" : "NO\n");
    }
}