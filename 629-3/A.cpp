#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (; t > 0; --t) {
        int a, b;
        scanf("%d %d", &a, &b);

        int c = a % b;

        printf("%d\n", (b - c) % b);
    }
}