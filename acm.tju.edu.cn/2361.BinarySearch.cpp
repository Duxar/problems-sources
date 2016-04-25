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

int M, N, K;
vector <int> values, table;
vector <pair <int, int> > ans;

void BinarySearch(int x)
{
	int p, q, i, L;

	p = 0;   /* Left border of the search  */
	q = N-1; /* Right border of the search */
	L = 0;   /* Comparison counter         */
	while (p <= q) {
		i = (p + q) / 2;
		++L;
		if (values[i] == x) {
//			printf("Found item i = %d"
//				   " in L = %d comparisons\n", i, L);
			if (L == K) {
				table.pb(N);
			}
			return;
		}
		if (x < values[i])
			q = i - 1;
		else
			p = i + 1;
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

	int i, j;

	GetNr(M); GetNr(K);
	values.resize(10001);
	for (i = 1; i <= 10000; ++i) {
		values[i - 1] = i;
	}

	for (i = M; i <= 10000; ++i) {
		N = i;
		BinarySearch(values[M]);
	}

	sort(ALL(table));

	for (i = 0; i < table.size(); ++i) {
		for (j = i + 1; j < table.size(); ++j) {
			if (table[j] - table[j - 1] != 1) {
				break;
			}
		}
		ans.pb(mp(table[i], table[j - 1]));
		i = j - 1;
	}

	PutNr(ans.size(), '\n');
	for (i = 0; i < ans.size(); ++i) {
		PutNr(ans[i].fi); PutNr(ans[i].se, '\n');
	}
    
	return 0;
}
