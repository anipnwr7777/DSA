#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename t>
void __print(vector<t> v)
{
	cerr << endl;
	for (t x : v) {__print(x); cerr << " ";}
	cerr << endl;
}

template<typename T, typename V>
void __print(const pair<T, V> &x)
{
	cerr << '{';
	__print(x.first);
	cerr << ',';
	__print(x.second);
	cerr << '}';
}

template<typename T>
void __print(const T &x)
{
	int f = 0;
	cerr << '{';
	for (auto &i : x)
		cerr << (f++ ? "," : ""), __print(i);
	cerr << "}";
}
void _print()
{
	cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v)
{
	__print(t);
	if (sizeof...(v))
		cerr << ", ";
	_print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//----------------------------------------------------------------------------------------------

vector<int> row = { -2, -2, -1, -1, 1, 1, 2, 2}; // moves
vector<int> column = {1, -1, 2, -2, 2, -2, 1, -1};
vector<vector<bool>> visited(8, vector<bool> (8, 0)); // (i,j) is visited or not
vector<vector<int>> level(8, vector<int> (8, 0)); // level of (i,j)
int srcx, srcy, desx, desy;

void precomputation()
{
	//no precomputation
}

bool isvlalid(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	else
		return false;
}

int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	level[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == desx && y == desy) {
			return level[x][y];
		}
		q.pop();
		for (int i = 0 ; i < 8 ; i++) {
			int newx = x + row[i];
			int newy = y + column[i];

			if (isvlalid(newx, newy)) {
				if (!visited[newx][newy]) {
					q.push({newx, newy});
					level[newx][newy] = level[x][y] + 1;
					visited[newx][newy] = true;
				}
			}
		}
	}
}

/*
	shortest path is asked --> think about bfs, question may get solved

	there is only one difference this code has with the normal bfs i.e. in normal bfs the
	adjacent nodes were known from the adj list, here nodes are not known in that way.
	we have to calculate them with the types of moves of knight that are possible from a given
	(i,j). you are creating your adj list here in real time, that is the only difference this question
	has. It is the major intuition of this question.
*/

void solve()
{
	cin >> srcx >> srcy >> desx >> desy;
	cout << bfs(srcx, srcy) << endl;
}

//------------------------------------------------------------------------------------------------

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	precomputation();

	solve();

	return 0;
}