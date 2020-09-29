#include <vector>
#include <cstdio>
using namespace std;

vector<int> composite;
void sieve() {
    composite = vector<int>(1e9+1);
    int i = 2;
    while (i*i <= 1e9) {
        if (!composite[i]) {
            for (int j = i; i*j <= 1e9; ++j) {
                composite[i*j] = j;
            }
        }
        ++i;
    }
}

int main() {
    sieve();
}