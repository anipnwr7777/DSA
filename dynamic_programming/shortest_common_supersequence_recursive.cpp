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

vector<vector<int>> states; // to store the dp states

int shortest_common_supersequence(string first, string second, int fl, int sl){

	// base case: return lenght that is non-zero when other one is zero. length = index + 1
	if(fl < 0 || sl < 0)
		return max(fl,sl)+1;

	/*
		for optimal substructure consider two cases

		1. last element of the two strings are same

		2. not same

		read the substructure property in the article in the google doc, it is well explained there.
	*/

	if(states[fl][sl] != -1)
		return states[fl][sl];

	if(first[fl] == second[sl]){
		return states[fl][sl] = shortest_common_supersequence(first, second, fl-1, sl-1) + 1;
	}
	else{
		return states[fl][sl] = 1 + min(shortest_common_supersequence(first, second, fl-1, sl), shortest_common_supersequence(first, second, fl, sl-1));
	}
}

void solve()
{
    string first,second;
    cin >> first >> second;

    int first_length = first.size(), second_length = second.size();

    states.resize(first_length);
    for(int i=0 ; i<first_length ; i++)
    	states[i].resize(second_length, -1);

    shortest_common_supersequence(first, second, first_length-1, second_length-1);

    cout << states[first_length-1][second_length-1] << endl;
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

