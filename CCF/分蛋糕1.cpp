#include<iostream>
using namespace std;
int main()
{
  int n;
  int k;
  int temp;
  int total=0;
  int count;
  int v[1000];
  int *p=v;
  int fin;
  cin >> n;
  cin >> k;
  for(int i=0;i<n;i++){
    cin >> temp;
    v[i]=temp;
  }
  while(total<k){
  	 total+=*p++;
  	if(total>=k){
  		count++;
  		while(p--){
  			*p=0;
		  }
	  }
  }
  fin=n-count;
  cout << fin;
  return 0;
}
