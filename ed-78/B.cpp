#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        int a, b;
        scanf("%d %d\n", &a, &b);

        int diff = a-b;
        if (diff < 0) {
            diff = -diff;
        }

        int steps = 0;
        while (diff != 0) {
            ++steps;
            if (steps <= diff) {
                diff -= steps;
            } else if (steps-diff < diff) {
                diff = steps-diff;
            } else {
                steps += diff*2-1;
                break;
            }
        }

        printf("%d\n", steps);
    }

    return 0;
}