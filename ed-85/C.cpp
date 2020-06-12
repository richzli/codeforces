#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

int t, n, mhi;
ll a, b, total, mh;
vector<ll> health, explode;

ll min(ll a, ll b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d", &n);

        health.clear();
        explode.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%I64d%I64d", &a, &b);

            health.push_back(a);
            explode.push_back(b);
        }

        total = 0;
        mh = __LONG_LONG_MAX__;
        for (int i = 0; i < n; ++i) {
            ll m = min(explode.at(i), health.at((i+1)%n));
            total += health.at((i+1)%n) - m;
            if (m < mh) {
                mh = m;
            }
        }

        printf("%I64d\n", total + mh);
    }
}