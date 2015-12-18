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

int N, M, ans;
map <pair <int, int>, vector< pair <int, int> > > table;
vector <vector <int> > matrix;

int main(){
	string fileInput = "lightson";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

	int i, j, a, b, x, y, k;

	ReadNo(N); ReadNo(M);
	matrix.resize(N + 1, vector <int> (N + 1));
	for (i = 0; i < M; ++i) {
		ReadNo(a); ReadNo(b); ReadNo(x); ReadNo(y);
		table[mp(a, b)].pb(mp(x, y));
	}

	queue <pair <int, int> > que;
	que.push(mp(1, 1));
	matrix[1][1] = 2;
	while (!que.empty()) {
		a = que.front().first;
		b = que.front().second;
		que.pop();

		for (auto room: table[mp(a, b)]) {
			if (matrix[room.first][room.second] == 0) {
				matrix[room.first][room.second] = 1;
				for (k = 0; k < 4; ++k) {
					x = room.first + dx4[k];
					y = room.second + dy4[k];
					if (x && x <= N && y && y <= M && matrix[x][y] == 2) {
						que.push(mp(x, y));
						matrix[x][y] = 2;
					}
				}
			}
		}

		for (k = 0; k < 4; ++k) {
			x = a + dx4[k];
			y = b + dy4[k];
			if (x && x <= N && y && y <= M && matrix[x][y] == 1) {
				que.push(mp(x, y));
				matrix[x][y] = 2;
			}
		}
	}

	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			ans += matrix[i][j] != 0;
		}
	}


	cout << ans;
	ENTER


	return 0;
}


