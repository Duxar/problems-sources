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

int N, M, K;

vector <vector <int> > mat, position;
vector <vector <pair <int, int> > > colors;
vector <int> root, weight;
vector <bool> iszero;

int GetRoot(int x, stack <pair <int, int> > *prev_roots = 0) {
	if (x != root[x]) {
		if (prev_roots != 0) {
			prev_roots->push(mp(x, root[x]));
		}
		x = root[x] = GetRoot(root[x], prev_roots);
	}
	return x;
}

void MakeUnion(int x, int y, stack <pair <int, int> > *prev_roots = 0, stack <pair <int, int> > *prev_weights = 0) {
	x = GetRoot(x, prev_roots);
	y = GetRoot(y, prev_roots);
	if (x != y) {
		if (weight[x] < weight[y]) {
			swap(x, y);
		}
		if (prev_roots != 0) {
			prev_roots->push(mp(y, root[y]));
			prev_weights->push(mp(x, weight[x]));
		}
		root[y] = x;
		weight[x] += weight[y];
	}
}

void Solve() {
	GetNr(N); GetNr(M); GetNr(K);

	mat.clear(); position.clear(); root.clear(); weight.clear(); iszero.clear(); colors.clear();

	mat.resize(N, vector <int> (M));
	position.resize(N, vector <int> (M));
	root.resize(N * M);
	weight.resize(N * M, 1);
	iszero.resize(N * M, 0);
	colors.resize(1 + K);

	int i, j, pos;

	for (i = 0, pos = 0; i < N; ++i) {
		for (j = 0; j < M; ++j, ++pos) {
			GetNr(mat[i][j]);
			position[i][j] = pos;
			root[pos] = pos;

			if (mat[i][j] == 0) {
				iszero[pos] = 1;
				if (i > 0 && mat[i - 1][j] == 0) {
					MakeUnion(position[i][j], position[i - 1][j]);
				}
				if (j > 0 && mat[i][j - 1] == 0) {
					MakeUnion(position[i][j], position[i][j - 1]);
				}
			}
			else {
				colors[mat[i][j]].pb(mp(i, j));
			}
		}
	}

	vector <int> zero_roots;

	for (i = 0; i < N * M; ++i) {
		root[i] = GetRoot(i);
		if (root[i] == i && iszero[i]) {
			zero_roots.pb(i);
		}
	}

	if (zero_roots.size() == 1) {
		PutNr(K, '\n');
		return;
	}

	int x, y, k, p1, p2, final_ans = 0, w, r;
	stack <pair <int, int> > prev_weights, prev_roots;

	for (k = 1; k <= K; ++k) {
		if (colors[k].size()) {
			for (auto pos: colors[k]) {
				tie(i, j) = pos;
				p1 = position[i][j];
				for (int w = 0; w < 4; ++w) {
					x = i + dx4[w];
					y = j + dy4[w];
					if (0 <= x && x < N && 0 <= y && y < M && (mat[x][y] == 0 || mat[x][y] == k)) {
						p2 = position[x][y];
						MakeUnion(p1, p2, &prev_roots, &prev_weights);
					}
				}
			}
			int cnt = 0, good_r;
			good_r = root[zero_roots[0]] = GetRoot(zero_roots[0], &prev_roots);
			for (auto pos: zero_roots) {
				root[pos] = GetRoot(pos, &prev_roots);
				if (root[pos] != good_r) {
					++cnt;
					if (cnt == 2) {
						break;
					}
				}
			}
			if (cnt == 0) {
				++final_ans;
			}

			while (prev_weights.size()) {
				tie (x, w) = prev_weights.top();
				weight[x] = w;
				prev_weights.pop();
			}

			while (prev_roots.size()) {
				tie (x, r) = prev_roots.top();
				root[x] = r;
				prev_roots.pop();
			}
		}
 	}
	PutNr(final_ans, '\n');
}



int main(){
	string fileInput = "unlock";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
		//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

	int i, T;

	GetNr(T);
	while (T--) {
		Solve();
	}

	return 0;
}


