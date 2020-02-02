#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char getnot(string lets) {
    if (lets.compare("a") == 0) {
        return 'b';
    } else if (lets.compare("b") == 0 || lets.compare("c") == 0) { 
        return 'a';
    } else if (lets.compare("ab") == 0 || lets.compare("ba") == 0 || lets.compare("aa") == 0 || lets.compare("bb") == 0) {
        return 'c';
    } else if (lets.compare("bc") == 0 || lets.compare("cb") == 0 || lets.compare("cc") == 0) {
        return 'a';
    } else if (lets.compare("ac") == 0 || lets.compare("ca") == 0) {
        return 'b';
    } else {
        return 'a';
    }
}

string generate(int length, string l, string r) {
    string ret = "";
    string prev = l;
    for (int i = 0; i < length; ++i) {
        if (i != length-1) {
            char ll = getnot(prev);
            ret += ll;
            prev = ll;
        } else {
            char ll = getnot(prev+r);
            ret += ll;
        }
    }
    
    return ret;
}

string find(string s) {
    string poss = "";
    int run = 0;
    for (auto let : s) {
        if (poss.compare("") == 0) {
            if (let == '?') {
                run += 1;
            } else {
                string r(1, let);
                poss += generate(run, "", r) + r;
                run = 0;
            }
        } else {
            if (let == '?') {
                run += 1;
            } else {
                string l(1, poss[poss.length()-1]);
                string r(1, let);
                poss += generate(run, l, r) + r;
                run = 0;
                if (poss[poss.length()-2] == poss[poss.length()-1]) {
                    return "-1";
                }
            }
        }
    }
    if (poss.compare("") != 0) {
        string l(1, poss[poss.length()-1]);
        poss += generate(run, l, "");
    } else {
        poss += generate(run, "", "");
    }
                    
    return poss;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
}