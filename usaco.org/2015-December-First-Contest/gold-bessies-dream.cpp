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

int N, M;
vector <vector <int> > mat, best[2];

int main(){
	string fileInput = "dream";

	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);

	int i, j, k;
	vector<int> to(3);

	ReadNo(N); ReadNo(M);
	mat.resize(N + 2, vector<int> (M + 2));
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= M; ++j) {
			ReadNo(mat[i][j]);
		}
	}

	best[0].resize(N + 1, vector<int> (M + 1, MOD1));
	best[1].resize(N + 1, vector<int> (M + 1, MOD1));

	queue <vector <int> > que;
	que.push({1, 1, 0});
	best[0][1][1] = 0;
	while (!que.empty()) {
		vector <int> now = que.front();
		que.pop();
		for (k = 0; k < 4; ++k) {
			to[0] = now[0] + dx4[k];
			to[1] = now[1] + dy4[k];
			to[2] = now[2];
			if (mat[to[0]][to[1]] != 0) {
				int step = 1;
				bool purple = false;

				if (mat[to[0]][to[1]] == 4) {
					purple = true;
					while (mat[to[0]][to[1]] == 4) {
						to[0] += dx4[k];
						to[1] += dy4[k];
						++step;
					}
					to[2] = 0;
				}

				if ((mat[to[0]][to[1]] == 0 || (mat[to[0]][to[1]] == 3 && to[2] == 0)) && purple) {
					to[0] -= dx4[k];
					to[1] -= dy4[k];
					--step;
					if (best[to[2]][to[0]][to[1]] > step + best[now[2]][now[0]][now[1]]) {
						que.push(to);
						best[to[2]][to[0]][to[1]] = step + best[now[2]][now[0]][now[1]];
					}
				}

				if (mat[to[0]][to[1]] == 1) {
					if (best[to[2]][to[0]][to[1]] > step + best[now[2]][now[0]][now[1]]) {
						que.push(to);
						best[to[2]][to[0]][to[1]] = step + best[now[2]][now[0]][now[1]];
					}
				}

				if (mat[to[0]][to[1]] == 2) {
					to[2] = 1;
					if (best[to[2]][to[0]][to[1]] > step + best[now[2]][now[0]][now[1]]) {
						que.push(to);
						best[to[2]][to[0]][to[1]] = step + best[now[2]][now[0]][now[1]];
					}
				}

				if (mat[to[0]][to[1]] == 3 && to[2] == 1) {
					if (best[to[2]][to[0]][to[1]] > step + best[now[2]][now[0]][now[1]]) {
						que.push(to);
						best[to[2]][to[0]][to[1]] = step + best[now[2]][now[0]][now[1]];
					}
				}
			}
		}
	}

	int ans = min(best[0][N][M], best[1][N][M]);
	if (ans == MOD1) {
		ans = -1;
	}
	cout << ans << '\n';

	return 0;
}


