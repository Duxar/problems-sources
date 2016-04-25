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

int N, topstack = -1;
vector <int> values;
vector <vector <int> > positions;

int main(){
    string fileInput = "undo2";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
//  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, t, x, newtopstack = -2;

    GetNr(N);
    values.resize(200000);
    positions.resize(200001);

    for (i = 0; i < N; ++i) {
        GetNr(t);
        if (t == 1) {
            if (-2 != newtopstack) {
                assert(newtopstack > -2);
                for (int j = newtopstack + 1; j <= topstack; ++j) {
                    assert(positions[values[j]].size() > 0);
                    positions[values[j]].pop_back();
                }
                topstack = newtopstack;
                newtopstack = -2;
            }
            GetNr(x);
            ++topstack;
            values[topstack] = x;
            positions[x].pb(topstack);
        }
        else if (t == 2) {
            GetNr(x);
            if (newtopstack == -2) {
                newtopstack = topstack - x;
            }
            else {
                newtopstack -= x;
            }
        }
        else if (t == 3) {
            GetNr(x);
            assert(newtopstack != -2);
            newtopstack += x;
        }
        else if (t == 4) {
            GetNr(x);
            int cnt, tpos;
            tpos = topstack;
            if (newtopstack != -2) {
                tpos = newtopstack;
            }
            cnt = (int) (upper_bound(ALL(positions[x]), tpos) - positions[x].begin());
            printf("%d\n", cnt);
        }
    }

    return 0;
}
