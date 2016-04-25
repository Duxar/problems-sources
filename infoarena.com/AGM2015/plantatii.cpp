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

int N, W;
vector <vector <LL> > mat_principal, mat_secundar;

LL GetSum(int i, int j, int lg) {
    if (i > 0 && j > 0 && i + lg - 1 <= N && j + lg - 1 <= N) {
        LL sum_principal = mat_principal[i + lg - 1][j + lg - 1] -  mat_principal[i - 1][j - 1];
        LL sum_secundar  =  mat_secundar[i + lg - 1][j]          -  mat_secundar[i - 1][j + lg];
        LL center = 0;
        if (lg & 1) {
            center = mat_principal[i + lg / 2][j + lg / 2] - mat_principal[i + lg / 2 - 1][j + lg / 2 - 1];
        }
        return  sum_secundar + sum_principal - center;
    }
    else {
        return -1;
    }
}

void Solve() {
    int i, j, even_side = 0, odd_side = -1;
    GetNr(N); GetNr(W);

    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            GetNr(mat_principal[i][j]);
            mat_secundar[i][j] = mat_principal[i][j];


            mat_principal[i][j] += mat_principal[i - 1][j - 1];
            mat_secundar[i][j]  += mat_secundar[i - 1][j + 1];
        }
    }

    LL sum_aux;

    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            sum_aux = GetSum(i - (odd_side + 2) / 2, j - (odd_side + 2) / 2, odd_side + 2);
            while (sum_aux > 0 && sum_aux <= W) {
                odd_side += 2;
                sum_aux = GetSum(i - (odd_side + 2) / 2, j - (odd_side + 2) / 2, odd_side + 2);
            }

            sum_aux = GetSum(i - (even_side + 2) / 2 + 1, j - (even_side + 2) / 2 + 1, even_side + 2);
            while (sum_aux > 0 && sum_aux <= W) {
                even_side += 2;
                sum_aux = GetSum(i - (even_side + 2) / 2 + 1, j - (even_side + 2) / 2 + 1, even_side + 2);
            }
        }
    }

    printf("%d\n", max(odd_side, even_side));
}

int main(){
    string fileInput = "plantatii";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
//  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, T;

    N = 1000;
    mat_secundar.resize(2 + N, vector<LL> (2 + N, 0));
    mat_principal.resize(2 + N, vector<LL> (2 + N, 0));

    GetNr(T);
    while (T--) {
        Solve();
    }

    return 0;
}
