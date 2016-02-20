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
void ReadNo(T &_value) {
	T _sign = 1;
	char ch;
	_value = 0;
	while(!isdigit(ch = getchar())) {
		ch == '-' ? _sign = -1 : _sign = 1 ;
	}
	do {
		_value = _value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	_value *= _sign;
}

template <class T>
void WriteNo(T _value, char _ch = ' ') {
	cout << _value << _ch;
}

int N;
vector <vector <pair <int, int> > > graph;
vector <vector <int> > mat;
vector <int> dist, best;
vector <bool> visited;

void Solve() {
	int i, j, x;
	graph.clear(); graph.resize(N + 1);
	dist.clear(); dist.resize(N + 1);
	best.clear(); best.resize(N + 1);
	visited.clear(); visited.resize(N + 1);
	for (i = 1; i <= N; ++i) {
		ReadNo(dist[i]);
	}
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			ReadNo(x);
			if (x) {
				graph[i].pb(mp(j, dist[j]));
			}
		}
	}

	priority_queue <pair <int, int> > que;
	int node, val, to;

	que.push(mp(dist[1], 1));
	best[1] = 1;
	while (!que.empty()) {
		node = que.top().second;
		val = que.top().first;
		que.pop();
		if (visited[node]) {
			continue;
		}
		visited[node] = 1;
		for (i = 0; i < graph[node].size(); ++i) {
			to = graph[node][i].first;
			if (!visited[to] && val > graph[node][i].second) {
				que.push(mp(graph[node][i].second, to));
				best[to] += best[node];
			}
		}

	}
	if (best[N] > 0) {
		WriteNo(best[N], '\n');
	}
	else {
		cout << "impossible\n";
	}

}

int main(){
	string fileInput = "sum";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
		//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "r", stdin);
#endif
#endif

	int i, t;
	ReadNo(N);
	while (N) {
		Solve();
		ReadNo(N);
	}

	return 0;
}
