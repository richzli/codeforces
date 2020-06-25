#include <cstdio>
using namespace std;

int t, n;
const char p1[] = "Ashishgup\n", p2[] = "FastestFinger\n";

int lsb(int n) {
    return n & (-n);
}

// isPrime algorithm pulled from KACTL
// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/MillerRabin.h
// https://codeforces.com/blog/entry/8790
typedef long long ll;
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

int main() {
    scanf("%d", &t);
    for (; t > 0; --t) {
        scanf("%d", &n);

        if (n == 1) {
            printf(p2);
        } else if (n == 2) {
            printf(p1);
        } else if (lsb(n) == n) {
            printf(p2);
        } else if (lsb(n) != 2) {
            printf(p1);
        } else if (isPrime(n/2)) {
            printf(p2);
        } else {
            printf(p1);
        }
    }
}