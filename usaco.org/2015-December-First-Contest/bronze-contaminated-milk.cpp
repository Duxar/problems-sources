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

	// N - friends, M - types of milk, D - drinks, S - sicks

int N, M, D, S, ans;

vector <vector <pair <int, int> > > drinks;
bitset <51> poison;

int main(){
	string fileInput = "badmilk";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

	int i, p, m, t;

	ReadNo(N); ReadNo(M); ReadNo(D); ReadNo(S);

	drinks.resize(N + 1);
	poison.set();
	for (i = 0; i < D; ++i) {
		ReadNo(p); ReadNo(m); ReadNo(t);
		drinks[p].pb(mp(t, m));
	}

	for (i = 0; i < S; ++i) {
		ReadNo(p); ReadNo(t);
		bitset <51> aux;
		for (auto milk: drinks[p]) {
			if (milk.first < t) {
				aux[milk.second] = 1;
			}
		}
		poison &= aux;
	}

	for (auto person: drinks) {
		for (auto drink: person) {
			if (poison[drink.second]) {
				++ans;
				break;
			}
		}
	}

	cout << ans;
	ENTER

	return 0;
}


