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

void Clear(vector <vector <int> > &mat, int x, int y) {

	if (mat[x + 1][y]) {
		mat[x + 1][y] = 0;
		Clear(mat, x + 1, y);
	}
	if (mat[x][y + 1]) {
		mat[x][y + 1] = 0;
		Clear(mat, x, y + 1);
	}

}


void Solve() {
	int N, M, i, j, x, y, cnt1 = 0;
	vector <vector <int> > mat, sum;
	GetNr(N); GetNr(M);
	mat.resize(2 + N, vector <int> (2 + M));
	sum.resize(2 + N, vector <int> (2 + M));
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= M; ++j) {
			GetNr(mat[i][j]);
//			mat[i][j] = mat[i][j] + mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
//			cnt1 += mat[i][j];
		}
	}

	if (mat[N][M] == 1) {
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
	}
	return ;

	if (cnt1 == 0) {
		cout << "Bob\n";
		return;
	}

	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= M; ++j) {
			for (x = i; x <= N; ++x) {
				for (y = j; y <= M; ++y) {
					int sum = mat[x][y] + mat[i - 1][j - 1] - mat[x][j - 1] - mat[i - 1][y];
					if (sum == cnt1) {
						cout << "Alice\n";
						return;
					}
				}
			}
		}
	}

//	int fr = 0;
//	for (i = 1; i <= N; ++i) {
//		for (j = 1; j <= M; ++j) {
//			if (mat[i][j]) {
//				Clear(mat, i, j);
//				++fr;
//			}
//		}
//	}
//


	if (cnt1 % 2) {
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
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
	GetNr(t);
	while (t--) {
		Solve();
	}

	return 0;
}
