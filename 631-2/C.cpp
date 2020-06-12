#include <cstdio>
#include <vector>
#include <list>
using namespace std;

int n, m;
vector<int> l;

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int li;
        scanf("%d", &li);
        l.push_back(li);
    }

    list<int> soln;

    int i = m-1;
    int j = n;
    while (j > 0 && i >= 0) {
        printf("-%d\n", i);
        j= min(j-1, n-l.at(i));
        soln.emplace_front(j);
        --i;
    }
    if (i == -1) {
        for (int num : soln) {
            printf("%d ", num);
        }
    } else {
        printf("-1\n");
    }


}