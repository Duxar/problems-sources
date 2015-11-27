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

int K, N, M;
vector <pair <int, int> > mihaela, decanu;

pair <int, int> get_intersection (pair <int, int> a, pair <int, int> b) {
	if (a.second < b.first) {
		return mp(0, 0);
	}
	if (b.second < a.first) {
		return mp(0, 0);
	}
	return mp(max(a.first, b.first), min(a.second, b.second));
}

int main(){
	string fileInput = "licenta";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
#endif

	int i, j;
	ReadNo(K);
	ReadNo(N);
	mihaela.resize(N);
	for (i = 0; i < N; ++i) {
		ReadNo(mihaela[i].first);
		ReadNo(mihaela[i].second);
	}
	sort(ALL(mihaela));

	ReadNo(M);
	decanu.resize(M);
	for (i = 0; i < M; ++i) {
		ReadNo(decanu[i].first);
		ReadNo(decanu[i].second);
	}
	sort(ALL(decanu));

	i = 0; j = 0;
	while (i < N && j < M) {
		pair <int, int> aux = get_intersection(mihaela[i], decanu[j]);
		int lg = aux.second - aux.first;
		if (lg >= K) {
			printf("%d %d\n", aux.first, aux.first + K);
			return 0;
		}
		if (mihaela[i].second > decanu[j].second) {
			++j;
		}
		else {
			++i;
		}
	}


	return 0;
}