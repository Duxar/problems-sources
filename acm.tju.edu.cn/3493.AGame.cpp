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

int N, ans;
vector <vector <int> > graph;
vector <bool> visited;
vector <int> match;

bool found_new_path(int iam) {
	if (visited[iam]) {
		return false;
	}
	visited[iam] = true;
	for (int i = 0; i < graph[iam].size(); ++i) {
		int to = graph[iam][i];
		if (match[to] == -1 || found_new_path(match[to])) {
			match[to] = iam;
			match[iam] = to;
			return true;
		}
	}
	return false;
}



void Solve() {
	int x, cnt, i, j, y;

	graph.clear();
	visited.clear();
	match.clear();

	graph.resize(N);
	visited.resize(N);
	match.resize(N, -1);

	for (i = 0; i < N; ++i) {
		scanf("%d:[%d]", &x, &cnt);
		for (j = 0; j < cnt; ++j) {
			scanf("%d", &y);
			graph[x].pb(y);
			graph[y].pb(x);
		}
	}
	ans = 0;
	bool found = true;
	while (found) {
		fill(ALL(visited), 0);
		found = false;
		for (int node = 0; node < N; ++node) {
			if (!visited[node] && match[node] == -1) {
				bool res = found_new_path(node);
				ans += res;
				found = res || found;
			}
		}
	}

//	int ans = 0;
//	fill(ALL(visited), 0);
//	for (i = 0; i < N; ++i) {
//		if (visited[i] == 0 && match[i] != -1 && visited[match[i]] == 0) {
//			++ans;
//			visited[i] = 1;
//			visited[match[i]] = 1;
//		}
//	}

	printf("%d\n", ans);


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

	int i;

	cin >> N;
	while (!cin.eof()) {
		Solve();
		cin >> N;
	}

	return 0;
}
