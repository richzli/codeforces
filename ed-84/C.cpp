#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", (n-1) + (m-1) + n * m);

    for (int i = 1; i < n; ++i) {
        printf("D");
    }

    for (int i = 1; i < m; ++i) {
        printf("L");
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (i%2) {
                printf("D");
            } else {
                printf("U");
            }
        }
        printf("R");
    }
}