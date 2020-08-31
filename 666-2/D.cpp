#include <cstdio>
#include <vector>
using namespace std;

int t, a, last, m, n, p;
vector<int> as;

bool play() {
    bool turn = false;
    last = -1;
    while (true) {
        p = 0;
        m = 0;
        for (int i = 0; i < as.size(); ++i) {
            if (i != last) {
                if (as[i] > m) {
                    m = as[i];
                    p = i;
                }
            }
        }
        if (m == 0) {
            return turn;
        }
        last = p;
        as[last] -= 1;
        turn = !turn;
    }
    return turn;
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        as.clear();
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            as.emplace_back(a);
        }
        printf(play() ? "T\n" : "HL\n");
    }
}