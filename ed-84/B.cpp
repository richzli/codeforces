#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);

        bool kingdoms[n] = {};
        vector<vector<int>> princesses;

        for (int j = 0; j < n; ++j) {
            princesses.push_back(vector<int>());
            int k;
            scanf("%d", &k);

            for (int l = 0; l < k; ++l) {
                int g;
                scanf("%d", &g);
                princesses.at(j).push_back(g);
            }
        }

        int fp = -1;
        for (int j = 0; j < n; ++j) {
            bool found = false;
            for (int m : princesses.at(j)) {
                if (!kingdoms[--m]) {
                    kingdoms[m] = true;
                    found = true;
                    break;
                }
            }
            if (!found && fp == -1) {
                fp = j+1;
            }
        }

        if (fp == -1) {
            printf("OPTIMAL\n");
        } else {
            printf("IMPROVE\n");
            printf("%d ", fp);
            for (int j = 0; j < n; ++j) {
                if (!kingdoms[j]) {
                    printf("%d\n", j+1);
                    break;
                }
            }
        }
    }
}
