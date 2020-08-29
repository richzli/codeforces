#include <cstdio>
#include <vector>
using namespace std;

int t, n, ai, s1;
vector<int> a;

int main() {
    scanf("%d", &t);
    for (; t>0; t--) {
        scanf("%d", &n);
        a.clear();
        s1 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ai);
            a.emplace_back(ai);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != 1) break;
            s1++;
        }
        if ((s1 % 2) ^ (s1 == n)) {
            printf("Second\n");
        } else {
            printf("First\n");
        }
    }
}