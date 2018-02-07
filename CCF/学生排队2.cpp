#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int i,temp,s;
	int p,q;
	vector<int> list;
	cin >> n;
	cin >> m;
	for(i=0;i<n;i++){
		list.push_back(i+1);
	}
	for(i=0;i<m;i++){
		cin >> p >> q;
		for(int j=0;j<n;j++){
			if(list[j]==p){
				temp = j;
				break;
			}
		}
		if(q>=0){
			for(int j=temp;j<temp+q;j++){
				s=list[j];
				list[j]=list[j+1];
				list[j+1]=s;
			}
		}
		else{
			for(int j=temp;j>temp+q;j--){
				s=list[j];
				list[j]=list[j-1];
				list[j-1]=s;
			}
		}
	}
	for(i=0;i<n;i++)
		cout << list[i] << " ";
		return 0;
}
//冒泡排序的变形
