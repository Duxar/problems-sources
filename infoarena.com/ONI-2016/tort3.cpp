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
char mat[500][501];
int dp[500][500];

int main(){
    string fileInput = "tort3";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, j, x, y;

    GetNr(N); GetNr(M);

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            dp[i][j] = 1;
        }
        scanf("%s", mat[i]);
    }

    for (i = 1; i < N; ++i) {
        for (j = 1; j < M; ++j) {
            if (mat[i][j] == mat[i - 1][j] && mat[i][j] == mat[i - 1][j - 1] && mat[i][j] == mat[i][j - 1]) {
                dp[i][j] = max(dp[i][j], 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}));
            }
        }
    }

    for (int lg = min(N, M); lg; --lg) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < M; ++j) {
                if (dp[i][j] >= lg) {

                    if (mat[i][j] != '-' && mat[i - lg + 1][j] != '-' && mat[i - lg + 1][j - lg + 1] != '-' && mat[i][j - lg + 1] != '-') {
                        printf("%d %d %d\n", lg, i + 1, j + 1);
                        for (x = i - lg + 1; x <= i; ++x) {
                            for (y = j - lg + 1; y <= j; ++y) {
                                mat[x][y] = '-';
                                dp[x][y] = 0;
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}
