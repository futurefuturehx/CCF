#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int list[1000];
	int n,i;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> list[i];
	}
	sort(list,list+n);
	int mid = list[n/2];
	int lb = lower_bound(list,list+n,mid)-list;
	int ub = upper_bound(list,list+n,mid)-list;
	if (n-ub == lb)
		cout << mid << endl;
	else
		cout << "-1";
	return 0;
}
