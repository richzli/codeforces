#include <cstdio>
#include <list>
using namespace std;

/*
void pl(list<int> l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        printf("%d-", *it);
    }
    printf("X\n");
}
*/

int main() {
    int n;
    scanf("%d\n", &n);

    int people[n];
    bool g[n];

    for (int i = 0; i < n; ++i) {
        g[i] = false;
    }

    list<int> empty;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);

        people[i] = --a;

        if (a == -1) {
            empty.push_back(i);
        } else {
            g[a] = true;
        }
    }

    list<int> nongiven;
    for (int i = 0; i < n; ++i) {
        if (!g[i]) {
            nongiven.push_back(i);
        }
    }

    while (empty.size() > 0) {
        //pl(empty);
        //pl(nongiven);

        int e = empty.front();
        list<int>::iterator ng = nongiven.begin();
        
        if (empty.size() == 2) {
            //printf("%d %d!\n", empty.back(), nongiven.back());
            if (empty.back() == nongiven.back()) {
                ng = --nongiven.end();
            }
        } else if (e == *ng) {
            ++ng;
        }

        //printf("%d %d\n", *e, *ng);

        people[e] = *ng;

        empty.pop_front();
        nongiven.erase(ng);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", ++people[i]);
    }

    return 0;
}