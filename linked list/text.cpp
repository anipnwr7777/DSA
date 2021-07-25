#include<bits/stdc++.h>
using namespace std;

set<int*> stt;

int main() {
	int a = 2;
	int *ptr = NULL;
	int *ptr1 = &a;
	stt.insert(ptr);
	stt.insert(ptr1);
	for(auto x:stt){
		cout << x << endl;
	}
	return 0;
}