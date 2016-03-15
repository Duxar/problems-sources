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

int N, M;
vector <int> country;
map <int, int> cnt;
map <int, bool> visitedcountry;
vector <bool> visitednode;
vector <vector <int> > graph;

int Explore(int now) {
	int res = 1, i;
	visitednode[now] = 1;
	visitedcountry[country[now]] = 1;
	for (i = 0; i < graph[now].size(); ++i) {
		int to = graph[now][i];
		if (!visitednode[to] && country[now] == country[to]) {
			res += Explore(to);
		}
	}
	return res;
}

void Solve() {
	int i, x, y, total = 0;
	GetNr(M);

	cnt.clear();
	visitedcountry.clear();
	country.clear();
	graph.clear();
	visitednode.clear();

	country.resize(1 + N);
	graph.resize(1 + N);
	visitednode.resize(1 + N);

	for (i = 1; i <= N; ++i) {
		GetNr(country[i]);
		++cnt[country[i]];
	}

	for (i = 0; i < M; ++i) {
		GetNr(x); GetNr(y);
		graph[x].pb(y);
		graph[y].pb(x);
	}

	for (i = 1; i <= N; ++i) {
		bool visc = visitedcountry.find(country[i]) != visitedcountry.end();
		if (!visc && !visitednode[i]) {
			int ans = Explore(i);
			if (ans != cnt[country[i]]) {
				++total;
			}
		}
	}
	PutNr(total, '\n');

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
