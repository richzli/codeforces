#include <queue>
#include <cstdio>
using namespace std;

int n, k, a;
priority_queue<int> odd, even;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d%d", &n, &k);

    if ((n - k) % 2) {

    } else {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            if (i % 2) {
                odd.emplace(a);
            } else {
                even.emplace(a);
            }
        }
        for (; n > k; --n) {
            odd.pop();
            even.pop();
        }
        printf("%d", min(odd.top(), even.top()));
    }
}