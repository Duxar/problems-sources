	// http://acm.tju.edu.cn/toj/showp4069.html - ACCEPTED

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

template <class T>
void AddNr(T &a, T b) {
	a = a + b;
	while (a >= MOD1) {
		a -= MOD1;
	}
	while (a < 0) {
		a += MOD1;
	}
}

void solve(int t, string s) {
	vector <int> fr(10), frs(10);
	int i, rez = MOD1;

	while (t) {
		fr[t % 10]++;
		t /= 10;
	}

	for (i = 0; i < s.length(); ++i) {
		frs[s[i] - '0']++;
	}

	for (i = 0; i < 10; ++i) {
		if (i != 9 && i != 6 && i != 2 && i != 5) {
			if (fr[i]) {
				rez = min(rez, frs[i] / fr[i]);
			}
		}
	}
	if (fr[5] || fr[2]) {
		rez = min(rez, (frs[5] + frs[2]) / (fr[5] + fr[2]));
	}
	if (fr[9] || fr[6]) {
		rez = min(rez, (frs[6] + frs[9]) / (fr[6] + fr[9]));
	}
	cout << rez << '\n';
}

int main(){
		//	string fileInput = "sum";
		//#ifdef INFOARENA
		//	freopen((fileInput + ".in").c_str(), "r", stdin);
		//	freopen((fileInput + ".out").c_str(), "w", stdout);
		//#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
		//#endif

	int i, t;
	string s;
	while (cin >> t >> s) {
		solve(t, s);
	}

	return 0;
}
