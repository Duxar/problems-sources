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

template <class T>
void PutNr(T _value, char _ch = ' ') {
    cout << _value << _ch;
}

int N;
vector <vector <int> > mat, graph;
vector <int> match_diagonal;
vector <bool> visited;
map <int, int> match_value;


bool FoundNewPath(int node) {
    if (visited[node]) {
        return false;
    }

    visited[node] = true;
    for (auto to: graph[node]) {
        if (match_value[to] == -1) {
            match_value[to] = node;
            match_diagonal[node] = to;
            return true;
        }
    }

    for (auto to: graph[node]) {
        if (FoundNewPath(match_value[to])) {
            match_value[to] = node;
            match_diagonal[node] = to;
            return true;
        }
    }

    return false;
}

void Solve() {
    int x, i, j, y;

    match_diagonal.clear();
    mat.clear();
    graph.clear();
    visited.clear();

    GetNr(N);
    match_diagonal.resize(2 * N - 1, -1);
    mat.resize(N, vector <int> (N, 0));
    graph.resize(2 * N - 1, vector <int> ());
    visited.resize(2 * N - 1, 0);


    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            GetNr(x);
            match_value[x] = -1;
            mat[i][j] = x;
        }
    }

    int diag = 0;
    for (j = N - 1; j >= 0; --j, ++diag) {
        x = 0; y = j;
        while (x < N && y < N) {
            graph[diag].pb(mat[x][y]);
            ++x; ++y;
        }
    }
    for (i = 1; i < N; ++i, ++diag) {
        x = i; y = 0;
        while (x < N && y < N) {
            graph[diag].pb(mat[x][y]);
            ++x; ++y;
        }
    }

    bool found = true;
    while (found) {
        found = false;
        fill(ALL(visited), 0);
        for (i = 0; i < 2 * N - 1; ++i) {
            if (!visited[i] && match_diagonal[i] == -1) {
                found = FoundNewPath(i) || found;
            }
        }
    }

    int cnt = 0;
    for (i = 0; i < 2 * N - 1; ++i) {
        cnt += match_diagonal[i] != -1;
    }

    if (cnt != 2 * N - 1) {
        printf("Bunicul este dezamagit!\n");
        return;
    }

    printf("DA");
    for (i = 2 * N - 2; i >= 0; --i) {
        printf(" %d", match_diagonal[i]);
    }
    putchar('\n');
}

int main(){
    string fileInput = "caroiaj";
#ifdef INFOARENA
    assert(freopen((fileInput + ".in").c_str(), "r", stdin));
    assert(freopen((fileInput + ".out").c_str(), "w", stdout));
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
        //  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int T;
    GetNr(T);
    while (T--) {
        Solve();
    }

    return 0;
}
