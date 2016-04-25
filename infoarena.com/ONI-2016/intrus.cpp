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

#define VMAX 1e6

class Intrus {
public:
    int id, x, y, grad, vmax;

    Intrus() {
    }

    Intrus(int iid, int xx, int yy, int ggrad, int vvmax) {
        id = iid;
        this->x = xx;
        this->y = yy;
        grad = ggrad;
        vmax = vvmax;
    }

    void writeme() {
        printf("%d %d %d\n", id, x + 1, y + 1);
    }

    pair <int, int> getlocation() {
        return mp(x, y);
    }
};

int C, N, M, D;
vector <bool> isthere1(VMAX), isthere2(VMAX), isprime(VMAX, true);
vector <vector <int> > mat;
vector <Intrus> intrusi;
vector <int> positions;

bool Comparator1(int p1, int p2) {
    if (intrusi[p1].grad == intrusi[p2].grad) {
        if (intrusi[p1].vmax == intrusi[p2].vmax) {
            return intrusi[p1].getlocation() < intrusi[p2].getlocation();
        }
        return intrusi[p1].vmax > intrusi[p2].vmax;
    }
    return intrusi[p1].grad > intrusi[p2].grad;
}

pair <int, int> GetPrimesMax(int x, int y) {
    int vmax = -1, cnt = 0, i, j;
    for (i = x - (D / 2); i <= x + (D / 2); ++i) {
        for (j = y - (D / 2); j <= y + (D / 2); ++j) {
            if (0 <= i && i < N && 0 <= j && j < M) {
                if (isprime[mat[i][j]]) {
                    ++cnt;
                    vmax = max(vmax, mat[i][j]);
                }
            }
        }
    }
    return mp(cnt, vmax);

}

int main(){
    string fileInput = "intrus";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
        //  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, j, cnt2 = 0;

    GetNr(C); GetNr(N); GetNr(M); GetNr(D);

    mat.resize(N, vector<int> (M));
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            GetNr(mat[i][j]);
            if (mat[i][j]) {
                if (isthere1[mat[i][j]]) {
                    cnt2 += (isthere2[mat[i][j]] == false);
                    ++cnt2;
                    isthere2[mat[i][j]] = 1;
                }
                isthere1[mat[i][j]] = 1;
            }
        }
    }

    if (C == 1) {
        printf("%d\n", cnt2);
        return 0;
    }

    if (cnt2 == 0) {
        printf("-1\n");
        return 0;
    }

    isprime[0] = isprime[1] = false;
    for (i = 4; i < VMAX; i += 2) {
        isprime[i] = false;
    }
    for (i = 3; i < VMAX; ++i) {
        if (isprime[i]) {
            for (LL j = (LL) i * i; j < VMAX; j += i) {
                isprime[j] = false;
            }
        }
    }

    intrusi.resize(cnt2);
    positions.resize(cnt2);
    for (i = 0; i < cnt2; ++i) {
        positions[i] = i;
    }

    --cnt2;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            if (isthere2[mat[i][j]]) {
                int cnt, vmax;
                tie(cnt, vmax) = GetPrimesMax(i, j);
                intrusi[cnt2--] = Intrus(mat[i][j], i, j, cnt, vmax);
            }
        }
    }

    sort(ALL(positions), Comparator1);

    for (i = 0; i < positions.size(); ++i) {
        intrusi[positions[i]].writeme();
    }


    return 0;
}
