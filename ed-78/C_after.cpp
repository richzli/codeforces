#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        n += n;
        
        int dd = 0;
        vector<int> left, right;
        for (int j = 0; j < n/2; ++j) {
            int x;
            scanf("%d", &x);
            if (x == 2) {
                x = -1;
            }

            left.push_back(x);
            dd += x;
        }
        for (int j = n/2; j < n; ++j) {
            int x;
            scanf("%d", &x);
            if (x == 2) {
                x = -1;
            }

            right.push_back(x);
            dd += x;
        }

        int dl = 0, dr = 0;
        map<int, int> drm;
        drm.insert(pair<int, int>(0, -1));
        for (size_t j = 0; j < right.size(); ++j) {
            int d = right.at(j);
            dr += d;
            if (drm.find(dr) == drm.end()) {
                drm.insert(pair<int, int>(dr, j));
            }
        }

        auto it = drm.find(dd);
        if (it != drm.end()) {
            n = min(it->second+1, n);
        }
        for (int j = left.size()-1; j >= 0; --j) {
            int d = left.at(j);
            dl += d;
            auto it = drm.find(dd-dl);
            if (it != drm.end()) {
                n = min((left.size()-j)+(it->second+1), n);
            }
        }

        printf("%d\n", n);
    }

    return 0;
}