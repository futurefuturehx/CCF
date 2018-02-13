//对应入出
//数组中的数组
#include <bits/stdc++.h>
using namespace std;
int a[20][5]={0}; 
int RestNum(int m){
	int b=0;
	for(int i=0;i<5;i++){
		b+=a[m][i];
	}
	return (5-b);
}
int main(){
	int n,p,e;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p;
		e=p;
		for(int c=0;c<20;c++){
			int q=0;
			q=RestNum(c);
			if(q>=p){
				for(int d=0;d<5;d++){
					if(a[c][d]==0&&e>0){
						a[c][d]=1;
						cout << c*5+d+1 << " ";
						e--;
					}
				}
				cout << endl;
				break;
			}
		}
		for(int f=0;f<20;f++){
			for(int g=0;g<5;g++){
				if (a[f][g]==0&&e>0){
					a[f][g]==1;
					cout << f*5+g+1 << " ";
					e--;
				}
			}
		}
	}
	return 0;
	
} 
