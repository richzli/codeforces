#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, l, cnt;
vector<int> spheres, shop, leftover;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        spheres.emplace_back(a);
    }
    shop = vector<int>(n);
    sort(spheres.begin(), spheres.end());

    l = 0;
    while(spheres.size() > 0) {
        int top = spheres.back();
        spheres.pop_back();
        int i = 1;
        while (spheres.back() == top) {
            ++i;
            spheres.pop_back();
        }

        while (i > 0 && l < n) {
            shop[l] = top;
            l += 2;
            --i;
        }

        if (l >= n) {
            while (i > 0) {
                spheres.emplace_back(top);
                --i;
            }
            break;
        }
    }

    l = 1;
    while (spheres.size() > 0) {
        int c = spheres.back();
        spheres.pop_back();
        if (l < n-1 && shop[l-1] > c && shop[l+1] > c && shop[l] == 0) {
            shop[l] = c;
            l += 2;
        } else {
            leftover.emplace_back(c);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (shop[i] == 0) {
            int c = leftover.back();
            leftover.pop_back();
            shop[i] = c;
        }
    }

    cnt = 0;
    for (int i = 1; i < n-1; ++i) {
        if (shop[i-1] > shop[i] && shop[i+1] > shop[i]) {
            ++cnt;
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) {
        printf("%d ", shop[i]);
    }
}