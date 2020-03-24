#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);

        vector<int> perm;
        for (int j = 0; j < n; ++j) {
            int p;
            scanf("%d", &p);

            perm.push_back(p-1);
        }

        vector<int> colors;
        for (int j = 0; j < n; ++j) {
            int c;
            scanf("%d", &c);

            colors.push_back(c);
        }

        vector<int> cycle;

        int mn = n+1;

        for (int j = 0; j < n; ++j) {
            if (perm.at(j) != -1) {
                cycle.clear();
                int nxt = perm.at(j);
                perm.at(j) = -1;
                cycle.push_back(colors.at(j));
                while (perm.at(nxt) != -1) {
                    cycle.push_back(colors.at(nxt));
                    int k = perm.at(nxt);
                    perm.at(nxt) = -1;
                    nxt = k;
                }

                for (int k = 1; k <= sqrt(cycle.size()); ++k) {
                    if (!(cycle.size() % k)) {
                        for (int l = 0; l < k; ++l) {
                            int color = cycle.at(l);
                            int nn = l+k;
                            nn %= cycle.size();
                            while (nn != l) {
                                if (cycle.at(nn) != color) {
                                    color = -1;
                                    break;
                                }
                                nn += k;
                                nn %= cycle.size();
                            }
                            if (color != -1) {
                                mn = min(mn, k);
                                break;
                            }
                        }

                        for (int l = 0; l < cycle.size()/k; ++l) {
                            int color = cycle.at(l);
                            int nn = l+cycle.size()/k;
                            nn %= cycle.size();
                            while (nn != l) {
                                if (cycle.at(nn) != color) {
                                    color = -1;
                                    break;
                                }
                                nn += cycle.size()/k;
                                nn %= cycle.size();
                            }
                            if (color != -1) {
                                mn = min(mn, cycle.size()/k);
                                break;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", mn);
    }
}