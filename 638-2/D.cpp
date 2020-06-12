#include <cstdio>
#include <vector>
#include <list>
using namespace std;

#define MAXN ((int) (1e9+5))

int t, n, c;
vector<int> maxes;
list<int> soln;

void solve() {
    if (n == 0) return;
    for (int i = 29; i >= 0; --i) {
        if (maxes.at(i) <= n) {
            if (n - maxes.at(i) <= maxes.at(i+1) - n) {
                soln.emplace_front((maxes.at(i+1) - maxes.at(i))/2);
                n -= (maxes.at(i+1) - maxes.at(i))/2;
            } else {
                soln.emplace_front(n - maxes.at(i));
                n = maxes.at(i);
            }

            solve();
            return;
        }
    }
}

int main() {
    scanf("%d\n", &t);

    for (int i = 1; i < 32; ++i) {
        maxes.emplace_back((1L<<i) - 2);
    }

    for (; t > 0; --t) {
        scanf("%d\n", &n);
        --n;

        soln.clear();
        solve();

        int k = 1;

        printf("%d\n", soln.size());
        for (auto it = soln.begin(); it != soln.end(); ++it) {
            printf("%d ", *it - k);
            k = *it;
        }
        printf("\n");
    }
}