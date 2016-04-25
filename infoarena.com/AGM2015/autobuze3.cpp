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

#define destination first
#define fee second

int N, M, total;
vector <vector <pair <int, int> > > graph;
vector <vector <int> > final_graph;
vector <int> weight, root;
vector <bool> visited;
vector <deque <int> > drivers;


int GetRoot(int node) {
    if (root[node] != node) {
        root[node] = GetRoot(root[node]);
    }
    return root[node];
}

void Unite(int node1, int node2) {
    node1 = GetRoot(node1);
    node2 = GetRoot(node2);
    if (weight[node1] < weight[node2]) {
        swap(node1, node2);
    }
    root[node2] = node1;
    weight[node1] += weight[node2];
    while (drivers[node2].size()) {
        int driver;
        drivers[node1].pb(driver = drivers[node2].front());
        drivers[node2].pop_front();
        printf("Move %d %d %d\n", driver, node2, node1);
    }
}

void CountPathLength(int now) {
    for (auto to: final_graph[now]) {
        CountPathLength(to);
    }
    weight[now] = 0;
    int best = now;
    for (auto to: final_graph[now]) {
        if (weight[GetRoot(to)] > weight[best]) {
            best = to;
        }
    }

    weight[now] = 1;
    root[now] = now;
    drivers[now].pb(now);

    if (best != now) {
        printf("Drive %d %d %d\n", GetRoot(best), best, now);
        Unite(now, best);

        for (auto to: final_graph[now]) {
            if (to != best) {
                printf("Drive %d %d %d\n", GetRoot(to), to, now);
                Unite(now, GetRoot(to));
            }
        }
    }
}

void Solve() {
    int x, y, c, i, j;
    GetNr(N); GetNr(M);
    total = 0;

    graph.clear();
    weight.clear();
    root.clear();
    visited.clear();
    final_graph.clear();
    drivers.clear();

    graph.resize(1 + N);
    weight.resize(1 + N, 1);
    root.resize(1 + N);
    visited.resize(1 + N);
    final_graph.resize(1 + N);
    drivers.resize(1 + N);

    for (i = 0; i < M; ++i) {
        GetNr(x); GetNr(y); GetNr(c);

        graph[x].pb(mp(y, c));
        graph[y].pb(mp(x, c));
    }

    for (i = 1; i <= N; ++i) {
        root[i] = i;
    }

    priority_queue <tuple <int, int, int> > heap;
    heap.push(mt(0, 1, 0));
    while (heap.size()) {
        int c, now, from;
        tie(c, now, from) = heap.top();
        heap.pop();
        if (visited[now]) {
            continue;
        }
        total += -c;
        final_graph[from].pb(now);
        visited[now] = true;

        for (auto to: graph[now]) {
            if (!visited[to.destination]) {
                heap.push(mt(-to.fee, to.destination, now));
            }
        }
    }

    printf("%d\n", total);

    CountPathLength(1);

    printf("Gata\n");
}

int main(){
    string fileInput = "autobuze3";
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

    GetNr(t);
    while (t--) {
        Solve();
    }

    return 0;
}
