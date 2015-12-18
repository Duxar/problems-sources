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

int T, A, B, ans, cnt;
vector <int> values;
vector <bool> ican;

void findNr() {
	int a, b, nr;
	deque <pair <int, int> > deq;
	deq.pb(mp(0, 0));

	while (!deq.empty()) {
		a = deq.front().first;
		b = deq.front().second;
		deq.pop_front();
		nr = a * A + b * B;
		if (nr > T) {
			continue;
		}
		if (ican[nr]) {
			continue;
		}
		values.pb(nr);
		ican[nr] = 1;
		++cnt;
		deq.pb(mp(a + 1, b));
		deq.pb(mp(a, b + 1));
	}
}

int main(){
	string fileInput = "feast";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

	int i, j = 0, y;

	ReadNo(T); ReadNo(A); ReadNo(B);
	ican.resize(T + 1);
	findNr();
	values.resize(cnt);
	for (j = 0, i = 0; i <= T; ++i) {
		if (ican[i]) {
			values[j++] = i;
		}
	}
	for (auto x: values) {
		ans = max(ans, x);
		y = *(upper_bound(ALL(values), T - (x / 2)) - 1);
		ans = max(ans, x / 2 + y);
	}
	cout << ans << '\n';

	return 0;
}


