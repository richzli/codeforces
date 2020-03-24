#include <cstdio>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        int c, k;
        scanf("%d %d\n", &c, &k);

        int d = c / k;
        int r = c % k;
        int s = k / 2;

        printf("%d\n", (d*k) + min(r, s));
    }

    return 0;
}