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
		ch == '-' ? _sign = -1 : _sign = 1 ;
	}
	do {
		_value = _value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	_value *= _sign;
}

template <class T>
void WriteNo(T _value, char _ch = ' ') {
	cout << _value << _ch;
}

#define DEPTH 17

int N, K, val_order, Q;
vector <vector <int> > parent, graph;
vector <int> level, order, ans_node;
vector <pair <int, int> > weight;

int get_lca(int x, int y) {
	int i, par, par1, par2;
	
	if (level[x] < level[y]) {
		swap(x, y);
	}
	
	for (i = DEPTH - 1; i >= 0 && level[x] > level[y]; --i) {
		par = parent[i][x];
		if (level[par] >= level[y]) {
			x = par;
		}
	}
	
	if (x == y) {
		return x;
	}
	
	for (i = DEPTH - 1; i >= 0; --i) {
		par1 = parent[i][x];
		par2 = parent[i][y];
		if (par1 != par2) {
			x = par1;
			y = par2;
		}
	}
	
	if (x > 1) {
		return parent[0][x];
	}
	return 1;
}

void get_order(int iam, int from) {
	order[iam] = ++val_order;
	int i;
	
	parent[0][iam] = from;
	for (int d = 1; d < DEPTH; ++d) {
		int p = parent[d - 1][iam];
		if (p == 0) {
			break;
		}
		parent[d][iam] = parent[d - 1][p];
	}
	
	for (i = 0; i < graph[iam].size(); ++i) {
		if (from != graph[iam][i]) {
			level[graph[iam][i]] = level[iam] + 1;
			get_order(graph[iam][i], iam);
		}
	}
}

bool by_order(pair <int, int> a, pair <int, int> b) {
	if (a.fi == b.fi) {
		return order[a.se] < order[b.se];
	}
	return a.fi < b.fi;
}

void compute_ans(int iam, int from) {
	int i;
	for (i = 0; i < graph[iam].size(); ++i) {
		if (from != graph[iam][i]) {
			compute_ans(graph[iam][i], iam);
			ans_node[iam] += ans_node[graph[iam][i]];
		}
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
#endif
#endif
	
	int ww, T, i, x, y, j, q;
	
	ReadNo(T);
	for (ww = 1; ww <= T; ++ww) {
		if (ww > 1) {
			ENTER
		}
		printf("Case #%d:\n", ww);
		
		graph.clear();
		level.clear();
		parent.clear();
		ans_node.clear();
		weight.clear();
		order.clear();
		
		ReadNo(N); ReadNo(K);
		graph.resize(N + 1);
		weight.resize(N + 1);
		order.resize(N + 1, 0);
		level.resize(N + 1, 0);
		ans_node.resize(N + 1, 0);
		parent.resize(DEPTH, vector<int> (N + 1, 0));
		val_order = 0;
		
		for (i = 1; i <= N; ++i) {
			ReadNo(weight[i].fi);
			weight[i].se = i;
		}
		for (i = 1; i < N; ++i) {
			ReadNo(x); ReadNo(y);
			graph[x].pb(y);
			graph[y].pb(x);
		}
		get_order(1, 0);
		
		
		sort(ALL(weight), by_order);
		
		for (i = 1; i <= N; ++i) {
			int k = K;
			for (j = i; j <= N && k; ++j) {
				if (weight[j].fi == weight[i].first) {
					--k;
				}
				else {
					break;
				}
			}
			if (k > 0) {
				continue;
			}
			--j;
			
			int p1 = -1, p2 = -1, p3 = -1, pos1;
			for (pos1 = i; weight[j].fi == weight[i].fi && j <= N; ++j, ++pos1) {
				p1 = get_lca(weight[pos1].se, weight[j].se);
				if (pos1 > 1 && weight[pos1 - 1].fi == weight[pos1].fi) {
					p2 = get_lca(weight[pos1 - 1].se, p1);
					if (level[p2] == level[p1]) {
						continue;
					}
				}
				if (j < N && weight[j + 1].fi == weight[j].fi) {
					p3 = get_lca(weight[j + 1].se, p1);
					if (level[p3] == level[p1]) {
						continue;
					}
				}
				++ans_node[p1];
				if (p2 == -1 && p3 == -1) {
					continue;
				}
				if (p2 != -1 && p3 != -1) {
					if (level[p2] < level[p3]) {
						swap(p2, p3);
					}
				}
				if (p2 == -1) {
					swap(p2, p3);
				}
				--ans_node[p2];
			}
			i = j - 1;
		}
		
		compute_ans(1, 0);
		
		ReadNo(Q);
		for (i = 0; i < Q; ++i) {
			ReadNo(q);
			WriteNo(ans_node[q], '\n');
		}
	}
	
	return 0;
}


