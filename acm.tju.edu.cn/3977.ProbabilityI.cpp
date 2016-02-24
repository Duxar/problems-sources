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
vector <vector <double> > dp, values;

void Solve() {
	int i, steps, j;
	double ans = 0;
	values.resize(N - 1, vector <double> (3));
	for (i = 0; i + 1 < N; ++i) {
		for (j = 0; j < 3; ++j) {
			cin >> values[i][j];
		}
	}
	steps = N * N + 5;
	dp.clear();
	dp.resize(N, vector<double> (steps));
	dp[0][0] = 1;
	for (j = 1; j < steps; ++j) {
		dp[0][j] = dp[0][j - 1] * values[0][0];
	}
	for (i = 1; i < N; ++i) {
		for (j = 1; j < steps; ++j) {
			if (i < N - 1) {
				dp[i][j] += dp[i][j - 1] * values[i][0];
			}
			dp[i][j] += dp[i - 1][j - 1] * values[i - 1][1];
			if (i > 1) {
				dp[i][j] += dp[i - 2][j - 1] * values[i - 2][2];
			}
		}
	}
	for (j = 0; j < steps; ++j) {
		ans += dp[N - 1][j] * j;
	}

	printf("%.2lf\n", ans);

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

	int i;

	while (cin >> N) {
		Solve();
	}

	return 0;
}


