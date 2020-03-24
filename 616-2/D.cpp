#include <stdio.h>
#include <string.h>
using namespace std;

char input[200001];
int sum[26][200001] = {};

int main() {
    scanf("%s\n", input);
    int n = strlen(input);

    for (int i = 0; i < n; ++i) {
        char c = input[i];

        for (int j = 0; j < 26; ++j) {
            sum[j][i+1] = sum[j][i];
            if (c == j+97) {
                ++sum[j][i+1];
            }
        }
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        int ncs = 0;
        
        if (l == r) {
            printf("Yes\n");
            continue;
        }

        for (int j = 0; j < 26; ++j) {
            if (sum[j][r]-sum[j][l-1] > 0) {
                ++ncs;
            }
        }

        if (ncs > 2 || (ncs == 2 && input[l-1] != input[r-1])) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}