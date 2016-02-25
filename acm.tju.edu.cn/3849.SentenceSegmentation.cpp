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

int N, lgS;
char S[20005];

struct TrieNode {
	int val;
	bool endhere;
};

#define COEFF 20

void Solve() {
	int i, lgw, root, pos, val, last_node = 1;
	char word[102];
	vector <int> dp;
	vector <pair <string, int> > words;
	vector <TrieNode> trienodes;
	vector <vector <int> > trie;
	
	trie.resize(N * COEFF, vector <int> (26));
	trienodes.resize(N * COEFF);
	for (i = 0; i < N; ++i) {
			//		cin >> word >> val;
		scanf("%s %d", word, &val);
		
		lgw = (int) strlen(word);
		root = 0;
		pos = 0;
		while (pos < lgw) {
			int to = word[pos] - 'a';
			if (trie[root][to] == 0) {
				trie[root][to] = last_node;
				trienodes[last_node].val = 0;
				trienodes[last_node].endhere = false;
				last_node++;
			}
			root = trie[root][to];
			++pos;
		}
		trienodes[root].val = max(trienodes[root].val, val);
		trienodes[root].endhere = true;
	}
	
	cin >> (S + 1);
	if (N == 0) {
		WriteNo(-1, '\n');
		return;
	}
	lgS = (int) strlen(S + 1);
	dp.resize(lgS + 1, -1);
	dp[0] = 0;
	for (i = 1; i <= lgS; ++i) {
		if (i == 1 || dp[i - 1] != -1) {
			for (root = 0, pos = i; pos < i + 100 && pos <= lgS; ++pos) {
				int to = S[pos] - 'a';
				if (trie[root][to] != 0) {
					root = trie[root][to];
					if (trienodes[root].endhere) {
						dp[pos] = max(dp[i - 1] + trienodes[root].val, dp[pos]);
					}
				}
				else {
					break;
				}
			}
		}
	}
	if (dp[lgS] > 0) {
		WriteNo(dp[lgS],'\n');
	}
	else {
		WriteNo(-1, '\n');
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
		//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "r", stdin);
#endif
#endif
	
	int i, t;
	cin >> N;
	while (!cin.eof())
	{
		Solve();
		cin >> N;
	}
	
	return 0;
}
