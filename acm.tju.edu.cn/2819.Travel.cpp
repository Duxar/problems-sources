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

void Solve() {
	int N, M, S, T, i;
	vector <vector <pair <int, int> > > graph;
	GetNr(N); GetNr(M);
	GetNr(S); GetNr(T);
	graph.resize(1 + N);

	int x, y, d;

	for (i = 0; i < M; ++i) {
		GetNr(x); GetNr(y); GetNr(d);
		graph[x].pb(mp(y, d));
		graph[y].pb(mp(x, d));
	}

	priority_queue < pair <int, int> > heap;
	vector <bool> visited(1 + N);
	vector <int> dp(1 + N, MOD1);

	heap.push(mp(0, S));
	dp[S] = 0;

	while (heap.size()) {
		int d = -heap.top().first;
		int now = heap.top().second;
		heap.pop();
		if (dp[now] < d) {
			continue;
		}
		for (i = 0; i < graph[now].size(); ++i) {
			int to = graph[now][i].first;
			int dto = graph[now][i].second;
			if (dp[to] > dp[now] + dto) {
				dp[to] = dp[now] + dto;
				heap.push(mp(-dp[to], to));
			}
		}
	}
	if (dp[T] == MOD1) {
		PutNr(-1, '\n');
	}
	else {
		PutNr(dp[T], '\n');
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
	//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

	int i, t;
	cin >> t;
	while (t--) {
		Solve();
	}

	return 0;
}
