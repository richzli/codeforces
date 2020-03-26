#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (; t > 0; --t) {
        int n;
        scanf("%d\n", &n);

        char x, a[n+1], b[n+1];
        bool m = false;
        for (int i = 0; i < n; ++i) {
            scanf("%c", &x);
            if (x == '0') {
                a[i] = '0';
                b[i] = '0';
            } else if (x == '1') {
                if (!m) {
                    a[i] = '1';
                    b[i] = '0';
                    m = true;
                } else {
                    a[i] = '0';
                    b[i] = '1';
                }
            } else {
                if (!m) {
                    a[i] = '1';
                    b[i] = '1';
                } else {
                    a[i] = '0';
                    b[i] = '2';
                }
            }
        }

        a[n] = '\0';
        b[n] = '\0';

        printf("%s\n%s\n", a, b);
    }
}