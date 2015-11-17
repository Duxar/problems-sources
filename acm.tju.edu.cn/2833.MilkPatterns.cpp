	// http://acm.tju.edu.cn/toj/showp2833.html - ACCEPTED

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
#define BASE 1000003
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

int N, K;
vector<int> values;

bool i_can(int lg) {
	map <int, int> hasht;
	long long hash_value, base_rised = 1;
	int i;
	hash_value = values[0];

	for (i = 1; i < lg; ++i) {
		hash_value = hash_value * BASE + values[i];
		hash_value %= MOD1;
		base_rised *= BASE;
		base_rised %= MOD1;
	}
	hasht[hash_value]++;
	for (i = lg; i < N; ++i) {
		hash_value = ((hash_value + MOD1 - (base_rised * values[i - lg]) % MOD1) * BASE + values[i]) % MOD1;
		hasht[hash_value]++;
	}

	map <int, int> :: iterator it;
	for (it = hasht.begin(); it != hasht.end(); ++it) {
		if (it->second >= K) {
			return true;
		}
	}
	return false;
}

int main(){
		//	string fileInput = "sum";
		//#ifdef INFOARENA
		//	freopen((fileInput + ".in").c_str(), "r", stdin);
		//	freopen((fileInput + ".out").c_str(), "w", stdout);
		//#else
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
		//#endif

	int i, pw, ans = 1, aux;

	ReadNo(N); ReadNo(K);
	values.resize(N);

	for (i = 0; i < N; ++i) {
		ReadNo(values[i]);
	}

	for (pw = 1; pw <= N; pw <<= 1);

	for (; pw; pw >>= 1) {
		aux = ans + pw;
		if (aux <= N) {
			if (i_can(aux)) {
				ans = aux;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}


