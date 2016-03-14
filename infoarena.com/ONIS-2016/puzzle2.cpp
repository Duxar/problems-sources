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

int N, M;
vector <vector <int> > graph, mat;
vector <int> degree;
vector <bool> visited;

int HasVisited(int iam) {
	int cnt = 0;
	for (auto to: graph[iam]) {
		if (visited[to]) {
			++cnt;
		}
	}
	return cnt;
}

int main(){
	string fileInput = "puzzle2";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
		//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

	int i, j, x, y, st;

	GetNr(N); GetNr(M);
	graph.resize(1 + N);
	degree.resize(1 + N);
	visited.resize(1 + N);

	for (i = 0; i < M; ++i) {
		GetNr(x); GetNr(y);
		graph[x].pb(y);
		graph[y].pb(x);

		++degree[x];
		++degree[y];
	}

	st = 1;
	for (i = 2; i <= N; ++i) {
		if (degree[i] < degree[st]) {
			st = i;
		}
	}

	if (degree[st] == 1) {
		PutNr(1); PutNr(N, '\n');
		bool move = true;
		while (move) {
			move = false;
			visited[st] = 1;
			PutNr(st);
			for (auto to: graph[st]) {
				if (visited[to] == 0) {
					st = to;
					move = true;
					break;
				}
			}
		}
		ENTER
		return 0;
	}

	vector <int> line;
	int twoline = false;

	for (auto to: graph[st]) {
		if (degree[to] == 2) {
			twoline = true;
			break;
		}
	}

	if (twoline) {
		line.pb(st);
		visited[st] = 1;
		for (auto to: graph[st]) {
			if (degree[to] == 2) {
				visited[to] = 1;
				line.pb(to);
				break;
			}
		}


		queue <int> que;

		for (auto to: graph[st]) {
			if (!visited[to]) {
				que.push(to);
				break;
			}
		}

		while (que.size()) {
			mat.pb(line);
			line.clear();
			st = que.front();
			que.pop();
			line.pb(st);
			visited[st] = 1;
			for (auto to: graph[st]) {
				if (!visited[to] && 2 == HasVisited(to)) {
					line.pb(to);
					visited[to] = 1;
					break;
				}
			}
			for (auto to: graph[st]) {
				if (!visited[to]) {
					que.push(to);
					break;
				}
			}
		}
		mat.pb(line);

		PutNr(mat.size()); PutNr(mat[0].size(), '\n');
		for (i = 0; i < mat.size(); ++i) {
			for (j = 0; j < mat[i].size(); ++j) {
				PutNr(mat[i][j]);
			}
			ENTER
		}
	}
	else {
		while (!visited[st]) {
			line.pb(st);
			visited[st] = 1;
			for (auto to: graph[st]) {
				if (!visited[to] && degree[to] == 3) {
					st = to;
					break;
				}
			}
		}

		for (auto to: graph[st]) {
			if (!visited[to] && degree[to] == 2) {
				line.pb(to);
				st = to;
				visited[st] = 1;
				break;
			}
		}

		for (auto to: graph[st]) {
			if (!visited[to]) {
				st = to;
				break;
			}
		}

		while (!visited[st]) {
			mat.pb(line);
			line.clear();

			line.pb(st);
			visited[st] = 1;

			while (1) {
				for (auto to: graph[st]) {
					if (!visited[to] && 2 == HasVisited(to)) {
						st = to;
					}
				}
				if (visited[st]) {
					break;
				}
				visited[st] = 1;
				line.pb(st);
			}

			for (auto to: graph[st]) {
				if (!visited[to]) {
					st = to;
					break;
				}
			}
		}

		mat.pb(line);
		PutNr(mat.size()); PutNr(mat[0].size(), '\n');
		for (i = 0; i < mat.size(); ++i) {
			if (i % 2 == 0) {
				for (j = 0; j < mat[i].size(); ++j) {
					PutNr(mat[i][j]);
				}
			}
			else {
				for (j = mat[i].size() - 1; j >= 0; --j) {
					PutNr(mat[i][j]);
				}
			}
			ENTER
		}
	}
	return 0;
}


