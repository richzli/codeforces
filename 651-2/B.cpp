#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

#define pii pair<int, int>

int t, n, a;
vector<pii> odd, even;

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d", &n);
        odd.clear();
        even.clear();
        for (int i = 1; i <= n*2; ++i) {
            scanf("%d", &a);
            if (a % 2) {
                odd.emplace_back(pii(a, i));
            } else {
                even.emplace_back(pii(a, i));
            }
        }

        if (odd.size() % 2) {
            odd.pop_back();
            even.pop_back();
        } else {
            if (odd.size() >= 2) {
                odd.pop_back();
                odd.pop_back();
            } else {
                even.pop_back();
                even.pop_back();
            }
        }

        while (!odd.empty()) {
            pii A = odd.back();
            odd.pop_back();
            pii B = odd.back();
            odd.pop_back();

            printf("%d %d\n", A.second, B.second);
        }

        while (!even.empty()) {
            pii A = even.back();
            even.pop_back();
            pii B = even.back();
            even.pop_back();

            printf("%d %d\n", A.second, B.second);
        }
    }
}