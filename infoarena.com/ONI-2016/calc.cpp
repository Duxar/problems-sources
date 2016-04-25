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

int N;
char *word, *to_write;

void Solve1() {
    int i, t1, t2, t3 = 0;
    GetNr(N);
    t1 = 0;
    t2 = 1;
    for (i = 1; i <= N; ++i) {
        t3 = ((LL) t1 + t2) % MOD1;
        t1 = t2;
        t2 = t3;
    }

    printf("%d\n", t3);
}

void Solve2() {
    int N, i;
    GetNr(N);
    word = (char*) (calloc(1 + N, sizeof(char)));
    to_write = (char*) (calloc(1 + N, sizeof(char)));
    word[N] = to_write[N] = 0;

    scanf("%s", word);

    strcpy(to_write, word);
    for (i = N - 2; i >= 0; --i) {
        if (to_write[i] == '1') {
            to_write[i] = to_write[i + 1] = '0';
            for (i = i + 2; i < N; ++i) {
                to_write[i] = '1';
            }
            printf("%s\n", to_write);
            break;
        }
    }
    if (i == -1) {
        printf("-1\n");
    }

    for (i = N - 2; i >= 0; --i) {
        if (word[i] == '0' && word[i + 1] == '0') {
            word[i] = '1';
            for (i = i + 1; i + 1 < N; i += 2) {
                word[i] = word[i + 1] = '0';
            }
            if (i < N) {
                word[i] = '1';
            }
            printf("%s\n", word);
            break;
        }
    }
    if (i == -1) {
        printf("-1\n");
    }
}

int main(){
    string fileInput = "calc";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int p;

    GetNr(p);
    if (p == 1) {
        Solve1();
    }
    else {
        Solve2();
    }

    return 0;
}
