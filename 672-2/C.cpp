#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define vii vector<ii>

int t, n, q, a, l, r;
ll S;
vector<int> pokemon;
vii swaps, segments;

ll min(ll c, ll b) {
    return c < b ? c : b;
}

ll max(ll c, ll b) {
    return c > b ? c : b;
}

ll abs(ll c) {
    return c>0 ? c : -c;
}

ll sign(ll c) {
    return c / abs(c);
}

int find_segment(int pos) {
    int L = 0, R = segments.size();
    while (L < R) {
        int M = (L+R)/2;
        if (segments[M].first <= pos && pos <= segments[M].second) {
            return pos == segments[M].first ? M - 1 : M;
        } else if (pos < segments[M].first) {
            R = M;
        } else if (pos > segments[M].second) {
            L = M+1;
        }
    }
    return L;
}

void update(int pos, int o) {
    int k = find_segment(pos);

    if (k == -1) {
        
    } else if (k == segments.size() - 1) {
    } else if (pos == segments[k].second) {

    } else {
        int direction = sign(pokemon[segments[k].second] - pokemon[segments[k].first]);
        if (direction == sign(pokemon[pos] - pokemon[pos-1])) {
            if (direction == sign(pokemon[pos + 1] - pokemon[pos])) {
                return;
            }
            ii arr[3] = {ii(segments[k].first, pos), ii(pos, pos+1), ii(pos+1, segments[k].second)};
            
            if (pos + 1 == segments[k].second) {
                S -= (pokemon[segments[k].second] - pokemon[pos]) * direction;
                arr[1] = ii(pos, segments[k+1].second);
                segments.erase(segments.begin() + k, segments.begin()+k+2);
                segments.insert(segments.begin()+k, arr, arr + 2);
            } else {
                S += (pokemon[pos] - pokemon[pos+1]) * direction;
                segments.erase(segments.begin() + k);
                segments.insert(segments.begin()+k, arr, arr + 3);
            }
        } else {
            ii arr[4] = {ii(segments[k].first, pos-1), ii(pos-1, pos), ii(pos, pos+1), ii(pos+1, segments[k].second)};
            
            if (pos-1 == segments[k].first) {
                
            } else { 
                S += (pokemon[pos] - pokemon[pos+1]) * direction;
                segments.erase(segments.begin() + k);
                segments.insert(segments.begin()+k, arr, arr + 4);
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    for (; t>0; --t) {
        pokemon.clear();
        swaps.clear();
        segments.clear();

        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            pokemon.emplace_back(a);
        }
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &l, &r);
            swaps.emplace_back(ii(l, r));
        }

        S = 0;
        int m = 0;
        for (int i = 1; i < n-1; ++i) {
            if (sign(pokemon[i+1]-pokemon[i]) != sign(pokemon[i]-pokemon[m])) {
                segments.emplace_back(ii(m, i));
                m = i;
                if (!(S == 0 && pokemon[segments.back().second] < pokemon[segments.back().first])) {
                    if (pokemon[segments.back().second] < pokemon[segments.back().first]) {
                        S -= pokemon[i];
                    } else {
                        S += pokemon[i];
                    }
                }
            }
        }
        segments.emplace_back(ii(m, n-1));
        if (pokemon[segments.back().second] > pokemon[segments.back().first]) {
            S += pokemon[n-1];
        } else if (S == 0) {
            S += pokemon[0];
        }

        printf("%lld\n", S);

        for (ii q : swaps) {
            ll temp = pokemon[q.first];
            pokemon[q.first] = pokemon[q.second];
            pokemon[q.second] = temp;

            update(q.first, q.second);
            update(q.second, q.first);

            printf("%lld\n", S);
        }
    }
}