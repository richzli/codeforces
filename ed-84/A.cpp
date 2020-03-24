#include <cstdio>
using namespace std;

#define ll long long

int main() {
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        ll n, k;
        scanf("%I64d %I64d\n", &n, &k);

        if ((k % 2) ^ (n % 2)) {
            printf("NO\n");
        } else if (n < (k * k)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
