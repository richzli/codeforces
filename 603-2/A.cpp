#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int candies[3];
        scanf("%d %d %d", &candies[0], &candies[1], &candies[2]);

        sort(candies, candies+3);

        printf("%d %d %d\n", candies[0], candies[1], candies[2]);
    }

    return 0;
}