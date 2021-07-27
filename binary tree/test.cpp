#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<int,int> mpp;
	mpp[1] = 2;
	mpp[3] = 10;
	mpp[12] = 11;
	for(auto x:mpp)
		cout << x.second << " ";
	cout << endl;
    return 0;
}