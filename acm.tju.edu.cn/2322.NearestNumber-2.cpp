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

int N;
vector <vector <int> > mat, dp;

void FindDP(int i, int j) {
	int x, y, p, q;
	for (p = -2; p <= 2; ++p) {
		for (q = -2; q <= 2; ++q) {
			x = i + p;
			y = j + p;
			if (0 <= x && x < N && 0 <= y && y < N) {
				dp[i][j] = max(dp[x][y] - abs(i - x) - abs(j - y), dp[i][j]);
			}
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
	//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

	int i, j, x, y, k, d, cntzero = 0;

	GetNr(N);
	mat.resize(N, vector <int> (N));
	dp.resize(N, vector<int> (N));

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			GetNr(mat[i][j]);
			cntzero += (mat[i][j] == 0);
		}
	}

	if (cntzero == N * N) {
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N - 1; ++j) {
				PutNr(0);
			}
			printf("%d", 0);
			ENTER
		}
		return 0;
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (mat[i][j] == 0) {
				FindDP(i, j);
				do {
					int cnt = 0, val = -1;

					for (x = i - dp[i][j], k = 0; x < i; ++x, ++k) {
						y = j - k;
						if (0 <= x && x < N && 0 <= y && y < N && mat[x][y] != 0) {
							++cnt;
							val = mat[x][y];
							if (cnt == 2) {
								break;
							}
						}

						if (k > 0){
							y = j + k;
							if (0 <= x && x < N && 0 <= y && y < N && mat[x][y] != 0) {
								++cnt;
								val = mat[x][y];
								if (cnt == 2) {
									break;
								}
							}
						}
					}

					if (cnt == 2) {
						if (j + 1 == N) {
							printf("%d", 0);
						}
						else {
							PutNr(0);
						}
						break;
					}

					for (x = i, k = dp[i][j]; x <= i + dp[i][j]; ++x, --k) {
						y = j - k;
						if (0 <= x && x < N && 0 <= y && y < N && mat[x][y] != 0) {
							++cnt;
							val = mat[x][y];
							if (cnt == 2) {
								break;
							}
						}

						if (k == 0) {
							break;
						}
						y = j + k;
						if (0 <= x && x < N && 0 <= y && y < N && mat[x][y] != 0) {
							++cnt;
							val = mat[x][y];
							if (cnt == 2) {
								break;
							}
						}
					}

					if (cnt == 2) {
						if (j + 1 == N) {
							printf("%d", 0);
						}
						else {
							PutNr(0);
						}
						break;
					}

					if (cnt == 1) {
						if (j + 1 == N) {
							printf("%d", val);
						}
						else {
							PutNr(val);
						}
						break;
					}

					++dp[i][j];
				} while (1);
			}
			else {
				if (j + 1 == N) {
					printf("%d", mat[i][j]);
				}
				else {
					PutNr(mat[i][j]);
				}
			}
		}
		ENTER
	}

	return 0;
}
