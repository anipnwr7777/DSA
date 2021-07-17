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
	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int> (n,0));

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> pre(n, vector<int> (n,0)); // this is dp matrix used to stord prefix sum of the matrix

	pre[0][0] = matrix[0][0];



	// this part is used to initialize the leftmost column and topmost row.

	for(int i=1 ; i<n ; i++){
		pre[i][0] = pre[i-1][0] + matrix[i][0];
	}

	for(int i=1 ; i<n ; i++){
		pre[0][i] = pre[0][i-1] + matrix[0][i];
	}




	// this is to calculate the answer of pre for the entire matrix excluding the values calculated above.

	for(int i=1 ; i<n ; i++){
		for(int j=1 ; j<n ; j++){
			
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + matrix[i][j];

		}
	}

	

	// "enter the top left x,y for the matrix and the bottom right respectively" 
	int tx,ty,bx,by;
	cin >> tx >> ty >> bx >> by;

	cout << pre[bx][by] - pre[tx-1][by] - pre[bx][ty-1] + pre[tx-1][ty-1] << endl;

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