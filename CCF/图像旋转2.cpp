#include <iostream>
using namespace std;
int main(){
	short a[1000][1000];
	int n,m,i,j;
	cin >> n >> m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout << a[j][m-i-1] << " ";
		}
		cout << endl;
	}
	return 0;
}
