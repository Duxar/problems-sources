#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <algorithm>
#include <bitset>
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
#define LL long long
#define ULL unsigned long long
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

template <class T>
void ReadNo(T &_value) {
	T _sign = 1;
	char ch;
	_value = 0;
	while(!isdigit(ch = getchar())) {
		(ch == '-') && (_sign = -1);
	}
	do {
		_value = _value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	_value *= _sign;
}

int N, M;
vector <vector <int> > graph;
vector <bool> viz, color;

void solve(int iam, int cnt, int pw) {
	viz[iam] = 1;
	if (cnt == 0) {
		cnt = -1;
	}
	if (cnt == -(pw + 1)) {
		cnt = pw;
	}
	if (cnt > 0) {
		color[iam] = 1;
	}
	for (auto to: graph[iam]) {
		if (!viz[to]) {
			solve(to, cnt - 1, pw);
		}
	}
}

int main(){
	string fileInput = "psychtraining";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
#endif

	int i, x, y, cnt, pw;

	ReadNo(N); ReadNo(M);
	graph.resize(N + 1);
	viz.resize(N + 1);
	color.resize(N + 1);

	for (i = 0; i < M; ++i) {
		ReadNo(x); ReadNo(y);
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for (cnt = 0, pw = 1; pw <= N; pw <<= 1, ++cnt);
	cout << cnt << '\n';
	for (pw = 1; pw <= N; pw <<= 1) {
		fill(ALL(color), 0);
		fill(ALL(viz), 0);
		for (i = 1; i <= N; ++i) {
			if (!viz[i]) {
				solve(i, pw, pw);
			}
		}
		for (i = 1; i <= N; ++i) {
			if (color[i]) {
				cout << 'a';
			}
			else {
				cout << 'b';
			}
		}
		ENTER
	}

	return 0;
}


