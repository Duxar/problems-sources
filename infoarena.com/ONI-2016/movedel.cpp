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
char *word1, *word2;
vector <bool> visited;

bool IsPrime(int x) {
    int i;
    if (x > 2 && x % 2 == 0) {
        return false;
    }
    for (i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void Rotate(char *word, int N) {
    int i;
    char c;
    c = word[0];
    for (i = 0; i + 1 < N; ++i) {
        word[i] = word[i + 1];
    }
    word[N - 1] = c;
}

int main(){
    string fileInput = "movedel";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
//  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, j, pos = 0, pleft;

    GetNr(N); GetNr(M);
    pleft = N;
    visited.resize(N);
    word1 = (char *) calloc (1 + N, sizeof(char)); word1[N] = 0;
    word2 = (char *) calloc (1 + N, sizeof(char)); word2[N] = 0;

//  visited[0] = 1;
    for (i = 0; i < N; ++i) {
        word2[i] = 'b';
        word1[i] = 'c';
    }
    word1[0] = 'a';

    i = 2;
    for (j = 1;; ++j) {
        while (!IsPrime(i)) {
            ++i;
        }
        pos -= i;
        while (pos < 0) {
            pos += N;
        }
//      pos %= N;
        if (visited[pos] == 0) {
            if (j >= M) {
                word2[pos] = 'a';
                break;
            }
            visited[pos] = 1;
            --pleft;
        }
        ++i;
    }

    printf("%s\n%s\n\n", word1, word2);

//  for (i = 2, j = 0; j < M; ++j) {
//      while (!IsPrime(i)) {
//          ++i;
//      }
//      for (int cnt = i; cnt; --cnt) {
//          Rotate(word1, N);
//      }
//      printf("%s\n", word1);
//      ++i;
//  }

    return 0;
}
