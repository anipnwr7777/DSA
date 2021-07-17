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

void merge(int arr[], int aux_arr[], int low, int mid, int high) {

	/*
		k --> for iterating on aux_arr from low to high
		i --> for iterating on arr from low to mid 
		j --> for iterating on arr from mid+1 to high

		logic --> first merge simultaneously both of them checking at each step which is smaller

				  as soon as one of them is exhausted just copy the remaining one at the end as 
				  it is already sorted and won't harm the order.

	*/

	int k = low, i = low, j = mid + 1;

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			aux_arr[k] = arr[i];
			k++, i++;
		}
		else {
			aux_arr[k] = arr[j];
			k++, j++;
		}
	}

	while(i<=mid){
		aux_arr[k] = arr[i];
		k++, i++;
	}

	while(j<=high){
		aux_arr[k] = arr[j];
		k++, j++;
	}

	// just update the arr with the sorted aux_arr.

	for(int i=low ; i<=high ; i++){
		arr[i] = aux_arr[i];
	}
}

void merge_sort(int arr[], int aux_arr[], int low, int high) {

	if (low == high)
		return;  // if the array is only of one element then stop dividing further.

	int mid = (low + high) / 2;

	/*
		merge_sort() --> returns sorted array
		takes an array, recursively divides it into two halves and calls the merge()
		to join two halves that are already sorted
		imp --> for an array of two elements two halves will contain one one element each,
			so they are already sorted. (this gives an intution how things are working)

		merge() --> merges two halves to make the bigger arrray as sorted

		merge_sort() uses merge() to function correctly.
	*/

	merge_sort(arr, aux_arr, low, mid);		// first half received sorted
	merge_sort(arr, aux_arr, mid + 1, high);	// second half received sorted

	merge(arr, aux_arr, low, mid, high);    // call the merge function to join them in a sorted way

	// finally the entire array is sorted. return to main



}


void solve()
{
	int n;
	cin >> n;
	int arr[n];
	int aux_arr[n];

	// auxillary array is used as extra space to help sort the given arr. final answer
	// is stored in arr.

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
		aux_arr[i] = arr[i];
	}

	merge_sort(arr, aux_arr, 0, n - 1);
	for (auto x : arr) {
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