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

int X, Y;
vector <int> facts(11);
map <int, vector<int> > ican;

void prefact() {
	facts[0] = 1;
	for (int i = 1; i < 11; ++i) {
		facts[i] = i * facts[i - 1];
	}
}

void fillican() {
	int i, j;
	for (i = 1; i < (1 << 11); ++i) {
		int nr = 0;
		for (j = 1; (1 << j) <= i; ++j) {
			if (i & (1 << j)) {
				nr += facts[j];
			}
		}
		ican[nr].pb(i);
	}
}

int main(){
	string fileInput = "sum";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
#endif

	int i;
	vector<int> :: iterator it1, it2;
	prefact();
	fillican();

	ReadNo(X); ReadNo(Y);
	while (X + Y) {
		bool found = false;
		if (ican.find(X) == ican.end()) {
			cout << "No\n";
		}
		else if (ican.find(Y) == ican.end()) {
			cout << "No\n";
		}
		else {
			for (it1 = ican[X].begin(); it1 != ican[X].end() && !found; ++it1) {
				for (it2 = ican[Y].begin(); it2 != ican[Y].end() && !found; ++it2) {
					if ((*it1 & *it2) == 0) {
						cout << "Yes\n";
						found = true;
					}
				}
			}
			if (!found) {
				cout << "No\n";
			}
		}
		ReadNo(X); ReadNo(Y);
	}

	return 0;
}