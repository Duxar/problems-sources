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

struct Event {
	int flight, where;
 	LL cost, timee;
	bool type;
};

struct Compare1 {
	bool operator()(Event a, Event b) {
		if (a.timee == b.timee) {
			return (int) a.type < (int) b.type;
		}
		return a.timee > b.timee;
	}
};

struct Query {
	int node, pos;
	LL timee;
};

int N, M, K;
priority_queue<Event, vector <Event>, Compare1> heap;
vector <Event> arrival;
vector <LL> besthere, ans;
vector <Query> queries;

int main(){
	string fileInput = "avioane2";
#ifdef INFOARENA
	freopen((fileInput + ".in").c_str(), "r", stdin);
	freopen((fileInput + ".out").c_str(), "w", stdout);
#else
#ifndef ONLINE_JUDGE
	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
		//	freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/result", "w", stdout);
#endif
#endif

	int i, from, timefrom, to, timeto, price;

	GetNr(N); GetNr(M); GetNr(K);
	besthere.resize(1 + N, -1);
	arrival.resize(1 + M);
	queries.resize(K);
	ans.resize(K);

	Event depart, arrive, now;
	depart.type = 0;
	arrive.type = 1;
	besthere[1] = 0;

	for (i = 1; i <= M; ++i) {
		GetNr(from); GetNr(timefrom);
		depart.flight = arrive.flight = i;
		depart.where = from;
		depart.timee = timefrom;
		heap.push(depart);

		GetNr(to); GetNr(timeto); GetNr(price);
		arrive.where = to; arrive.timee = timeto;
		arrive.cost = price;
		arrival[i] = arrive;
	}

	for (i = 0; i < K; ++i) {
		GetNr(queries[i].node); GetNr(queries[i].timee);
		queries[i].pos = i;
	}

	sort(ALL(queries), [] (Query a, Query b) -> bool {
		return a.timee < b.timee;
	});
	i = 0;

	while (i < K) {
		if (heap.size() == 0 || queries[i].timee < heap.top().timee) {
			ans[queries[i].pos] = besthere[queries[i].node];
			++i;
		}
		else {
			if (heap.size()) {
				now = heap.top();
				heap.pop();

				LL x = now.where, cost = now.cost;
				if (now.type) {
					if (besthere[x] == -1 || besthere[x] > cost) {
						besthere[x] = cost;
					}
				}
				else {
					if (besthere[x] != -1) {
						arrive = arrival[now.flight];
						arrive.cost += besthere[x];
						heap.push(arrive);
					}
				}
			}
		}
	}

	for (i = 0; i < K; ++i) {
		PutNr(ans[i], '\n');
	}



	return 0;
}


