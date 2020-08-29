#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int t, n, a;
vector<int> q, qs;
vector<bool> dp;

int main() {
    scanf("%d", &t);
    for (; t>0; t--) {
        scanf("%d", &n);
        q.clear();
        for (int i = 0; i < n*2; i++) {
            scanf("%d", &a);
            q.emplace_back(a);
        }

        qs.clear();
        
        int last = 0;
        for (int i = 0; i < n*2; ++i) {
            if (q[i] > q[last]) {
                qs.emplace_back(i - last);
                last = i;
            }
        }
        qs.emplace_back(n*2 - last);

        dp = vector<bool>(n+1);
        dp[0] = true;
        for (int c : qs) {
            for (int i = n; i >= c; --i) {
                if (!dp[i] && dp[i-c]) {
                    dp[i] = dp[i-c];
                }
            }
        }
        if (dp[n]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}