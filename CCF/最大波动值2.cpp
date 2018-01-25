#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int compare(int a ,int b){
	return a>b;
}
int main(){
	vector<int> list;
	int n,temp;
	int cha;
	int save[1000];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		list.push_back(temp);
	}
	for(int i=0;i<n-1;i++){
		cha = abs(list[i]-list[i+1]);
		save[i] = cha;
	}
	sort(save,save+n-2,compare);
	cout << save[0];
}
//sort()
