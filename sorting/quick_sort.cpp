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

int partition(int arr[], int low, int high){

	int key = arr[high];
	int index = low;

	/*
		keep swaping elements that are smaller than and equal to pivot to get them to the left side of the pivot.
		Automatically greater elements are pushed to the right.
	*/
	for(int i=low ; i<=high ; i++){
		if(arr[i] <= key){
			swap(arr[i],arr[index]);
			index++;
		}
	}

	// decrement and then return because last increment was useless.
	// we want to send the index of pivot not the index at which next smaller element needs to be swaped.
	return --index;
}

void quick_sort(int arr[], int low, int high){

	// take care of the base case, don't use (low == high), extra case need to be 
	// considered using (low >= high).
	if(low >= high){   
		return;
	}

	/*
		partition and find the index of pivot element and then call quick_sort() for left and
		right subarray using leap of faith.

		it is faster than merge sort when implemented properly but it is not stable as merge sort is.
	*/

	

	int index = partition(arr,low,high);

	quick_sort(arr, low, index-1);
	quick_sort(arr, index+1, high);

}

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
	}

	quick_sort(arr, 0, n-1);

	for(auto x:arr){
		cout << x << " ";
	}
	cout << endl;

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