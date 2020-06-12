#include <cstdio>
#include <vector>
using namespace std;

int t, n, a, m, T;
vector<int> nms;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d", &n);

        T = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            
            if (i == 0) {
                m = a;
            } else {
                if (a < m) {
                    int d = m-a;
                    int c = 0;
                    while (d > 0) {
                        ++c;
                        d = d >> 1;
                    }
                    T = max(c, T);
                } else {
                    m = a;
                }
            }
        }

        printf("%d\n", T);
    }
}