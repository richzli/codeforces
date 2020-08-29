#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

int n, m, e;
ll ans;
vector<int> a, b, c, d, f, g, h;

int main() {
    scanf("%d", &n);
    a = vector<int>(1);
    b = vector<int>(1);
    c = vector<int>(n+1);
    for (ll i = 0; i < n; ++i) {
        scanf("%d", &m);
        a.emplace_back(m);
    }
    for (ll i = 0; i < n; ++i) {
        scanf("%d", &m);
        b.emplace_back(m);
        ++c[m];
    }
    for (ll i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            if (a[i] >= 0) {
                d.emplace_back(i);
            } else {
                g.emplace_back(i);
            }
        }
    }
    while (!g.empty()) {
        e = g.back();
        g.pop_back();
        h.emplace_back(e);
        if (b[e] != -1) {
            --c[b[e]];
            if (c[b[e]] == 0) {
                if (a[b[e]] >= 0) {
                    d.emplace_back(b[e]);
                } else {
                    g.emplace_back(b[e]);
                }
            }
        }
    }

    ans = 0; 
    while (!d.empty()) {
        e = d.back();
        f.emplace_back(e);
        d.pop_back();
        ans += a[e];
        if (b[e] != -1) {
            a[b[e]] += a[e];
            --c[b[e]];
            if (c[b[e]] == 0) {
                if (a[b[e]] >= 0) {
                    d.emplace_back(b[e]);
                } else {
                    g.emplace_back(b[e]);
                }
            }
        }
        while (!g.empty()) {
            e = g.back();
            g.pop_back();
            h.emplace_back(e);
            if (b[e] != -1) {
                --c[b[e]];
                if (c[b[e]] == 0) {
                    if (a[b[e]] >= 0) {
                        d.emplace_back(b[e]);
                    } else {
                        g.emplace_back(b[e]);
                    }
                }
            }
        }
    }
    while (!h.empty()) {
        e = h.back();
        h.pop_back();
        f.emplace_back(e);
        ans += a[e];
    }
    printf("%lld\n", ans);
    for (ll i = 0; i < f.size(); ++i) {
        printf("%d ", f[i]);
    }
}