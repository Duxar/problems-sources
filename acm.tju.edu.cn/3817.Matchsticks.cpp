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

vector <int> cnt(10);
vector <string> dp;

void Solve() {
	int N, i, j;
	GetNr(N);


	dp.clear();
	dp.resize(1 + N);

	for (i = 1; i <= N; ++i) {
		for (j = 0; j < 10; ++j) {
			if (i == cnt[j]) {
				if (dp[i] == "" && j != 0) {
					dp[i] = dp[i] + (char) ('0' + j);
				}
				else {
					string aux = ((string) ("")) + (char) ('0' + j);
					if (aux[0] == '0') {
						continue;
					}
					if (aux.length() < dp[i].length() || (aux < dp[i] && aux.length() == dp[i].length())) {
						dp[i] = aux;
					}
				}
			}
			else {
				if (i > cnt[j] && dp[i - cnt[j]] != "") {
					string res = dp[i - cnt[j]] + (char) ('0' + j);
					if (res[0] == '0' && res.length() > 1) {
						continue;
					}
					if (res.length() < dp[i].length() || (res < dp[i] && res.length() == dp[i].length()) || dp[i] == "") {
						dp[i] = res;
					}
				}
			}
		}
	}

	PutNr(dp[N], ' ');

	dp.clear();
	dp.resize(1 + N);

	for (i = 1; i <= N; ++i) {
		for (j = 0; j < 10; ++j) {
			if (i == cnt[j]) {
				if (dp[i] == "") {
					dp[i] = dp[i] + (char) ('0' + j);
				}
				else {
					string aux = ((string) ("")) + (char) ('0' + j);
					if (aux.length() > dp[i].length() || (aux > dp[i] && aux.length() == dp[i].length())) {
						dp[i] = aux;
					}
				}
			}
			else {
				if (i > cnt[j] && dp[i - cnt[j]] != "") {
					string res = dp[i - cnt[j]] + (char) ('0' + j);
					if (res.length() > dp[i].length() || (res > dp[i] && res.length() == dp[i].length())) {
						dp[i] = res;
					}
				}
			}
		}
	}

	PutNr(dp[N], '\n');
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
//	   0  1  2  3  4  5  6  7  8  9
//	 = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	cnt[0] = 6;
	cnt[1] = 2;
	cnt[2] = 5;
	cnt[3] = 5;
	cnt[4] = 4;
	cnt[5] = 5;
	cnt[6] = 6;
	cnt[7] = 3;
	cnt[8] = 7;
	cnt[9] = 6;

	cin >> t;
	while (t--) {
		Solve();
	}

	return 0;
}
