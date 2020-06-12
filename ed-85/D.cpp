#include <cstdio>
using namespace std;

#define ll long long

int t;
ll n, l, r, i, s, d;

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%I64d%I64d%I64d", &n, &l, &r);

        if (l < n*(n-1)+1 && r > 1) {
            i = 0;
            s = 1;

            ll total = n*(n-1);
            ll left = 1, right = n;
            while (true) {
                ll mid = (left + right)/2;
                //printf("%I64d %I64d %I64d\n", left, mid, right);
                if (total - mid * (mid-1) >= l && total - (mid) * (mid+1) < l) {
                    s = n - (mid);
                    i = total - mid * (mid+1);
                    break;
                }

                if (total - mid * (mid-1) < l) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            d = s+1;
            while (i + 2 < l) {
                i += 2;
                ++d;
            }

            if (i+1 == l && i+1 < r) {
                printf("%I64d %I64d ", s, d);
            } else {
                printf("%I64d ", d);
            }

            i += 2;
            ++d;

            if (d > n) {
                ++s;
                d = s+1;
            }

            while (i < r) {
                if (i+1 == r) {
                    if (r == n * (n-1) + 1) {
                        printf("1 ");
                    } else {
                        printf("%I64d ", s);
                    }
                } else {
                    printf("%I64d %I64d ", s, d);
                }

                i += 2;
                ++d;

                if (d > n) {
                    ++s;
                    d = s+1;
                }
            }
        } else {
            printf("1 ");
        }

        printf("\n");
    }
}