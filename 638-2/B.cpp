#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int t, n, k, a, c;
set<int> nums;
vector<int> init, soln;

int main() {
    scanf("%d", &t);

    for (; t > 0; --t) {
        scanf("%d%d", &n, &k);
        
        init.clear();
        soln.clear();
        nums.clear();

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            init.emplace_back(a);
            nums.emplace(a);
        }

        if (nums.size() > k) {
            printf("-1\n");
        } else {
            c = 1;
            while (nums.size() < k) {
                nums.emplace(c);
                ++c;
            }
            printf("%d\n", n * nums.size());
            for (int i = 0; i < n; ++i) {
                for (auto it = nums.begin(); it != nums.end(); ++it) {
                    printf("%d ", *it);
                }
            }
            printf("\n");
        }
    }
}