#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        int h, m;
        scanf("%d %d\n", &h, &m);

        printf("%d\n", (23-h)*60+(60-m));
    }

    return 0;
}