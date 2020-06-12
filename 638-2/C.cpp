#include <cstdio>
#include <vector>
using namespace std;

int t, n, k, j;
char c;
vector<int> s;

int main() {
    scanf("%d\n", &t);
    for (; t > 0; --t) {
        scanf("%d%d\n", &n, &k);
        s.clear();
        s.resize(26);

        for (int i = 0; i < n; ++i) {
            scanf("%c", &c);

            ++s.at(c-'a');
        }

        j = 0;
        while (s.at(j) == 0) {
            ++j;
        }
        
        if (s.at(j) == n && n == k) {
            printf("%c\n", j+'a');
        } else
        if (s.at(j) >= k) {
            s.at(j) -= k;

            printf("%c", j+'a');

            while (s.at(j) == 0) {
                ++j;
            }

            if (k + s.at(j) != n) {
                while (j < 26) {
                    for (int m = 0; m < s.at(j); ++m) {
                        printf("%c", j+'a');
                    }
                    ++j;
                }
            } else {
                for (int m = 0; m < (s.at(j)-1)/k + 1; ++m) {
                    printf("%c", j+'a');
                }
            }

            printf("\n");
        } else {
            while (k > 0) {
                k -= s.at(j);
                ++j;
            }
            printf("%c\n", j-1+'a');
        }
    }
}