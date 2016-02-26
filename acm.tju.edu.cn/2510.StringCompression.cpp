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
#define PRIME 1493
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

int lgword;
char word[205];
vector <ULL> hashword, pwer;
vector <vector <int> > dpcompress;

int GetChars(int x) {
	int ans = 0;
	do {
		++ans;
		x /= 10;
	} while (x);
	return ans;
}

ULL GetHashSegment(int st, int en) {
	int lg = en - st + 1;
	ULL hashseg = hashword[en] - hashword[st - 1] * pwer[lg];
	return hashseg;
}

void Compress(int pos, int lgseg) {
	ULL hashseg = GetHashSegment(pos, pos + lgseg - 1);
	int cnt = 1, i;
	for (i = pos + lgseg; i + lgseg - 1 <= lgword; i += lgseg) {
		if (hashseg == GetHashSegment(i, i + lgseg - 1)) {
			++cnt;
			dpcompress[pos][i + lgseg - 1] = min(dpcompress[pos][i + lgseg - 1], dpcompress[pos][pos + lgseg - 1] + 2 + GetChars(cnt));
		}
		else {
			break;
		}
	}
}

void GetBest(int st, int en) {
	int i;
	dpcompress[st][en] = min(dpcompress[st][en], en - st + 1);
	for (i = st; i < en; ++i) {
		dpcompress[st][en] = min(dpcompress[st][en], dpcompress[st][i] + dpcompress[i + 1][en]);
	}
}

void Solve() {
	int i, k;
	scanf("%s", word + 1);
	lgword = (int) strlen(word + 1);
	
	hashword.clear();
	hashword.resize(1 + lgword);
	pwer.clear();
	pwer.resize(1 + lgword);
	dpcompress.clear();
	dpcompress.resize(1 + lgword, vector <int> (1 + lgword, MOD1));
	
	pwer[0] = 1;
	for (i = 1; i <= lgword; ++i) {
		hashword[i] = hashword[i - 1] * BASE + (word[i] - 'a');
		pwer[i] = pwer[i - 1] * BASE;
	}
	
	for (k = 1; k <= lgword; ++k) {
		for (i = 1; i <= lgword; ++i) {
			if (i + k - 1 <= lgword) {
				GetBest(i, i + k - 1);
				Compress(i, k);
			}
			else {
				break;
			}
		}
	}
	WriteNo(dpcompress[1][lgword], '\n');
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
	
	int i, T;
	ReadNo(T);
	for (i = 0; i < T; ++i) {
		Solve();
	}
	
	
	return 0;
}


