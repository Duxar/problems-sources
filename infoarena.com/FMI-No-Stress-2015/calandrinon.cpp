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

int N, pmax;
char *S;

vector <vector <int> > positions(26);
vector <pair <int, int> > ans;
vector <int> viz(26);

int main(){
	string fileInput = "calandrinon";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
#endif

	int i, j;
	char ch;
	ReadNo(N);
	for (i = 0; i < N; ++i) {
		ch = getchar();
		positions[ch - 'a'].pb(i);
	}

	bool done = false;
	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			if (viz[i] == 0 && positions[i].size() > 0) {
				int fpos = lower_bound(ALL(positions[i]), pmax) - positions[i].begin();
				fpos = positions[i][fpos];
				for (j = i + 1; j < 26; ++j) {
					if (viz[j] == 0 && positions[j].size() > 0) {
						int spoz = *(positions[j].end() - 1);
						if (spoz < fpos) {
							break;
						}
					}
				}
				if (j == 26) {
					viz[i] = 1;
					ch = 'a' + i;
					pmax = fpos;
					cout << ch;
					break;
				}
			}
		}
	}
	ENTER


	return 0;
}