#include <cstdio>
using namespace std;

int t, n, p1, c1, p2, c2;
bool f;

int main() {
    scanf("%d", &t);
    
    for (; t > 0; --t) {
        scanf("%d", &n);

        p1 = c1 = 0;
        f = false;

        for (; n > 0; --n) {
            scanf("%d%d", &p2, &c2);

            if ((p2-p1 < c2-c1) || (p2-p1 < 0) || (c2-c1 < 0)) {
                f = true;
            }

            p1 = p2;
            c1 = c2;
        }

        if (f) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}