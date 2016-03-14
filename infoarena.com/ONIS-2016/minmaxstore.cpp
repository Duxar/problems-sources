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
#include <unordered_set>
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



void Solve() {
	int N, M, i;
	unordered_set <int> pmax, pmin;
	vector <pair <int, int> > updates;

	GetNr(N); GetNr(M);
	updates.resize(M);
	for (i = 0; i < M; ++i) {
		GetNr(updates[i].fi); GetNr(updates[i].se);
	}

	GetNr(i);
	pmin.insert(i);

	GetNr(i);
	pmax.insert(i);

	for (i = M - 1; i >= 0; --i) {
		if (pmin.find(updates[i].fi) != pmin.end()) {
			pmin.insert(updates[i].se);
		}
		else {
			if (pmin.find(updates[i].se) != pmin.end()) {
				pmin.erase(updates[i].se);
			}
		}

		if (pmax.find(updates[i].se) != pmax.end()) {
			pmax.insert(updates[i].fi);
		}
		else {
			if (pmax.find(updates[i].fi) != pmax.end()) {
				pmax.erase(updates[i].fi);
			}
		}
	}

	if (pmin.size() == N && pmax.size() == N) {
		PutNr("Popeala", '\n');
	}

	else if (pmin.size() == N) {
		PutNr("Popel", '\n');
	}

	else if (pmax.size() == N) {
		PutNr("Popita", '\n');
	}

	else {
		PutNr("Comisarul", '\n');
	}


}

int main(){
	string fileInput = "minmaxstore";
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

	cin >> t;
	while (t--) {
		Solve();
	}



	return 0;
}


