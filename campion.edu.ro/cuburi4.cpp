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

int N, K;

int eliminate_digits(int x) {
	int i, j, cnt = 3, ans = 0, pmin, lg;
	int s[10];
	i = 0;
	while (x) {
		s[i++] = x % 10;
		x /= 10;
	}
	lg = i;
	j = i - 1;
	i = 0;
	while (i < j) {
		swap(s[i], s[j]);
		++i; --j;
	}
	pmin = 0;
	for (i = 1;i < min(4, lg); ++i) {
		if (s[i] < s[pmin] && s[i] != 0) {
			pmin = i;
		}
	}
	cnt -= pmin;
	ans = s[pmin] - 0;
	for (i = pmin + 1; i < lg; ++i) {
		pmin = i;
		for (j = i + 1; j < lg && j <= i + cnt; ++j) {
			if (s[j] < s[pmin]) {
				pmin = j;
			}
		}
		cnt -= pmin - i;
		ans = ans * 10 + (s[pmin] - 0);
		i = pmin;
	}
	while (cnt > 0) {
		ans /= 10;
		--cnt;
	}
	return ans;
}

int main(){
	string fileInput = "cuburi4";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

//	freopen("input.cpp", "r", stdin);
	
	int i, j, total, ans, p, q, x;
	
	ReadNo(N); ReadNo(K);
	
	total = 0;
	ans = 0;
	q = 0;
	p = -1;
	
	while ((total + q + p + 2) * 6 <= N) {
		++ans;
		p += 2;
		q += p;
		total += q;
	}
	
	printf("%d\n", ans);
	
	p = 1;
	q = 0;
	total = 0;
	for (i = 1; i <= K; ++i, p += 2) {
		total += p;
		for (j = total * 6; j; --j) {
			ReadNo(x);
			printf("%d ", eliminate_digits(x));
		}
	}
	return 0;
}