#include <vector>
#include <cstdio>
#include <utility>
using namespace std;

#define pvii pair<vector<int>, int>
#define vi vector<int>

int n, ai, sz, x, minv, binv;
vector<int> a, b;

pair<vector<int>, int> find_inversions(vector<int> arr) {
    if (arr.size() == 1) {
        return pvii(arr, 0);
    }

    vi left_slice = vi(arr.size()/2);
    copy(arr.begin(), arr.begin() + arr.size() / 2, left_slice.begin());
    vi right_slice = vi(arr.size() - arr.size()/2);
    copy(arr.begin() + arr.size() / 2, arr.end(), right_slice.begin());
    
    pvii left = find_inversions(left_slice);
    pvii right = find_inversions(right_slice);

    vi combine = vi();
    int inversions = left.second + right.second;

    while (left.first.size() > 0 && right.first.size() > 0) {
        if (left.first[0] <= right.first[0]) {
            combine.emplace_back(left.first[0]);
            left.first.erase(left.first.begin());
        } else {
            inversions += left.first.size();
            combine.emplace_back(right.first[0]);
            right.first.erase(right.first.begin());
        }
    }

    if (left.first.size() > 0) {
        combine.insert(combine.end(), left.first.begin(), left.first.end());
    } else {
        combine.insert(combine.end(), right.first.begin(), right.first.end());
    }

    return pvii(combine, inversions);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        a.emplace_back(ai);
    }
    sz = 30;
    x = 0;

    minv = find_inversions(a).second;
    for (int j = sz; j >= 0; --j) {
        b.clear();
        for (int i = 0; i < a.size(); ++i) {
            b.emplace_back(a[i] ^ (x + (1<<j)));
        }
        binv = find_inversions(b).second;

        if (binv < minv) {
            x += (1<<j);
            minv = binv;
        }
    }

    printf("%d %d", minv, x);
}