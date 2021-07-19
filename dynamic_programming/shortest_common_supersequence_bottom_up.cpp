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


void solve()
{
	// see the recursive code for explanation.
	
    string first,second;
    cin >> first >> second;

    int first_length = first.size(), second_length = second.size();

    states.resize(first_length + 1);

    for(int i=0 ; i<=first_length ; i++)
    	states[i].resize(second_length + 1);

    for(int i=0 ; i<= first_length ; i++){
    	for(int j=0 ; j<= second_length ; j++){

    		if(i==0)
    			states[i][j] = j;
    		if(j==0)
    			states[i][j] = i;
    	}
    }

    for(int i=1 ; i<= first_length ; i++){
    	for(int j=1 ; j<= second_length ; j++){

    		if(first[i-1] == second[j-1]){
    			states[i][j] = states[i-1][j-1] + 1;
    		}
    		else{
    			states[i][j] = min(states[i-1][j] , states[i][j-1]) + 1;
    		}
    	}
    }

    cout << states[first_length][second_length] << endl;

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