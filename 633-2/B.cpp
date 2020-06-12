#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, a, j;
vector<int> nms;

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d", &n);

        nms.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);

            nms.emplace_back(a);
        }

        sort(nms.begin(), nms.end());

        j = n/2-1;
        if (n % 2) {
            printf("%d ", nms.at(j+1));
        }

        for (; j >= 0; --j) {
            printf("%d %d ", nms.at(j), nms.at(n-j-1));
        }
        printf("\n");
    }
}