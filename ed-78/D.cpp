#include <cstdio>
#include <vector>
using namespace std;

#define pii pair<int, int>

vector<pii> borders;
vector<int> points;

int find(int n) {
    if (points.at(n) == n) {
        return n;
    }

    return (points.at(n) = find(points.at(n)));
}

void unionn(int a, int b) {
    points.at(find(b)) = find(a);
}

bool intersect(pii f, pii s) {
    if ((f.first > s.first && f.first < s.second && f.second > s.second) || (f.second > s.first && f.second < s.second && f.first < s.first)) {
        return true;
    }
    return false;
}

bool doit() {
    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        points.push_back(i);

        int l, r;
        scanf("%d %d\n", &l, &r);

        pii seg(l, r);

        for (int j = 0; j < borders.size(); ++j) {
            if (intersect(borders.at(j), seg)) {
                if (find(i) == find(j)) {
                    return false;
                } else {
                    unionn(i, j);
                }
            }
        }

        borders.push_back(seg);
    }

    int o = find(0);
    for (int i = 0; i < points.size(); ++i) {
        if (find(i) != o) {
            return false;
        }
    }

    return true;
}

int main() {
    
    printf(doit() ? "YES" : "NO");

    return 0;
}