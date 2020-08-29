#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int t, n;
string a, b;
deque<char> A, B;
vector<int> ops;
bool reverse;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (; t>0; t--) {
        cin >> n;
        cin >> a;
        cin >> b;
        for (char c : a) {
            A.emplace_back(c);
        }
        for (char c : b) {
            B.emplace_back(c);
        }
        reverse = false;
        ops.clear();
        while (A.size() > 0) {
            if (reverse) {
                if (A.front() != B.back()) {
                    A.pop_front();
                    B.pop_back();
                } else {
                    reverse = !reverse;
                    if (A.back() != B.back()) {
                        ops.emplace_back(1);
                    }
                    ops.emplace_back(A.size());
                    A.pop_back();
                    B.pop_back();
                }
            } else {
                if (A.back() == B.back()) {
                    A.pop_back();
                    B.pop_back();
                } else {
                    reverse = !reverse;
                    if (A.front() == B.back()) {
                        ops.emplace_back(1);
                    }
                    ops.emplace_back(A.size());
                    A.pop_front();
                    B.pop_back();
                }
            }
        }
        cout << ops.size() << " ";
        for (int i : ops) {
            cout << i << " ";
        }
        cout << "\n";
    }
}