#include <cstdio>
#include <vector>
using namespace std;

#define ll long long
#define llm __LONG_LONG_MAX__

int q, n, a, b;
vector<ll> m;
vector<int> A, B;
vector<vector<ll>> dp;

ll min(ll x, ll y) {
    return x < y ? x : y;
}

int main() {
    scanf("%d\n", &q);
    for (int i = 0; i < q; ++i) {
        A.clear();
        B.clear();

        scanf("%d\n", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d %d\n", &a, &b);
            A.emplace_back(a);
            B.emplace_back(b);
        }

        dp.clear();
        dp = vector<vector<ll>>(3, vector<ll>(n));

        for (int j = 0; j < 3; ++j) {
            dp[j][0] = j*B[0];
        }
        //printf(" %lld, %lld, %lld\n", dp[0][0], dp[1][0], dp[2][0]);

        for (int j = 1; j < n; ++j) {
            for (int k1 = 0; k1 < 3; ++k1) {
                m = vector<ll>(3);
                for (int k2 = 0; k2 < 3; ++k2) {
                    if (A[j-1] + k2 == A[j] + k1) {
                        m[k2] = llm;
                    } else {
                        m[k2] = dp[k2][j-1];
                    }
                }
                dp[k1][j] = min(m[0], min(m[1], m[2])) + k1*B[j];
            }
            //dp[0][j] = min(A[j-1]==A[j]?llm:dp[0][j-1], A[j-1]==A[j]+1?llm:dp[1][j-1]);
            //dp[1][j] = min(A[j-1]==A[j]+1?llm:dp[0][j-1], A[j-1]==A[j]?llm:dp[1][j-1]) + B[j];
            //printf(" %lld, %lld, %lld\n", dp[0][j], dp[1][j], dp[2][j]);
        }

        printf("%lld\n", min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1])));
    }
}