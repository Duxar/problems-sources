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

ULL N, K;
vector <vector <ULL> > mat, cnt;
int nextNr[4] = {0, 2, 1, 1};

int main(){
	string fileInput = "sudoku1";
	
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
	
	int i, j;
	ULL ans;
	
	ReadNo(N); ReadNo(K);
	mat.resize(N, vector <ULL> (N));
	cnt.resize(N, vector <ULL> (N));
	
	ans = mat[0][0] = 3;
	for (i = 1; i < N; ++i) {
		mat[0][i] = 2;
		mat[i][0] = 2;
		ans *= 4;
	}
	
	cout << ans; ENTER
	
	cnt[N - 1][0] = 1;
	for (i = N - 2; i > 0; --i) {
		cnt[i][0] = 2 * cnt[i + 1][0];
	}
	
	cnt[0][N - 1] = 2 * cnt[1][0];
	for (j = N - 2; j >= 0; --j) {
		cnt[0][j] = 2 * cnt[0][j + 1];
	}
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			mat[i][j] = 1;
		}
	}
	
	for (j = 0; j < N; ++j) {
		if (j > 0) {
			mat[0][j] = nextNr[mat[0][j - 1]];
		}
		while (K > cnt[0][j]) {
			K -= cnt[0][j];
			++mat[0][j];
		}
		if (j > 0) {
			while (mat[0][j] == mat[0][j - 1] || mat[0][j] == 0) {
				mat[0][j] = (mat[0][j] + 1) % 4;
			}
		}
	}
	
	for (i = 1; i < N; ++i) {
		mat[i][0] = nextNr[mat[i - 1][0]];
		while (K > cnt[i][0]) {
			K -= cnt[i][0];
			++mat[i][0];
		}
		while (mat[i][0] == mat[i - 1][0] || mat[i][0] == 0) {
			mat[i][0] = (mat[i][0] + 1) % 4;
		}
	}
	
	for (i = 1; i < N; ++i) {
		for (j = 1; j < N; ++j) {
			if (mat[i - 1][j] != mat[i][j - 1]) {
				mat[i][j] = 6 - mat[i - 1][j] - mat[i][j - 1];
			}
			else {
				mat[i][j] = 6 - mat[i - 1][j] - mat[i - 1][j - 1];
			}
		}
	}
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cout << mat[i][j] << ' ';
		}
		ENTER
	}

	return 0;
}