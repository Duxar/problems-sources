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


void solve() {
	int N, i, c1, c2, j, prec = -1, now, cnt = 0;
	unsigned char d1, d2;
	ReadNo(N);
	for (i = 0, j = 1; i < N; ++i, ++j) {
		d1 = getchar(); c1 = d1 - '0';
		d2 = getchar(); c2 = d2 - '0';
		
		now = c1 + c2;
		if (now != 9) {
			if (now > 9 && cnt) {
				if (prec != -1)
					cout << prec + 1;
				else {
					cout << 1;
				}
				while (cnt--) {
					cout << 0;
				}
				prec = now % 10;
				cnt = 0;
			}
			else if (now < 9 && cnt) {
				if (prec != -1)
					cout << prec;
				while (cnt--) {
					cout << 9;
				}
				cnt = 0;
				prec = now;
			}
			else {
					//				if (prec != -1)
					//					cout << prec + now / 10;
				if (prec == -1 && now >= 10) {
					cout << 1;
				}
				else if (prec != -1 && now >= 10) {
					cout << prec + 1;
				}
				else if (prec != -1 && now < 10) {
					cout << prec;
				}
				prec = now % 10;
			}
		}
		else {
			++cnt;
		}
	}
	
	if (cnt) {
		if (prec != -1)
			cout << prec;
		while (cnt--) {
			cout << 9;
		}
	}
	else {
		if (prec != -1) {
			cout << prec;
		}
	}
	
	ENTER
	
}

int main(){
	string fileInput = "staropramen";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE

#endif
#endif
	
	int i, t;
	
	ReadNo(t);
	for (i = 1; i <= t; ++i) {
		solve();
	}
	
	return 0;
}


