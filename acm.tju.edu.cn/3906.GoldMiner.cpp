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

#define xx 0
#define yy 1
#define ttime 2
#define vvalue 3

int CrossProduct(pair <int, int> A, pair <int ,int> B) {
	return A.first * B.second - A.second * B.first;
}

bool Compr(vector <int> a, vector <int> b) {
	int valcp;
	if ((valcp = CrossProduct(mp(a[xx], a[yy]), mp(b[xx], b[yy]))) == 0) {
		return a[yy] < b[yy];
	}
	return valcp > 0;
}

int N, T;

void Solve() {
	int i, j, k, q;
	vector <int> dp(T + 1);
	vector <vector <int> > golds(N, vector <int> (4));
	
	for (i = 0; i < N; ++i) {
		ReadNo(golds[i][xx]); ReadNo(golds[i][yy]);
		ReadNo(golds[i][ttime]); ReadNo(golds[i][vvalue]);
	}
	
	sort(ALL(golds), Compr);
	
	for (i = 0; i < N; ++i) {
		j = i + 1;
		while (j < N  && CrossProduct(mp(golds[i][xx], golds[i][yy]), mp(golds[j][xx], golds[j][yy])) == 0) {
			++j;
		}
		for (k = T; k; --k) {
			int time_aux = 0, val_aux = 0;
			for (q = i; q < j; ++q) {
				time_aux += golds[q][ttime];
				val_aux += golds[q][vvalue];
				if (k >= time_aux && (dp[k - time_aux] > 0 || k == time_aux)) {
					dp[k] = max(dp[k], dp[k - time_aux] + val_aux);
				}
			}
		}
		i = j - 1;
	}
	
	int ans = 0;
	for (i = 1; i <= T; ++i) {
		ans = max(ans, dp[i]);
	}
	WriteNo(ans, '\n');
}

int main(){
	string fileInput = "sum";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
#endif
#endif
	
	int i = 0;
	
	while (cin >> N >> T) {
		++i;
		printf("Case %d: ", i);
		Solve();
	}
	
	return 0;
}


