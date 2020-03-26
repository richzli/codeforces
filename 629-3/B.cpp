#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (; t > 0; --t) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 1; i <= n; ++i) {
            if (k > i) {
                k -= i;
            } else {
                ++i;
                i = n - i;
                k = n - k;
                for (int j = 0; j < n; ++j) {
                    if (i == j || k == j) {
                        printf("b");
                    } else {
                        printf("a");
                    }
                }
                break;
            }
        }
        
        printf("\n");
    }
}