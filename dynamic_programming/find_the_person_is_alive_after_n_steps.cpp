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

map<string, float> dp;
# define N 3

void precomputation()
{
	//no precomputation
}

float P(int x, int y, int n) {

	if (n == 0)
		return 1.0;  // 0 zero steps left -- base case. prob = 1


	string unique_key = to_string(x) + to_string(y) + to_string(n);

	/*
		string is formed to identify all states uniquely.
		this is something that i discovered new. It can also be used in dp questions. be aware.
	*/

	if (dp.count(unique_key) != 0) {
		return dp[unique_key];
	}

	float ans = 0.0;

	/*

		I am trying to go to all the adj places that can be visited i.e. it is not outside the given
		matrix. 

		probability of being alive at x,y when n steps are left is probability of being alive at :
			(x-1,y) when n-1 steps are left
			.
			.
			.

		multiplied by 0.25 to reach to that value out of four possible vlaues adj to it.

		all the values of outside the matrix are ignored so their probability is automatically not
		counted. so in the end answer will only conatain probability of being inside.
	*/
	if ((x - 1) >= 0)
		ans += 0.25 * P(x - 1, y, n - 1);  


	if ((x + 1) <= (N - 1))
		ans += 0.25 * P(x + 1, y, n - 1);

	if ((y - 1) >= 0)
		ans += 0.25 * P(x, y - 1, n - 1);

	if ((y + 1) <= (N - 1))
		ans += 0.25 * P(x, y + 1, n - 1);

	return dp[unique_key] = ans;

}

void solve()
{
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;

	cout << P(x, y, n); // probability of being alive when I am at x,y and have n steps left.

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