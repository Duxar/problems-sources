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
#define NMAX 20002
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

int N, Q;
char str[20002];
int aib[NMAX], positions[NMAX], original_pos[NMAX];
LL hashv[NMAX], power_base[NMAX];
vector <int>answers;
vector <vector <int> > queries;

LL GetHashInterval(int st, int en) {
    return hashv[en] - hashv[st - 1] * power_base[en - st + 1];
}

bool CmpString(int st1, int st2) {
    int lg = min(N - st1 + 1, N - st2 + 1);
    int pos = -1;
    for (int pw = (1 << 15); pw; pw >>= 1) {
        int aux = pos + pw;
        if (aux < lg) {
            if (str[st1] == str[st2]) {
                rand();
            }
            if (GetHashInterval(st1, st1 + aux) == GetHashInterval(st2, st2 + aux)) {
                pos = aux;
            }
        }
    }

    if (str[st1] == str[st2]) {
        rand();
    }

    if (pos == lg - 1) {
        return st1 < st2;
    }

    return str[st1 + pos + 1] < str[st2 + pos + 1];
}

bool CmpTuples(tuple <int, int, int> t1, tuple <int, int, int> t2) {
    return get<0>(t1) > get<0>(t2);
}

void InsertAib(int pos, int val) {
    for (;pos <= N; pos += step(pos)) {
        aib[pos] += val;
    }
}

int QueryAib(int pos) {
    int ans = 0;
    for (; pos; pos -= step(pos)) {
        ans += aib[pos];
    }
    return ans;
}

void Solve() {
    int i, j, l, k, last_valid = 0;
    scanf("%s", str + 1);

    N = strlen(str + 1);

//  aib.clear();
//  hashv.clear();
//  power_base.clear();
//  positions.clear();
//  original_pos.clear();
//
//
//  aib.resize(1 + N);
//  hashv.resize(1 + N);
//  power_base.resize(1 + N);
//  positions.resize(1 + N);
//  original_pos.resize(1 + N);

    power_base[0] = 1;
    for (i = 1; i <= N; ++i) {
        positions[i] = i;
        hashv[i] = hashv[i - 1] * BASE + str[i];
    }

    sort(positions + 1, positions + 1 + N, CmpString);
    for (i = 1; i <= N; ++i) {
        original_pos[positions[i]] = i;
    }

    queries.clear();
    answers.clear();

    GetNr(Q);
    queries.resize(1 + N);
    answers.resize(Q);

    for (i = 0; i < Q; ++i) {
        GetNr(l); GetNr(k);
//      queries[i] = mt(l, k, i);
        answers[i] = k;
        queries[l].pb(i);
    }
    memset(aib, 0, sizeof(aib));
    for (int lg = N; lg; --lg) {

        for (j = last_valid + 1; j < N - lg + 2; ++j) {
            InsertAib(original_pos[j], 1);
        }
        last_valid = j - 1;


        for (auto pos1: queries[lg]) {
            int pos = 0;
            for (int pw = (1 << 15); pw; pw >>= 1) {
                int aux = pos + pw;
                if (aux <= N) {
                    if (QueryAib(aux) < answers[pos1]) {
                        pos = aux;
                    }
                }
            }
            answers[pos1] = positions[pos + 1];
        }
    }

    for (i = 0; i < Q; ++i) {
//      printf("%d\n", answers[i]);
        cout << answers[i] << '\n';
    }
}

int main(){
    string fileInput = "klsecv";
#ifdef INFOARENA
    freopen((fileInput + ".in").c_str(), "r", stdin);
    freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
    freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
        //  freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

    int i, t;

    power_base[0] = 1;
    for (i = 1; i < NMAX; ++i) {
        power_base[i] = power_base[i - 1] * BASE;
    }

    GetNr(t);
    while (t--) {
        Solve();
    }

    return 0;
}
