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

LL C, D, vmin = (LL) 1 << 60, CMMC;

LL cmmdc(LL a, LL b) {
	if (a < b) {
		return cmmdc(b, a);
	}
	if (b != 0) {
		return cmmdc(b, a % b);
	}
	return a;
}

LL cmmmc(LL a, LL b) {
	return (a * b) / cmmdc(a, b);
}

int main(){
	string fileInput = "alune";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

//	freopen("input.cpp", "r", stdin);
	
	int i;
	LL x;
	
	ReadNo(C); ReadNo(D);
	CMMC = 1;
	for (i = 0; i < C; ++i) {
		ReadNo(x);
		vmin = min(x, vmin);
		if (CMMC != -1) {
			CMMC = cmmmc(CMMC, x);
		}
		if (CMMC > 2000000000) {
			CMMC = -1;
		}
	}
	
	for (i = 0; i < D; ++i) {
		ReadNo(x);
		if (CMMC != -1) {
			x = x % CMMC;
		}
		if (x >= vmin) {
			printf("0");
		}
		else {
			printf("1");
		}
	}
	ENTER
	
	return 0;
}


