#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int t, n, x, a;
vector<int> ppl;

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d %d", &n, &x);

        ppl.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ppl.push_back(a);
        }

        sort(ppl.begin(), ppl.end());

        ll rich = 0, total = 0;
        int num = 0;

        while (rich <= total && !ppl.empty()) {
            rich += x;
            total += ppl.back();
            ppl.pop_back();
            ++num;
        }

        if (rich <= total) {
            printf("%d\n", num);
        } else {
            printf("%d\n", num-1);
        }
    }
}