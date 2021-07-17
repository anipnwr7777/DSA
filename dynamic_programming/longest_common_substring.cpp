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



void precomputation()
{
	//no precomputation
}

void solve()
{

	string s, t;
	cin >> s >> t;
	int sl = s.size();
	int tl = t.size();

	vector<vector<int>> lookup(sl + 1, vector<int> (tl + 1, 0));

	int maxlen = -1, endindex = sl;


	/*
		lookup[i][j] --> stores the length of longest common substring ending at (i,j).

		if at any index the value of corresponding two elements are equal then the length of lcs ending at this point is
		equal to the (length of lcs at (i-1,j-1)) + 1.
	*/

	for (int i = 1 ; i <= sl ; i++) {
		for (int j = 1 ; j <= tl ; j++) {

			if (s[i - 1] == t[j - 1]) {
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

				// update the maxlength and also update the endindex of lcs in string s.

				if (lookup[i][j] > maxlen) {
					maxlen = lookup[i][j];
					endindex = i;
				}
			}

		}
	}


	// finallly calculate the lcs using the substr function of string from the string s using the lenght of lcs and
	// the end index of lcs
	
	string ans = s.substr(endindex - maxlen, maxlen);
	cout << ans << endl;

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