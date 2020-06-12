#include <cstdio>
#include <list>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (; t > 0; --t) {
        int n;
        scanf("%d", &n);

        list<int> p;
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            p.emplace_back(num);
        }

        vector<int> solns;

        list<int> c = p;
        c.sort();
        int d = 0, e = 0;
        bool f = false;

        while (!f && !c.empty()) {
            if (c.size() >= 2) {
                if (c.front() == e+1) {
                    if (c.front() == *(++(c.begin()))) {
                        if (c.front() == d+1) {
                            d += 1;
                            e += 1;
                            c.pop_front();
                            c.pop_front();
                        } else {
                            f = true;
                        }
                    } else {
                        e += 1;
                        c.pop_front();
                    }
                } else {
                    f = true;
                }
            } else {
                if (c.front() == e+1) {
                    e += 1;
                    c.pop_front();
                } else {
                    f = true;
                }
            }
        }

        if (f || d == 0) {
            ;
        } else {
            set<int> a;
            for (int i = 1; i <= d; ++i) {
                a.insert(i);
            }
            auto it = p.begin();
            for (int i = 0; i < d; ++i) {
                a.erase(*it);
                ++it;
            }
            if (a.empty()) {
                solns.emplace_back(d);
            }

            if (d != n-d) {
                a.clear();
                for (int i = 1; i <= d; ++i) {
                    a.insert(i);
                }
                auto it = --p.end();
                for (int i = 0; i < d; ++i) {
                    a.erase(*it);
                    --it;
                }
                if (a.empty()) {
                    solns.emplace_back(n-d);
                }
            }
        }

        printf("%d\n", solns.size());
        for (int i = 0; i < solns.size(); ++i) {
            printf("%d %d\n", solns.at(i), n-solns.at(i));
        }
    }
}