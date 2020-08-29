#include <cstdio>
#include <vector>
using namespace std;

int t, n, m, p, h, a, b;
vector<int> citizens, happies, travels, parent;
vector<vector<int>> G;

void dfs(int x) {
    travels[x] = citizens[x];
    for (int child : G[x]) {
        if (parent[child] == 0) {
            parent[child] = x;
            dfs(child);
            travels[x] += travels[child];
        }
    }
}

int g(int x) {
    return (travels[x] + happies[x]) / 2;
}

int sum_child(int x) {
    int sum = 0;
    for (int child : G[x]) {
        if (parent[child] == x) {
            sum += g(child);
        }
    }
    return sum;
}

void solve() {
    citizens.clear();
    happies.clear();
    G.clear();
    
    scanf("%d%d", &n, &m);
    citizens.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p);
        citizens.emplace_back(p);
    }
    happies.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);
        happies.emplace_back(h);
    }
    G = vector<vector<int>>(n+1);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d", &a, &b);
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }
    parent = vector<int>(n+1);
    travels = vector<int>(n+1);
    parent[1] = -1;
    dfs(1);

    for (int i = 1; i <= n; ++i) {
        if (((travels[i] + happies[i]) % 2 != 0) || (-travels[i] > happies[i]) || (travels[i] < happies[i])) {
            printf("NO\n");
            return;
        }

        if (sum_child(i) > g(i)) {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

int main() {
    scanf("%d", &t);
    for (; t > 0; --t) {
        solve();
    }
}