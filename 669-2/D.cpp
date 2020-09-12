#include <cstdio>
#include <vector>
using namespace std;


int n, h;
vector<int> a;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);
        a.emplace_back(h);
    }
}