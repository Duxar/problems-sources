#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <algorithm>
#include <bitset>
#include <list>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#endif

using namespace std;

    // lambda : [] (int a, int b) -> bool { body return }
    // string r_str = R"(raw string)"

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define LL long long
#define ULL unsigned long long
#define PI (atan(1) * 4)
#define BASE 73
#define NMAX 10000
#define NMAX2 20001
#define MOD1 1000000007
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define CRLINE Duxar(__LINE__);
#define SHOWME(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define ENTER putchar('\n');
#define step(i) (i & (i - 1)) ^ i

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};

int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Duxar(int _this_line) {
#ifndef ONLINE_JUDGE
    printf("\n . . . . . . . . . . . . . Passed line - %d\n", _this_line);
#endif
}

bool AreEqual(double a, double b) {
    return (fabs(a - b) < 1e-10);
}

template <class T>
bool GetNr(T &_value) {
    T _sign = 1;
    char ch;
    _value = 0;
    while(!isdigit(ch = getchar())) {
        if (ch == -1) {
            return false;
        }
        ch == '-' ? _sign = -1 : _sign = 1 ;
    }
    do {
        _value = _value * 10 + (ch - '0');
    } while(isdigit(ch = getchar()));
    _value *= _sign;
    return true;
}

int N, M;
vector <pair <LL, LL> > walls, birds, segments;

pair <LL, LL> GetSlope (pair <LL, LL> p1, pair <LL, LL> p2) {
    return mp(p1.second - p2.second, p1.first - p2.first);
}

LL CompareSlope(pair <LL, LL> s1, pair <LL, LL> s2) {
    LL t1, t2;
    t1 = s1.first * s2.second;
    t2 = s2.first * s1.second;
    if (t1 > t2) {
        return -1;
    }
    if (t1 < t2) {
        return 1;
    }
    return 0;
}

double GetX(pair <LL, LL> point, pair <LL, LL> slope) {
    double b, m = (double) slope.first / slope.second;
    b = point.second - m * point.first;
    return (-b) / m;
}

bool Cmp1(pair <LL, LL> p1, pair <LL, LL> p2) {
    return p1.first < p2.first;
}

int main(){
    string fileInput = "elmer";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
        //  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    LL i, j;

    GetNr(N);
    birds.resize(N);
    for (i = 0; i < N; ++i) {
        GetNr(birds[i].fi); GetNr(birds[i].se);
    }
    sort(ALL(birds));


    GetNr(M);
    walls.resize(2 + M);
    walls[0] = mp(0, MOD1);
    walls[M + 1] = mp((1LL << 62), MOD1);
    for (i = 1; i <= M; ++i) {
        GetNr(walls[i].fi); GetNr(walls[i].se);
    }
    M += 2;
    sort(ALL(walls));


    for (i = 0; i < N; ++i) {

        LL st = (LL) (lower_bound(ALL(walls), birds[i], Cmp1) - walls.begin());

        if (walls[st].first == birds[i].first) {
            assert(walls[st - 1].first >= 0);
            segments.pb(mp(walls[st - 1].first + 1, 1));
            segments.pb(mp(walls[st + 1].first, -1));
        }

        pair <LL, LL> slope = mp(MOD1, 1), aux;
        if (walls[st].first >= birds[i].first) {
            --st;
        }
        for (j = st; j; --j) {
            if (walls[j].second >= birds[i].second) {
                break;
            }
            if (CompareSlope((aux = GetSlope(birds[i], walls[j])), slope) == 1) {
                slope = aux;
            }
            LL x = floor(GetX(birds[i], slope));
            if (x > walls[j - 1].first) {
                assert(walls[j - 1].first >= 0);
                segments.pb(mp(walls[j - 1].first + 1, 1));
                segments.pb(mp(x + 1, -1));
            }
        }


        if (walls[st].first < birds[i].first && birds[i].first < walls[st + 1].first) {
            assert(walls[st].first >= 0);
            segments.pb(mp(walls[st].first + 1, 1));
            segments.pb(mp(walls[st + 1].first, -1));
        }

        slope = mp(MOD1, -1);

        while (walls[st].first <= birds[i].first) {
            ++st;
        }
        for (j = st; j + 1 < M; ++j) {
            if (walls[j].second >= birds[i].second) {
                break;
            }
            if (CompareSlope((aux = GetSlope(birds[i], walls[j])), slope) == -1) {
                slope = aux;
            }
            LL x = ceil(GetX(birds[i], slope));
            if (x < walls[j + 1].first) {
                assert(x > 0);
                segments.pb(mp(x, 1));
                segments.pb(mp(walls[j + 1].first, -1));
            }
        }
    }

    sort(ALL(segments));

    int ans = 0, cnt = 0;
    for (i = 0; i < segments.size(); ++i) {
        cnt += segments[i].second;
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}
