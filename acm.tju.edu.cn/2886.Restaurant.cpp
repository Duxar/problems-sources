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

long long N, M, ans;


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

	int i;
	while (cin >> N >> M) {
		ans = 0;
		vector <pair <long long, int> > points;
		long long add_left = 0, add_right = 0, cost_right = 0, cost_left = 0;

		points.resize(N);
		for (i = 0; i < N; ++i) {
			ReadNo(points[i].first);
			ReadNo(points[i].second);
		}
		sort(ALL(points));

		add_right = points[N - 1].second;
		for (i = N - 2; i >= 0; --i) {
			cost_right += (points[i + 1].first - points[i].first) * add_right;
			add_right += points[i].second;
		}
		if (M > cost_right) {
			ans += min (points[0].first - (-1000000000L), (M - cost_right) / add_right);
		}
		for (i = 0; i < N - 1; ++i) {
			if (M >= cost_right + cost_left) {
				++ans;
			}
			add_left += points[i].second;
			add_right -= points[i].second;

			long long lg = points[i + 1].first - points[i].first - 1;
			long long p;
			for (p = 1; p <= lg; p *= 2);

			if (M >= cost_left + cost_right) {
				long long poz = points[i].first;
				while (p) {
					long long aux = poz + p;
					if (aux < points[i + 1].first) {
						long long dist2 = (aux - points[i].first);
						if (M >=  dist2 * add_left + cost_left + cost_right - dist2 * add_right) {
							poz += p;
						}
					}
					p >>= 1;
				}
				ans += poz - points[i].first;
			}
			else {
				long long poz = points[i].first;
				while (p) {
					long long aux = poz + p;
					if (aux < points[i + 1].first) {
						long long dist2 = (aux - points[i].first);
						if (M <  dist2 * add_left + cost_left + cost_right - dist2 * add_right) {
							poz += p;
						}
					}
					p >>= 1;
				}
				ans += points[i + 1].first - poz - 1;
			}
			cost_left += add_left * (points[i + 1].first - points[i].first);
			cost_right -= add_right * (points[i + 1].first - points[i].first);
		}
		add_left += points[N - 1].second;
		if (M >= cost_left) {
			ans += 1 + min(1000000000L - points[N - 1].first, (M - cost_left) / add_left);
		}

		cout << ans << '\n';
	}

	return 0;
}


