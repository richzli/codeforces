#include <cstdio>
using namespace std;

int rev(int a) {
    return a == 1 ? 2 : 1;
}

int main() {
    int t;
    scanf("%d", &t);

    for (; t > 0; --t) {
        int n;
        scanf("%d", &n);
        
        int first;
        scanf("%d", &first);
        int prev = first;
        int pc = 1;

        int mc = 1;
        int colors[n] = {1};
        int sp = -1;

        for (int i = 1; i < n; ++i) {
            int a;
            scanf("%d", &a);

            if (i == n-1) {
                if ((pc != 1 || prev == a) && first == a) {
                    colors[i] = 1;
                } else if (first != a) {
                    if (prev != a) {
                        if (pc == 1) {
                            mc = 2;
                            colors[i] = 2;
                        } else {
                            if (sp != -1) {
                                mc = 2;
                                colors[i] = 1;
                                for (int j = sp; j < n; ++j) {
                                    colors[j] = rev(colors[j]);
                                }
                            } else {
                                mc = 3;
                                colors[i] = 3;
                            }

                        }
                    } else {
                        mc = 2;
                        colors[i] = 2;
                    }
                } else {
                    mc = 2;
                    colors[i] = 2;
                }
                break;
            }

            if (pc != 1 || prev == a) {
                colors[i] = 1;
                pc = 1;
                if (prev == a) {
                    sp = i;
                }
            } else {
                mc = 2;
                colors[i] = 2;
                pc = 2;
            }

            prev = a;
        }

        printf("%d\n", mc);
        for (int i = 0; i < n; ++i) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    }
}