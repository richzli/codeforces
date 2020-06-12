#include <cstdio>

int t, n;
int sumpow2[31] = {};

int main() {
    sumpow2[0] = 1;
    int p2 = 2;
    for (int i = 1; i <= 30; ++i) {
        sumpow2[i] = sumpow2[i-1] + p2;
        p2 *= 2;
    }

    scanf("%d\n", &t);
    for (; t > 0; --t) {
        scanf("%d\n", &n);

        int k = n/2-1;
        printf("%d\n", sumpow2[k] - 1 + (1<<n) - (sumpow2[n] - sumpow2[k] - (1<<n)));
    }
}